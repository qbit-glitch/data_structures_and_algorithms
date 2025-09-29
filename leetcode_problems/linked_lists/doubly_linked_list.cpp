/**
 * Description: Doubly Linked List Basic Functions
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

void printDLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head -> next;
    }
    cout << endl;
}

Node* convertArrayToDLL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); i++){
        Node* newNode = new Node(a[i], nullptr, mover);
        mover->next = newNode;
        mover = newNode;
    }
    return head;
}



int main(){
    vector<int> a{1,5,2,7,10,11};
    Node* head = convertArrayToDLL(a);
    printDLL(head);
}