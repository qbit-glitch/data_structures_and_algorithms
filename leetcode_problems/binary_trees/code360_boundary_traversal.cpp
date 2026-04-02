/**
 * Code360: Boundary Traversal
 * Link: https://www.naukri.com/code360/problems/boundary-traversal_790725
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
void printVectorOfVectors(vector<vector<T>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

template <typename T>
bool isLeaf(BinaryTree<T> *node){
    if(node->left == nullptr and node->right == nullptr)
        return true;
    return false;
}

template <typename T>
void addLeftBoundary(BinaryTree<T>* root, vector<T> &res){
    BinaryTree<T> *cur = root->left;
    
    while(cur != nullptr){
        if(!isLeaf(cur))
            res.push_back(cur->data);
        
        if(cur->left != nullptr)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

template <typename T>
void addRightBoundary(BinaryTree<T>* root, vector<T> &res){
    BinaryTree<T> *cur = root->right;
    vector<T> tmp;

    while(cur != nullptr){
        if(!isLeaf(cur))
            tmp.push_back(cur->data);
        
        if(cur->right != nullptr)
            cur = cur->right;
        else
            cur = cur->left;
    }

    for(int i=tmp.size()-1; i>= 0; i--){
        res.push_back(tmp[i]);
    }

}

template <typename T>
void addLeaves(BinaryTree<T>* root, vector<T> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left != nullptr) 
        addLeaves(root->left, res);

    if(root->right != nullptr)  
        addLeaves(root->right, res);
}




template <typename T>
vector<T> traverseBoundary(BinaryTree<T>* root){
    vector<T> res;
    if(root == nullptr)
        return res;
    if(!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}




int main() {
    BinaryTree<int> *root = new BinaryTree(-10);
    
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

    auto res = traverseBoundary(root);

    for(auto &i: res){
        cout << i << " ";
    }
    
}


