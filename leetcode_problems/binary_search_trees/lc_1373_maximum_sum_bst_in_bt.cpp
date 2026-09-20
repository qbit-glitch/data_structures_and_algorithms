/**
 * Leetcode-1373: Maximum Sum BST in BT
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
 *  - Store maxNode, minNode and maxSum for each node and then do a postorder traversal
 */
class NodeValue{
public:
    int maxNode, minNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum): minNode(minNode), maxNode(maxNode), maxSum(maxSum) {}
};

class Solution{
private :
    int ans = 0;
    NodeValue maxSumBSTHelper(TreeNode* root){
        // An empty tree is a BST of size 0
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree of current size
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right,
        // it is a BST
        if(left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST
            int sum = left.maxSum + right.maxSum + root->val;
            ans = max(sum, ans);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), sum);
        }

        // Otherwise return [-inf, inf] so that parent can't be a valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

public:
    int maxSumBST(TreeNode* root){
        maxSumBSTHelper(root);
        return ans;
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
    root->left->left->left = new TreeNode(30);
    root->left->left->right = new TreeNode(7);

    root->left->left->left->left = new TreeNode(2);
    root->left->left->left->right = new TreeNode(4);

    root->left->left->right->left = new TreeNode(6);

    root->left->left->left->left->left = new TreeNode(1);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(1);
    root->right->left->right = new TreeNode(11);

    printBST(root);

    Solution sol;

    cout << sol.maxSumBST(root) << endl;
    

}