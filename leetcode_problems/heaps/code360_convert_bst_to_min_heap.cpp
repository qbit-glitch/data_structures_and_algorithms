/** Code360: Convert BST to Min Heap
 * Link: https://www.naukri.com/code360/problems/convert-bst-to-min-heap_920498
*/

#include <iostream>
#include <vector>
using namespace std;

class BinaryTreeNode {
    
public :
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
    this -> left = NULL;
    this -> right = NULL;
    this -> data = data;
    }
};

void inorderTraversal(BinaryTreeNode* root, vector<int> &inorder){
    if(root == nullptr)
        return;
    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);

    inorderTraversal(root->right, inorder);
}

void fillPreOrder(BinaryTreeNode* root, vector<int> &inorder, int& index){
    if(root == nullptr)
        return;
    
    root->data = inorder[index];
    index++;

    fillPreOrder(root->left, inorder, index);
    fillPreOrder(root->right, inorder, index);
}


/** Can I do something like this :
 * in-order traversal of BST
 * then insertion in the heap using preorder traversal
 */
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
    if(root == nullptr)
        return root;

    vector<int> inorder;
    inorderTraversal(root, inorder);
    int index = 0;
    fillPreOrder(root, inorder, index);
    return root;
}


void preorderTraversal(BinaryTreeNode* root){
    if(root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->left = new BinaryTreeNode(5);
    root->right = new BinaryTreeNode(10);

    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(6);

    preorderTraversal(root);
    cout << endl;
    BinaryTreeNode* newRoot = convertBST(root);
    preorderTraversal(newRoot);
    cout << endl;
}

