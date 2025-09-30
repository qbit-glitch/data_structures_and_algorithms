/**
 * GFG: Reverse a Doubly Linked List
 * Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
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

Node* reverseDLLUsingFront(Node* head){    
    if (head==NULL or head->next==NULL)     return head;

    Node* temp = head;
    Node* front = temp->next;
    while(temp != nullptr){
        
        temp->next = temp->prev;
        temp->prev = front;
        if (front != nullptr)
            temp = front;
        else
            break;
        front = front->next;
        
    }

    head = temp;
    return head;
}

Node* reverseDLLUsingBack(Node* head){
    if(head == NULL or head->next == NULL)
        return head;
    
    Node* temp = head;
    Node* last;

    while(temp != nullptr){
        last = temp->prev;
        temp->prev = temp->next;
        temp->next = last;
        temp = temp->prev;
    }
    head = last->prev;
    return head;
}




int main(){
    vector<int> a{1,5,2,7,10,11,90,18};
    Node* head = convertArrayToDLL(a);
    // head = insertBeforeKthPos(head, 100, 8);
    head = reverseDLLUsingBack(head);
    printDLL(head);
}