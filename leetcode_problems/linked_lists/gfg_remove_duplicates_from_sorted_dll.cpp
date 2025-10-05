/**
 * GFG: Remove Duplicates from Sorted Doubly Linked List
 * Link: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
*/


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertArrayToDLL(vector<int> &a){
    if(a.size() == 0)
        return nullptr;
    Node* head = new Node(a[0]);
    Node* temp = head;

    for(int i=1; i<a.size(); i++){
        Node* n = new Node(a[i], nullptr, temp);
        temp->next = n;
        temp = temp->next;
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* removeDuplicates(Node* head){
    Node* temp = head;
    Node* back = nullptr;
    while(temp!=nullptr and temp->next != nullptr){
        Node* nextNode = temp -> next;
        while(nextNode!=NULL and nextNode->data == temp->data){
            nextNode = nextNode->next;
        }
        temp->next = nextNode;
        if(nextNode)
            nextNode->prev = temp;
        
        temp = temp->next;
    }
    return head;
    
}





int main(){
    vector<int> a{3,3,3,3,3,3,4,10,10,10,10,10,12,12,13,40,50};
    Node* head = convertArrayToDLL(a);
    head = removeDuplicates(head);
    printDLL(head);
    
}