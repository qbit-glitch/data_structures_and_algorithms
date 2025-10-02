/**
 * GFG: Sort Linked List of 0s, 1s, 2s
 * Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
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

Node* segregate(Node* head){
    if(head == NULL or head->next==NULL)
        return head;
    Node* zero = new Node(-1);
    Node* one = new Node(-1);
    Node* two = new Node(-1);

    Node* zeroHead = zero;
    Node* oneHead = one;
    Node* twoHead = two;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next)? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    head = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}


int main(){
    vector<int> a{1,0,2,1,1,0,0,0,2};
    
    Node* headA = convertArrayToLL(a);

    headA = segregate(headA);

    printLL(headA);
}