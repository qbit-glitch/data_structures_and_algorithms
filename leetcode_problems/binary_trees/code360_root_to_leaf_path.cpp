/**
 * Code360: Root to leaf path
 * Link: https://www.naukri.com/code360/problems/root-to-leaf-path_2042001
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
vector<string> allRootToLeaf(BinaryTree<T>* root){
    queue<pair<BinaryTree<T>*, string>> q;
    vector<string> ans;

    q.push({root, ""});
    while(!q.empty()){
        int len = q.size();

        for(int i=0; i<len; i++){
            auto item = q.front();
            q.pop();

            BinaryTree<T>* node = item.first;
            string s = item.second;

            if(node->left)
                q.push({node->left, s + " " + std::to_string(node->data)});
            if(node->right)
                q.push({node->right, s + " " + std::to_string(node->data)});

            if(node->left == nullptr and node->right == nullptr)
                ans.push_back(s + " " + std::to_string(node->data));                
        }
    }
    return ans;
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

    auto ans = allRootToLeaf(root);
    printVector(ans);
    cout << endl;
    
}


