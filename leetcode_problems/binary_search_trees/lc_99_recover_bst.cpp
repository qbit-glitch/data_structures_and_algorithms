/**
 * Leetcode-99: Recover BST
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

class Solution{
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

private:
    void inorder(TreeNode* root){
        if(root == nullptr) 
            return;
        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)){
            // If this is first violation, mark these two nodes as 
            // `first` and `second`
            if(first == NULL){
                first = prev;
                middle = root;
            }

            // If this is second violation, mark this node as last
            else
                last = root;
        }

        // Mark this node as previous
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root){
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
            swap(first->val, last->val);
        else if(first && middle)
            swap(first->val, middle->val);
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
    TreeNode* root = new TreeNode(11);
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
    root->right->left->right = new TreeNode(9);

    printBST(root);

    Solution sol;

    sol.recoverTree(root);
    printBST(root);
    

}