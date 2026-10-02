/** GFG : Is Binary Tree Heap
 * Link: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
*/

#include <iostream>
using namespace std;

/** is Binary Tree a Heap :
 * - check if array is CBT
 * - Satisfy heap property => maxHeap
 * - check if root node > left and right child
 * - So create two functions one for checking CBT and another for checking whether the tree is satisfying the heap property
 */

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {

    private:
       int countNodes(Node* root){
        if(root == nullptr)
            return 0;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }

    /*
    isCBT(root, i, nodeCount){
        if leftIndex or rightIndex goes out of nodeCount
            NOT a CBT
        else
            CBT
    */

    bool isCBT(Node* root, int index, int totalNodes){
        if(root == nullptr)
            return true;
        if(index >= totalNodes)
            return false;

        bool left = isCBT(root->left, 2*index + 1, totalNodes);
        bool right = isCBT(root->right, 2*index + 2, totalNodes);

        return left && right;

    }    
    
    
    /*
    maxHeapProperty :
        total 3 nodes possible :
            - Both child exist
            - Leaf Node
            - Only Left exist
    
    */
    bool isMaxOrder(Node* root){
        if(root == nullptr)
            return true;
        if(root->left == nullptr and root->right == nullptr)
            return true;
        
        if(root->right == nullptr){
            return (root->data > root->left->data);
        }
        else {
            
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            return (left && right &&(root->data > root->left->data && root->data > root->right->data));
        }
    }


    public:
    /** Algo :
     * solve(){
     *      if(isCBT() and isMaxOrder())
     *          return true;
     *      else 
     *          return false;
     * }
     * 
    */
    bool isHeap(Node* root) {
        if(root == NULL)
            return true;
        int totalNodes = countNodes(root);
        int index = 0;
        if(isCBT(root, index, totalNodes) && isMaxOrder(root))
            return true;
        else    return false;

    }

};


void printTree(Node* root, const string &prefix="", bool isLeft=false){
    if(root == nullptr)
        return;
    cout << prefix;
    cout << (isLeft ? "|-- " : "'-- ");
    cout << root->data << endl;

    string childPrefix = prefix + (isLeft ? "|  " : "   ");
    printTree(root->left, childPrefix, true);
    printTree(root->right, childPrefix, false);
}

int main(){
    Node *root = new Node(6);
    
    root ->left = new Node(4);
    root->right = new Node(3);

    root->left->right = new Node(2);

    Solution sol;
    printTree(root, "", true);

    cout << sol.isHeap(root) << endl;
    
}