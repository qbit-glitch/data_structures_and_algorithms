#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


/**
 * Inorder : Elements of a BST in sorted order
 * Preorder : Root -> Left -> Right
 * inorder : Left -> Root -> Right
*/

class Solution {
    public:
    TreeNode* bstFromPreorder(vector<int> &preorder){
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

    TreeNode* build(vector<int> &preorder, int &i, int bound) {
        if(i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root -> left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};

void printBST(TreeNode* root, const string &prefix="", bool isLeft=false) {
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
    vector<int> preorder {8,5,1,7,10,12};

    Solution sol;
    TreeNode* newRoot = sol.bstFromPreorder(preorder);
    
    printBST(newRoot);
}