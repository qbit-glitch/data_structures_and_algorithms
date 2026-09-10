/** Predecessor and Successor in BST
 * Link: https://www.naukri.com/code360/problems/predecessor-and-successor-in-bst_893049
*/

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
 * Inorder Traversal in BST : 1,2,3,4,5,6,7,8,9,10,11,12,13
 * 
 * So Successor of 9 : 10
 *    Predecessor of 9 : 8
 */


class Solution {
    public:
    pair<int, int> predecessorSuccessor(TreeNode *root, int key)
    {
        int successor = -1;
        int predecessor = -1;
        TreeNode* temp = root;
        while(temp != nullptr) {
            if(key > temp->val) {
                predecessor = temp->val;
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }

        temp = root;
        while(temp != nullptr) {
            if(key >= temp->val) {
                temp = temp->right;
            }
            else {
                successor = temp->val;
                temp = temp->left;
            }
        }
        
        return {predecessor, successor};
    }

    TreeNode* inorderSuccessor(TreeNode* root, int key){
        TreeNode* successor = nullptr;
        while(root != NULL) {
            if(key > root->val){
                root = root->right;
            }
            else if(key < root->val){
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }

    TreeNode* inorderPredecessor(TreeNode* root, int key){
        TreeNode* predecessor = nullptr;
        while(root!=nullptr) {
            if(key >= root->val) {
                predecessor = root;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return predecessor;
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
    Solution sol;

    pair<int, int> ans = sol.predecessorSuccessor(root, key);
    cout << ans.first << " " << ans.second << endl;

    // TreeNode* successor = sol.inorderSuccessor(root, 9);
    // printBST(successor);

    // TreeNode* predecessor = sol.inorderPredecessor(root, 9);
    // printBST(predecessor);
}