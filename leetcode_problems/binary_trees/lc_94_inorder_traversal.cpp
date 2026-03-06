/**
 * Leetcode-94: Inorder Traversal in Binary Tree using iterative approach
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;    
    }

    TreeNode(): data(0), left(nullptr), right(nullptr) {}

    TreeNode(int val, TreeNode* left1, TreeNode* right1){
        data = val;
        left = left1;
        right = right1;
    }
};

// reference to pointer
void insert(TreeNode* &root, int val) {
    if(root == nullptr){
        root = new TreeNode(val);
        return;
    }
    
    if(val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

class Solution {
public:
    vector<int> inorderTraversal_iterative(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true) {
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty())  break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }
};

void printVector(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

void printBinaryTree(TreeNode* root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
    cout << endl;
}

void printTreeFancy(TreeNode* root, const string& prefix = "", bool isLeft = false) {
    if (root == nullptr) return;

    cout << prefix;
    cout << (isLeft ? "├── " : "└── ");
    cout << root->data << "\n";

    string childPrefix = prefix + (isLeft ? "│   " : "    ");
    printTreeFancy(root->left,  childPrefix, true);
    printTreeFancy(root->right, childPrefix, false);
}

int main(){
    TreeNode* root = nullptr;
    
    vector<int> datas {50,30,70,20,40,60,80,10,13,25,78,90};
    for(int &i: datas){
        insert(root, i);
    }

    printBinaryTree(root);
    
    printTreeFancy(root);
    
    Solution sol;
    vector<int> ans = sol.inorderTraversal_iterative(root);
    
    printVector(ans);
}



