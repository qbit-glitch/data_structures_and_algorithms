#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right){}
};

void printBinaryTree(TreeNode* root, const string &prefix="", bool isLeft = false){
    if(root == nullptr) return;  

    cout << prefix;
    cout << (isLeft ? "|-- " : "'-- ");
    cout << root->val << endl;

    string childPrefix = prefix + (isLeft ? "|  " : "   ");
    printBinaryTree(root->left, childPrefix, true);
    printBinaryTree(root->right, childPrefix, false);

}


class Solution{
    public:
    TreeNode* searchBST(TreeNode* root, int val){
        if(root == nullptr) 
            return nullptr;
        if(root->val == val)
            return root;
        else if(val < root->val) 
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    
    root->left->right->left = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    printBinaryTree(root);

    int val = 5;
    
    Solution sol;
    TreeNode* searchNumberRoot = sol.searchBST(root, val);
    printBinaryTree(searchNumberRoot);

}