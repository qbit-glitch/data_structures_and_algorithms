/**
 * GFG: Add 1 to a Linked List Number
 * Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
 * 
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

Node* reverseList(Node* head){
    Node* back = nullptr;
    Node* temp = head;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = back;
        back = temp;
        temp = front;
    }
    head = back;
    return head;
}

Node* addOne(Node* head){
    if(head == NULL)
        return head;
    Node* revHead = reverseList(head);
    Node* temp = revHead;
    int carry = 1;
    
    Node* prev = temp;
    while(temp!= NULL){
        if(carry == 1){
            temp->data = temp->data + 1;
            carry = 0;
        }

        if(temp->data > 9){
            carry = 1;
            temp -> data = 0;
        }
        else {
            carry = 0;
        }
        prev = temp;
        temp = temp->next;
    }

    if(carry == 1){
        Node* node = new Node(1);
        prev->next = node;
    }
    head = reverseList(revHead);
    return head;
}




int main(){
    vector<int> a{1,9,9,1};
    
    Node* headA = convertArrayToLL(a);
    headA = addOne(headA);
    printLL(headA);
}