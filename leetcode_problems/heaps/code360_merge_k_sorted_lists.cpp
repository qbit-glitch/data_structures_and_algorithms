/** Code 360: Merge K sorted Lists
 * Link: https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772
 * Status: Very Important
*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

/* thinking about the approach :
    - same approach as merging k sorted arrays, the only thing is we need to delete the nodes from one place and join them to another
    - so for this we need to define a new datastructure or container which holds the nodes, the pointer to each node
*/



class compare{
public:
    bool operator() (Node* a, Node* b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    
    for(int i=0; i < listArray.size(); i++){
        Node* n1 = listArray[i];
        minHeap.push(n1);
    }

    Node* ans = new Node(-1);
    Node* ansRoot = ans;

    while(!minHeap.empty()){
        Node* n = minHeap.top();
        minHeap.pop();

        if(n->next != nullptr){
            Node* newRoot = n->next;
            n->next = nullptr;
            minHeap.push(newRoot);
        }

        ans->next = n;
        ans = ans->next;
        
    }
    return ansRoot->next;
}

void printLL(Node* root){
    while(root != nullptr){
        cout << root -> data << " ";
        root = root->next;
    }
    cout << endl;
}


int main(){
    Node* root1 = new Node(4);
    root1->next = new Node(8);
    root1->next -> next = new Node(10);

    Node* root2 = new Node(2);
    root2->next = new Node(5);
    root2->next -> next = new Node(7);
    root2->next -> next -> next = new Node(9);

    vector<Node*> a{root1, root2};

    printLL(root1);
    printLL(root2);

    Node* ans = mergeKLists(a);
    printLL(ans);
}


