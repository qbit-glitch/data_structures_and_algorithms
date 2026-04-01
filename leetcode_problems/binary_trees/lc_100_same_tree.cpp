/**
 * Leetcode-124: Binary Tree Maximum Path Sum
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


template<typename T>
bool isSameTree(BinaryTree<T>* p, BinaryTree<T>* q){
    return checkRecursive(p, q);
}

template <typename T>
bool checkRecursive(BinaryTree<T>* p, BinaryTree<T> *q){
    if(p == nullptr and q == nullptr)
        return true;

    if((p != nullptr and q == nullptr) or (p == nullptr and q != nullptr))
        return false;
    
    if(p->data != q->data)
        return false;
    
    if((p->left == nullptr and q->left != nullptr) or (p->left != nullptr and q->left == nullptr))
        return false;

    if((p->right == nullptr and q->right != nullptr) or (p->right != nullptr and q->right == nullptr))
        return false;
    
    return checkRecursive(p->left, q->left) and checkRecursive(p->right, q->right);
}


int main() {
    BinaryTree<int> *p = new BinaryTree(-10);
    insert(p->left, 9);
    insert(p->right, 20);

    insert(p->right->left, 22);
    insert(p->right->right, 7);
    

    BinaryTree<int> *q = new BinaryTree(-10);
    insert(q->left, 9);
    insert(q->right, 20);

    insert(q->right->left, 15);
    insert(q->right->right, 7);
    

    string prefix = "";
    cout << p->data << endl;
    printBinaryTree(p->left, prefix, true);
    printBinaryTree(p->right, prefix, false);


    prefix = "";
    cout << q->data << endl;
    printBinaryTree(q->left, prefix, true);
    printBinaryTree(q->right, prefix, false);


    cout << "Is Same Tree: " << isSameTree(p,q) << endl;
}


