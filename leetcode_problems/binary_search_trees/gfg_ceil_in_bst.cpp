#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int val): data(val), left(nullptr), right(nullptr){}
    Node(int val, Node* left, Node* right): data(val), left(left), right(right){}
};

void printBST(Node* root, const string &prefix="", bool isLeft=false){
    if(root == nullptr) return;

    cout << prefix;
    cout << (isLeft ? "|-- " : "'-- ");
    cout << root->data << endl;

    string childPrefix = prefix + (isLeft ? "|  " : "   ");
    printBST(root->left, childPrefix, true);
    printBST(root->right, childPrefix, false);
}

class Solution{
    public:
    int findCeil(struct Node* root, int x) {
        int ceil = -1;
        while(root){
            if(root->data == x){
                ceil = root->data;
                return ceil;
            }
            if (x > root->data){
                root = root->right;
            }
            else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
};

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);

    root->left->left = new Node(4);
    root->left->right = new Node(7);
    
    root->left->right->left = new Node(6);

    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    printBST(root);

    int x = 5;
    Solution sol;
    cout << sol.findCeil(root, 9) << endl;
}