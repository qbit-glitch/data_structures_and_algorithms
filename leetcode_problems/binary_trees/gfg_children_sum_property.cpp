/**
 * GFG: Children Sum Property
 * Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1
*/



#include <iostream>
#include <vector>
#include <map>
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
bool isSumProperty(BinaryTree<T>* root){
    return isSumRec(root).second;
}

template <typename T>
pair<T, bool> isSumRec(BinaryTree<T>* node){
    if(node == nullptr)
        return {0, true};

    if(node->left == nullptr and node->right == nullptr)
        return {node->data, true};

    pair<T, bool> left = isSumRec(node->left);
    pair<T, bool> right = isSumRec(node->right);

    if(left.second == true and right.second == true){
        if(left.first + right.first == node->data)
            return {node->data, true};
        else
            return {node->data, false};
    }
    else 
        return {node->data, false};
}




int main() {
    BinaryTree<int> *root = new BinaryTree(35);
    
    insert(root->left, 20);
    insert(root->right, 15);

    insert(root->left->left, 15);
    insert(root->left->right, 5);
    insert(root->right->right, 10);
    insert(root->right->left, 5);

    insert(root->left->right->left, 0);
    insert(root->left->right->right, 0);

    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    auto ans = isSumProperty(root);
    
    cout << ans << endl;
    
}


