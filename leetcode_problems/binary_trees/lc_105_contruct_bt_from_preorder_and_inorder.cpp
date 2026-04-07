/**
 * Leetcode-105: Construction Binary Tree from Pre-Order and Post-Order
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
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

template <typename T>
void printVector(vector<T> &a){
    for(auto &i: a){
        cout << i << endl;
    }
}


template <typename T>
BinaryTree<T>* buildTreeRec(vector<T> &preorder, int preStart, int preEnd, vector<T> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap){
    if(preStart > preEnd || inStart > inEnd)
        return nullptr;
    
    BinaryTree<T>* root = new BinaryTree(preorder[preStart]);
    int inRoot = inMap[root->data];

    int numsLeft = inRoot - inStart;
    root->left = buildTreeRec(preorder, preStart+1, preStart + numsLeft, inorder, inStart, inRoot-1, inMap);
    root->right = buildTreeRec(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

    return root;
}




template <typename T>
BinaryTree<T>* buildTree(vector<T> &inorder, vector<T> &preorder){
    // create hashmap for each nodes' val present in inorder
    unordered_map<T, int> inMap;
    for(int i=0; i<inorder.size(); i++){
        inMap[inorder[i]] = i;
    }

    BinaryTree<T>* root = buildTreeRec(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}



int main() {
    BinaryTree<int> *root = new BinaryTree(3);
    
    insert(root->left, 5);
    insert(root->right, 1);

    insert(root->left->left, 6);
    insert(root->left->right, 2);
    insert(root->right->right, 8);
    insert(root->right->left, 0);

    insert(root->left->right->left, 7);
    insert(root->left->right->right, 4);

    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    vector<int> preorder {3,5,6,2,7,4,1,0,8};
    vector<int> inorder {6,7,2,4,5,3,0,1,8};

    auto newRoot = buildTree(inorder, preorder);

    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    
}


