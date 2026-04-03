/**
 * Leetcode-101: Symmetric Binary Tree
*/



#include <iostream>
#include <vector>
#include <map>
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
void printVectorOfVectors(vector<vector<T>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}


template<typename T>
bool isSymmetric(BinaryTree<T>* root){
    if(root == nullptr)
        return true;
    return isMirror(root->left, root->right);
}

template<typename T>
bool isMirror(BinaryTree<T>* p, BinaryTree<T>* q){
    if(p == nullptr or q == nullptr)
        return (p == q);

    if(p->data != q->data)
        return false;
    
    return isMirror(p->left, q->right) and isMirror(p->right, q->left);
    
}



int main() {
    BinaryTree<int> *root = new BinaryTree(1);
    
    insert(root->left, 2);
    insert(root->right, 2);

    insert(root->left->left, 3);
    insert(root->left->right, 4);
    
    insert(root->right->left, 4);
    insert(root->right->right, 3);
    
    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    auto res = isSymmetric(root);
    cout << res << endl;
    
}


