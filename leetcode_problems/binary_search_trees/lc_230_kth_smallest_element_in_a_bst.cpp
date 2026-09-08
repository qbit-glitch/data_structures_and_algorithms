#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


/** Thought Process:
 * Inorder Traversal of a Binary Search Tree always gives the sorted order of the values present in the BST
 * So count the number of nodes we have traversed in inorder traversal, the kth node will give use the kth smallest
*/

class Solution{
    public:
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int cnt = 0;
        int kthSmall = 0;
        while(curr != nullptr || !st.empty()){

            // Move to left
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }

            // Process the node
            cnt++;
            curr = st.top();
            st.pop();

            if(cnt == k){
                kthSmall = curr->val;
            }

            // Move to right
            curr = curr->right;

        }
        return kthSmall;
    }
};


void printBST(TreeNode* root, const string &prefix="", bool isLeft=false){
    if(root == nullptr)
        return;
    cout << prefix;
    cout << ((isLeft) ? "|-- " : "'-- ");
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
    root->left->left->right->right = new TreeNode(8);

    root->left->left->left->left->left = new TreeNode(1);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(13);
    root->right->right->left = new TreeNode(11);

    printBST(root);

    Solution sol;
    int x = 3;
    cout << sol.kthSmallest(root, x) << endl;
}

