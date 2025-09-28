/**
 * Leetcode-237: Delete Node from a Linked List
 * 
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* deleteNode(Node* head, Node* node){
    if(head == NULL)
        return NULL;
    if(head->data == node->data)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(temp->data == node->data){
            prev->next = prev->next->next;  
            free(temp);
            break;          
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* convertArrayToSLL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); i++){
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head){
    Node* mover = head;
    while(mover != NULL){
        cout << mover->data << " -> ";
        mover = mover->next;
    }
}

int main(){
    vector<int> a{4,6,8,2,1};
    Node* head = convertArrayToSLL(a);
    head = deleteNode(head, new Node(8));
    printLL(head);
}