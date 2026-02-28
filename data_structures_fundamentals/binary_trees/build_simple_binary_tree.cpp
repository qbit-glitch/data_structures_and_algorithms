/**
 * Building a Simple Binary Tree in C++
*/

#include <iostream>
#include <vector>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data1) {
        data = data1;
        left = NULL;
        right = NULL;
    }
};

int main() {
    Node* root = new Node(23);
    root->left = new Node(20);
    root->right = new Node(25);

    printf("%d, %d, %d", root->data, root->left->data, root->right->data);
}