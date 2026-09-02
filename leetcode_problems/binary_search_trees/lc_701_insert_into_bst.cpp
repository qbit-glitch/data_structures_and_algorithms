#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right){}
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


class Solution{
    public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root ==nullptr)  return  new TreeNode(val);

        TreeNode* curr = root;
        TreeNode* node = new TreeNode(val);

        while(true){
            if(val <= curr->val){ // left subtree
                if(curr ->left != NULL)
                    curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }

            } else {
                if(curr->right != nullptr)
                    curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
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

    printBST(root);

    Solution sol;
    int x = 9;
    TreeNode* newRoot = sol.insertIntoBST(root, x);
    printBST(newRoot);
 
}