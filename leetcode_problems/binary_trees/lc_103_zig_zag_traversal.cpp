/**
 * Leetcode-103: Zig Zag Level Traversal
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
vector<vector<T>> zigzagLevelOrder(BinaryTree<T>* root){
    vector<vector<T>> result;

    queue<BinaryTree<T>*> nodesQueue;
    nodesQueue.push(root);

    bool leftToRight = true;

    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<T> row(size);

        for(int i=0; i<size; i++){
            auto node = nodesQueue.front();
            nodesQueue.pop();

            // finding the index in the vector where the node's value will be inserted 
            int index = (leftToRight) ? i : size-1-i;

            row[index] = node->data;

            if(node->left)
                nodesQueue.push(node->left);

            if(node->right)
                nodesQueue.push(node->right);
        }
        // after traversing the level invert the sign
        leftToRight = !leftToRight;

        result.push_back(row);
    }
    return result;
}

template <typename T>
void printVectorOfVectors(vector<vector<T>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
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

    auto result = zigzagLevelOrder(root);
    printVectorOfVectors(result);
}


