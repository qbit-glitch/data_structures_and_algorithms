/**
 * Code360: Time to Burn the Binary Tree
 * Link: https://www.naukri.com/code360/problems/time-to-burn-tree_630563
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
void printQueue(queue<BinaryTree<T>*> q){
    while(!q.empty()){
        auto item = q.front();
        q.pop();

        cout << item->data << " ";
    }
    cout << endl;
}


template <typename T>
BinaryTree<T>* findNodeAddress(BinaryTree<T>* node, int val){
    // preorder traversal
    if(node == nullptr)
        return node;
    
    if(node->data == val)
        return node;

    
    auto left = findNodeAddress(node->left, val);
    auto right = findNodeAddress(node->right, val);

    if(left)
        return left;
    return right;
}

template <typename T>
void markParents(BinaryTree<T>* root, unordered_map<BinaryTree<T>*, BinaryTree<T>*> &parents_track){
    queue<BinaryTree<T>*> q;
    q.push(root);
    // doing normal inorder traversal using queue
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
int timeToBurnTree(BinaryTree<T>* root, int start){
    BinaryTree<T>* startNode = findNodeAddress(root, start);
    
    unordered_map<BinaryTree<T>*, BinaryTree<T>*> parents_track;
    markParents(root, parents_track);
    
    unordered_map<BinaryTree<T>*, bool> visited;
    int dist = 0;

    queue<BinaryTree<T>*> q;
    q.push(startNode);
    visited[startNode] = true;

    int timeCost = 0;

    while(!q.empty()){
        int len = q.size();
        timeCost++;

        printQueue(q);
        
        for(int i=0; i<len; i++){
            BinaryTree<T>* node = q.front();
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
    return timeCost-1;
}



int main() {
    BinaryTree<int> *root = new BinaryTree(1);
    
    insert(root->left, 2);
    insert(root->right, 3);

    insert(root->left->left, 4);
    insert(root->left->right, 5);
    insert(root->right->right, 6);

    insert(root->left->right->left, 7);
    insert(root->left->right->right, 8);
    insert(root->right->right->left, 9);

    insert(root->right->right->left->left, 10);
    


    string prefix = "";
    cout << root->data << endl;
    printBinaryTree(root->left, prefix, true);
    printBinaryTree(root->right, prefix, false);

    auto ans = timeToBurnTree(root, 8);
    cout << ans << endl;
    
}














