#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

void printBinaryTree(TreeNode* root, const string &prefix="", bool isLeft=false){
    if(root == nullptr)
        return;
    cout << prefix;
    cout << (isLeft ? "|-- " : "'-- ");
    cout << root->val << endl;

    string childPrefix = prefix + (isLeft ? "|  " : "   ");
    printBinaryTree(root->left, childPrefix, true);
    printBinaryTree(root->right, childPrefix, false);
}



/** Thought Process :
 * It is similar to the morris inorder traversal, the only thing is that we are not creating threads here, 
 * instead we are re-arranging the tree.
 * - First move the left sub-tree to the right part and make the pointer to the leftsubtree as nullptr
 * - and do it recursively.
 * Goes like this :
 *      - if left is null then anyhow move to the right subtree.
 *      - Travel to the rightmost part of the left-subtree
 *      - join the left-subtree root with the curr->left
 *      - join the left-subtree's rightmost element with right-subtree root
 *      - make the curr->left to nullptr
 *      - move the curr to the right-subtree now(i.e. curr = curr->left) and repeat the entire process again.
*/
class Solution{
    public:
    void flatten(TreeNode* root){
        if(root == nullptr) return;

        TreeNode* curr = root;
        while(curr != nullptr) {
            if(curr->left == nullptr) {
                curr = curr -> right;
            }
            else {
                TreeNode* leftTree = curr -> left;
                TreeNode* leftTreeRightMost = leftTree;
                
                while(leftTreeRightMost -> right != nullptr){
                    leftTreeRightMost = leftTreeRightMost -> right;
                }
                
                TreeNode* temp = curr -> right;
                curr->right = leftTree;
                leftTreeRightMost -> right = temp;
                
                curr->left = nullptr;
                curr = curr -> right;
                
            }
        }
    }
};



int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* temp = root;
    temp->left = new TreeNode(2);
    temp->right = new TreeNode(3);
    temp->left->left = new TreeNode(4);
    temp->left->right = new TreeNode(5);
    temp->left->right->right = new TreeNode(6);
    

    printBinaryTree(root);

    Solution sol;
    sol.flatten(root);

    printBinaryTree(root);
}