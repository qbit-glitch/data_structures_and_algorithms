/** Floor in BST
 * Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
*/

#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }

    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int data, Node* left, Node* right): data(data), left(left), right(right){}
};

void printBST(Node* root, const string &prefix="", bool isLeft=false){
    if(root == nullptr)
        return;

    cout << prefix;
    cout << (isLeft ? "|-- ": "'-- ");
    cout << root->data << endl;
    
    string childPrefix = prefix + (isLeft ? "|  " : "   ");
    printBST(root->left, childPrefix, true);
    printBST(root->right, childPrefix, false);
}

class Solution{
    public:
    int findMaxFork(Node* root, int k){
        int floor = -1;
        Node* curr = root;
        while(curr != nullptr){
            if(curr->data == k){
                floor = curr->data;
                return floor;
            }
            else if (k > curr->data){
                floor = curr->data;
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        return floor;
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

    Solution sol;
    int x = 9;
    cout << "Floor: " << sol.findMaxFork(root, x);
    
}
