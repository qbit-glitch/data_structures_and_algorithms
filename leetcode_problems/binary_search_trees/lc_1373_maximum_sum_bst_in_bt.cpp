/**
 * Code360: Size of Largest BST Subtree in BT
 * Link : https://www.naukri.com/code360/problems/size-of-largest-bst-in-binary-tree_893103
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


/**
 * Brute Force: Run Validate BST for every node -> O(n) x O(n) => O(n^2)
 * Better Approach : 
 *  - Store maxNode, minNode and maxSize for each node and then do a postorder traversal
 */
class NodeValue{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize): minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
};

class Solution{
private :
    NodeValue largestBSTSubtreeHelper(TreeNode* root){
        // An empty tree is a BST of size 0
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree of current size
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right,
        // it is a BST
        if(left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), (left.maxSize + right.maxSize + 1));
        }

        // Otherwise return [-inf, inf] so that parent can't be a valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(TreeNode* root){
        return largestBSTSubtreeHelper(root).maxSize;
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