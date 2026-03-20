/**
 * Leetcode-110: Balanced Binary Tree
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



// return height of tree if balanced, else return -1
template<typename T>
int isBalanced(BinaryTree<T>* root) {
    if(root == nullptr)
        return 0;
    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);

    if(lh == -1 or rh == -1)    return -1;
    if(abs(lh-rh) > 1)  return -1;

    return max(lh, rh) + 1;
}

int main() {
    BinaryTree<int> *root = new BinaryTree(2);
    insert(root->left, 4);
    insert(root->right, 6);
    
    insert(root->left->left, 4);
    insert(root->left->left->left, 4);
    insert(root->left->left->left->left, 4);


    insert(root->right->right, 8);
    insert(root->right->left, 10);

    insert(root->right->left->left, 12);
    insert(root->right->left->right, 14);

    insert(root->right->left->left->right, 16);
    insert(root->right->left->left->right->right, 18);

    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);


    bool isBalance = (isBalanced(root) != -1)? true : false;
    cout << isBalance << endl;
}


