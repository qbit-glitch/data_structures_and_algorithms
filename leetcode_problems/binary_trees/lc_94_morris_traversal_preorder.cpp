#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left1, TreeNode* right1) {
        val = x;
        left = left1;
        right = right1;
    }
};



void printBinaryTreeFancy(TreeNode* root, const string& prefix = "", bool isLeft = false){
    if (root == nullptr)    return;

    cout << prefix;
    cout << (isLeft ? "├── " : "└── ");
    cout << root -> val << "\n";

    string childPrefix = prefix + (isLeft ? "|  " : "   ");
    printBinaryTreeFancy(root->left, childPrefix, true);
    printBinaryTreeFancy(root->right, childPrefix, false);
}

void printVector(vector<int> &a){
    for(auto &i: a){
        cout << i << " " << endl;
    }
    cout << endl;
}

/*
            1
        2       3
    4       5   
                6
*/

class Solution{
    public:
    /** Thought Process
    - 1st Case: left -> null &&  print(current guy) and move to the next
    - 2nd Case: 
        - a. if the rightmost guy on the left doesn't have the thread then,
            - rightmost guy on left subtree, will be connected to the current
            - and then current = current -> left
            
        - b. the threaded binary tree already exist. so we have to first remove the connection of the thread and then move to the right i.e. current = current->right
    */

    /** Overall algo :
     * Standing at the current check on the left subtree, who is the rightmost guy, then make the connection (thread) to the root and then move to the left
     * Once we create the thread move to the left
     * if the left is nullptr then print the node
     * if the current node is pointing to itself, then move to the left and cut the node and then move to the right.
     * Refer to this image for reference: ../../../striver_notes_images/binary_trees/morris_traversal_inorder.png
     */
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> preorder;
        TreeNode* curr = root;

        while(curr != NULL) {
            if(curr -> left == NULL) {
                preorder.push_back(curr->val);
                curr = curr -> right;
            }

            else {
                TreeNode *prev = curr -> left;
                
                while(prev -> right && prev->right != curr) {
                    prev = prev -> right;
                }

                if(prev -> right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr -> val);
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return preorder;
    }
};



int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* temp = root;
    temp->left = new TreeNode(2);
    temp->right = new TreeNode(3);
    temp->left->left = new TreeNode(4);
    temp->left->right = new TreeNode(5);
    temp->left->right->right = new TreeNode(6);
    

    printBinaryTreeFancy(root);

    Solution sol;
    vector<int> ans = sol.preorderTraversal(root);

    printVector(ans);
}

