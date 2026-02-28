/**
 * Topic: Pre Order, Inorder, PostOrder Traversal in a single pass
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;



struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};

void printVector(vector<int> &a) {
    for(auto &i: a){
        printf("%d, ", i);
    }
    cout << endl;
}

class Solution {
    public:
    vector<int> preInPostTraversal(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        vector<int> pre, in, post;

        if(root == NULL)    
            return {};

        while(!st.empty()) {
            pair<TreeNode*, int> item = st.top();
            st.pop();

            if(item.second == 1){
                pre.push_back(item.first->data);
                item.second++;
                st.push(item);

                if(item.first->left != NULL) {
                    st.push({item.first->left, 1});
                }
                
            }

            else if(item.second == 2) {
                in.push_back(item.first->data);
                item.second++;
                st.push(item);

                if(item.first->right != NULL) {
                    st.push({item.first->right,1});
                }
            }

            else {
                post.push_back(item.first->data);
            }
        }

        printVector(pre);
        printVector(in);
        printVector(post);

        return in;
    }
};


int main(){
    TreeNode* root = new TreeNode(23);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    Solution sol;
    vector<int> inorder = sol.preInPostTraversal(root);

    printVector(inorder);

}