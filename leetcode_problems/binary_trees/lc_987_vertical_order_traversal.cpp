/**
 * Code360: Boundary Traversal
 * Link: https://www.naukri.com/code360/problems/boundary-traversal_790725
*/



#include <iostream>
#include <vector>
#include <set>
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
 * - DO any kind of traversal - we'll be going through level order traversal
 * - Take 2 data structures :
 *      - Queue(node, vertical, level)
 *      - map(vertical, map(level, ordered_collection(nodes)))
*/
template <typename T>
vector<vector<T>> verticalTraversal(BinaryTree<T>* root){
    vector<vector<T>> ans;

    queue<pair<BinaryTree<T>* , pair<int, int>>> que;
    
    map<int, map<int, multiset<T>>> nodes;

    que.push({root, {0,0}});

    while(!que.empty()) {
        auto p = que.front();
        que.pop();

        int vertical = p.second.first;
        int level = p.second.second;
        BinaryTree<T>* n = p.first;

        nodes[vertical][level].insert(n->data);

        if(n->left != nullptr)
            que.push({n->left, {vertical-1, level+1}});

        if(n->right != nullptr)
            que.push({n->right, {vertical+1, level+1}});
    }
    
    for(auto &p: nodes){
        vector<T> col;
        for(auto &q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;
} 




int main() {
    BinaryTree<int> *root = new BinaryTree(1);
    insert(root->left, 2);
    insert(root->right, 3);
    
    insert(root->left->left, 4);
    insert(root->left->right, 6);
    insert(root->right->left, 5);
    insert(root->right->right, 7);
    

    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    auto res = verticalTraversal(root);
    printVectorOfVectors(res);
    
}


