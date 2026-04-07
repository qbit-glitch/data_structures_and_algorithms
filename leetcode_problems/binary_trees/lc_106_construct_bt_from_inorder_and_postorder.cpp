/**
 * Leetcode-106: Construct Binary from inorder and postorder traversal
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
BinaryTree<T>* buildTreeRec(vector<T> &inorder, int inStart, int inEnd, vector<T> &postorder, int postStart, int postEnd, unordered_map<T, int> inorderMap){
    if(inStart > inEnd || postStart > postEnd)
        return nullptr;

    BinaryTree<T>* root = new BinaryTree(postorder[postEnd]);
    
    int inorderRoot = inorderMap[root->data];
    int numsLeft = inorderRoot - inStart;

    root->left = buildTreeRec(inorder, inStart, inorderRoot-1, postorder, postStart, postStart+numsLeft-1, inorderMap);
    root->right = buildTreeRec(inorder, inorderRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, inorderMap);

    return root;
}



template <typename T>
BinaryTree<T>* buildTree(vector<T> &inorder, vector<T> &postorder){
    unordered_map<T, int> inorderMap;
    for(int i=0; i < inorder.size(); i++){
        inorderMap[inorder[i]] = i;
    }

    BinaryTree<T>* root = buildTreeRec(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inorderMap);
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

    vector<int> postorder {6,7,4,2,5,0,8,1,3};
    vector<int> inorder {6,5,7,2,4,3,0,1,8};

    auto newRoot = buildTree(inorder, postorder);

    cout << newRoot->data << endl;
    printBinaryTree(newRoot->left, prefix, true);
    printBinaryTree(newRoot->right, prefix, false);

    
}


