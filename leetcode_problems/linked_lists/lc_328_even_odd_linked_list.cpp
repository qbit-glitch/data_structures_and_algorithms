/**
 * Leetcode-328: Even Odd Linked List
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

void printLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArrayToLL(vector<int>& a){
    Node* head = new Node(a[0]);
    Node* temp = head;
    for(int i=1; i<a.size(); i++){
        Node* node = new Node(a[i]);
        temp->next = node;
        temp = node;
    }
    return head;
}


Node* oddEvenList(Node* head){
    if(head == NULL or head->next==NULL or head->next->next==NULL)
        return head;
    Node* odd = head;
    Node* oddHead = odd;
    Node* even = head->next;
    Node* evenHead = even;
    Node* temp = head->next->next;
    while(temp != nullptr and temp->next != nullptr){
        odd->next = temp;
        odd = temp;
        even->next = temp->next;
        even = temp->next;
        if(temp->next==nullptr)
            break;
        temp = temp->next->next;
    }
    if(temp != NULL){
        odd->next = temp;
        odd=temp;
        even->next = NULL;
    }
    odd->next = evenHead;
    return oddHead;
}


int main(){
    vector<int> a{1,2,3,4,5,6,7,8,9};
    Node* head = convertArrayToLL(a);
    head = oddEvenList(head);
    printLL(head);
}