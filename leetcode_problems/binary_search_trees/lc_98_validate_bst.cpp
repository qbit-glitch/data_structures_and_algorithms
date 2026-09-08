
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution{
    public:
    bool isValidBST(TreeNode* root){
        return isValidBSTRec(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTRec(TreeNode* root, long minVal, long maxVal){
        if(root == nullptr)
            return true;
        if(root->val >= maxVal || root->val <= minVal)  return false;
        return isValidBSTRec(root->left, minVal, root->val) && isValidBSTRec(root->right, root->val, maxVal);
    }
};


void printBST(TreeNode* root, const string &prefix="", bool isLeft=false){
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
    cout << sol.isValidBST(root) << endl;
}

