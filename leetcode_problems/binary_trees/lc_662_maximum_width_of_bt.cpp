/**
 * Leetcode-662: Maximum Width of Binary Tree
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
int widthOfBinaryTree(BinaryTree<T>* root){
    if(!root)
        return 0;
    
    queue<pair<BinaryTree<T>*, int>> q;
    int maxWidth = INT_MIN;

    q.push({root, 0});

    while(!q.empty()){
        int len = q.size();
        int min_index = q.front().second;
        int first, last;

        for(int i=0; i<len; i++){
            auto item = q.front();
            q.pop();
            int index = item.second - min_index;
            BinaryTree<T>* node = item.first;

            if(i == 0)
                first = index;
            if(i == len-1)
                last = index;
            
            if(node ->left)
                q.push({node->left, 2*index + 1});
            if(node->right)
                q.push({node->right, 2*index + 2});
        }
        maxWidth = max(maxWidth, last-first+1);
    }
    return maxWidth;
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

    auto ans = widthOfBinaryTree(root);
    
    cout << ans << endl;
    
}


