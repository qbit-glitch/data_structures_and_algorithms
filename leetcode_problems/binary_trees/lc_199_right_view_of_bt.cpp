/**
 * leetcode-199: Right View of Binary Tree
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



/** Approach :
 * - DO level order traversal 
 * - Take 2 data structures :
 *      - Queue(node, vertical, level)
 *      - map(level, map(vertical, rightMostNode->val))
*/
template <typename T>
vector<T> rightSideView(BinaryTree<T>* root){
    vector<T> ans;

    queue<pair<BinaryTree<T>*, pair<int, int>>> que;
    map<int, T> nodes;

    que.push({root, {0,0}});

    while(!que.empty()){
        auto item = que.front();
        que.pop();

        BinaryTree<T>* n = item.first;
        int vertical = item.second.first;
        int level = item.second.second;

        nodes[level] = n->data;

        if(n->left)
            que.push({n->left, {vertical-1, level+1}});
        if(n->right)
            que.push({n->right, {vertical+1, level+1}});
    }

    for(auto &p: nodes){
        ans.push_back(p.second);
    }
    return ans;
} 




int main() {
    BinaryTree<int> *root = new BinaryTree(1);
    
    insert(root->left, 2);
    insert(root->right, 3);

    insert(root->left->left, 4);
    insert(root->left->left->left, 5);
    // insert(root->right->left, 6);
    // insert(root->right->right, 7);

    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    auto res = rightSideView(root);

    for(auto &i: res){
        cout << i << " ";
    }

    cout << endl;
}
