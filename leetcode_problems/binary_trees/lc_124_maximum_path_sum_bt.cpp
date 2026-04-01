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


template <typename T>
int maxPathSum(BinaryTree<T>* root){
    T maxi = std::numeric_limits<T>::min();
    findMaxPath(root, maxi);
    return maxi;
}

template <typename T>
int findMaxPath(BinaryTree<T> *node, T &maxi){
    if(node == nullptr)
        return 0;
    T leftSum = max(0, findMaxPath(node->left, maxi));
    T rightSum = max(0, findMaxPath(node->right, maxi));

    maxi = max(maxi, leftSum + rightSum + node->data);

    return max(leftSum, rightSum) + node->data;
}




int main() {
    BinaryTree<int> *root = new BinaryTree(-10);
    insert(root->left, 9);
    insert(root->right, 20);

    insert(root->right->left, 15);
    insert(root->right->right, 7);
    
    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    cout << "Max path Sum: " << maxPathSum(root) << endl;
}


