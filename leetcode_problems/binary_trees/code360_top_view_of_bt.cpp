/**
 * Code360: Top View of Binary Tree
 * Link: https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401
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
 *      - map(vertical, node->val)
*/
template <typename T>
vector<T> topView(BinaryTree<T>* root){
    vector<T> ans;

    queue<pair<BinaryTree<T>* , pair<int, int>>> que;
    
    map<int, int> nodes;

    que.push({root, {0,0}});

    while(!que.empty()) {
        auto p = que.front();
        que.pop();

        int vertical = p.second.first;
        int level = p.second.second;
        BinaryTree<T>* n = p.first;
        
        if(nodes.find(vertical) == nodes.end())
            nodes[vertical] = n->data;

        if(n->left != nullptr)
            que.push({n->left, {vertical-1, level+1}});

        if(n->right != nullptr)
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
    insert(root->left->right, 5);
    insert(root->right->right, 6);

    insert(root->left->left->right, 7);
    insert(root->right->right->left, 8);

    insert(root->left->left->right->left, 9);
    insert(root->right->right->left->right, 11);

    insert(root->left->left->right->left->left, 10);
    
    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    auto res = topView(root);

    for(auto &i: res){
        cout << i << " ";
    }

    cout << endl;
    
}


