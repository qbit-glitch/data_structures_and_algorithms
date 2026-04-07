/**
 * Leetcode-863: Nodes at distance k in Binary Tree
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
void markParents(BinaryTree<T>* root, unordered_map<BinaryTree<T>*, BinaryTree<T>*> &parents_track){
    queue<BinaryTree<T>*> q;

    q.push(root);

    while(!q.empty()){
        BinaryTree<T>* node = q.front();
        q.pop();

        if(node->left){
            parents_track[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parents_track[node->right] = node;
            q.push(node->right);
        }
    }
}




template <typename T>
vector<int> distanceK(BinaryTree<T>* root, BinaryTree<T>* target, int k){
    unordered_map<BinaryTree<T>*, BinaryTree<T>*> parents_track;
    markParents(root, parents_track);

    unordered_map<BinaryTree<T>*, bool> visited;
    queue<BinaryTree<T>*> q;

    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    while(!q.empty()){
        int len = q.size();
    
        if(curr_level == k)
            break;

        curr_level++;

        for(int i=0; i<len; i++){
            auto node = q.front();
            q.pop();
            
            if(node->left and !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right and !visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parents_track[node] and !visited[parents_track[node]]){
                q.push(parents_track[node]);
                visited[parents_track[node]] = true;
            }
        }
    }

    vector<int> res;
    while(!q.empty()){
        BinaryTree<T>* node = q.front();
        res.push_back(node->data);
        q.pop();
    }
    return res;
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

    auto ans = distanceK(root, root->left, 2);
    printVector(ans);
    cout << endl;
    
}


