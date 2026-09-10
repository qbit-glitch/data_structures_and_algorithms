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
private: stack<TreeNode* > st;
public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }

    int next(){
        TreeNode* tmpNode = st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext() {
        if(!st.empty())
            return true;
        else
            return false;
    }

private:
    void pushAll(TreeNode* root){
        while(root != nullptr){
            st.push(root);
            root = root->left;
        }
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
    int key = 9;
    BSTIterator sol = BSTIterator(root);

    cout << sol.next() << endl;
    cout << sol.hasNext() << endl;

    cout << sol.next() << endl;
    cout << sol.hasNext() << endl;

    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    cout << sol.next() << endl;
    
    

}