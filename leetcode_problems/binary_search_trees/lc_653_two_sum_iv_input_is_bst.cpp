/**
 * Leetcode-173: Binary Search Tree iterator
*/
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class BSTIterator{
    stack<TreeNode*> myStack;
    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext(){
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next(){
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse)    pushAll(tmpNode->right);
        else    pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode* node){
        for(; node!=NULL; ){
            myStack.push(node);
            if(reverse == true)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution{
public:
    bool findTarget(TreeNode* root, int k){
        if(root== nullptr)  return false;
        
        // next
        BSTIterator l(root, false);

        // for before
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j) {
            if(i + j == k)  return true;
            else if(i + j < k)  i = l.next();
            else j = r.next();
        }
        return false;
    }
};


void printBST(TreeNode* root, const string &prefix="", bool isLeft = false){
    if(root == nullptr)
        return;

    cout << prefix;
    cout << (isLeft ? "|-- " : "'-- ");
    cout << root->val << endl;

    string childPrefix = prefix + (isLeft ? "|  " : "   ");
    printBST(root->left, childPrefix, true);
    printBST(root->right, childPrefix, false);
}


int main(){
    TreeNode* root = new TreeNode(9);
    root->left = new TreeNode(8);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(7);

    root->left->left->left->left = new TreeNode(2);
    root->left->left->left->right = new TreeNode(4);

    root->left->left->right->left = new TreeNode(6);

    root->left->left->left->left->left = new TreeNode(1);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(13);
    root->right->left->right = new TreeNode(11);

    printBST(root);

    Solution sol;
    cout << sol.findTarget(root, 14) << endl;
    cout << sol.findTarget(root, 21) << endl;
    cout << sol.findTarget(root, 100) << endl;

}