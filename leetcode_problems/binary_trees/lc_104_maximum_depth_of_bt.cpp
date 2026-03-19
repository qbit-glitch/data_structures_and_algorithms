/**
 * Leetcode-104: Maximum Depth of BT
*/


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct BinaryTree{
    T data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(): data(T{}), left(nullptr), right(nullptr) {}
    BinaryTree(T d): data(d), left(nullptr), right(nullptr) {}
    BinaryTree(T d, BinaryTree* left, BinaryTree* right): data(d), left(left), right(right) {}

    ~BinaryTree(){
        delete left;
        delete right;
    }
};

template<typename T>
void insert(BinaryTree<T>*& ptr, T val) {
    BinaryTree<T> *node = new BinaryTree(val);
    ptr = node;
}

template <typename T>
void printBinaryTree(BinaryTree<T>* root, string prefix, bool is_left){
    if(root == nullptr)
        return;
    
    string connector = is_left ? "|--" : "'--";
    cout << prefix << connector << root->data << endl;

    string new_prefix = prefix + (is_left ? "|  " : "   ");
    printBinaryTree(root->left, new_prefix, true);
    printBinaryTree(root->right, new_prefix, false);
}



template <typename T>
int heightOfBT(BinaryTree<T>* root){
    // let's write the code similar to the inorder traversal
    stack<pair<BinaryTree<T>*,int>> st;
    st.push({root, 1});
    int currDepth = 1, maxDepth = 0;
    BinaryTree<T>* item = root;
    while(item != nullptr or !st.empty()){
        while(item != nullptr){
            st.push({item, currDepth});
            item = item->left;
            currDepth++;
        }
        auto [node, depth] = st.top(); st.pop();
        maxDepth = max(maxDepth, depth);
        
        item = node->right;
        currDepth = depth+1;
    }
    return maxDepth;
}


template <typename T>
int maxDepthRecursive(BinaryTree<T> *root) {
    if(root == nullptr)
        return 0;
    return max(1+maxDepthRecursive(root->left), 1 + maxDepthRecursive(root->right));
}

int main() {
    BinaryTree<int> *root = new BinaryTree(2);
    insert(root->left, 4);
    insert(root->right, 6);

    insert(root->right->right, 8);
    insert(root->right->left, 10);

    insert(root->right->left->left, 12);
    insert(root->right->left->right, 14);

    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    cout << heightOfBT(root) << endl;

    cout << maxDepthRecursive(root) << endl;
}


