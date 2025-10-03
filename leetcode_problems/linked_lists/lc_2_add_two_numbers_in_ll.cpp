/**
 * Leetcode-2 : Add 2 numbers in Linked List
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

/** Thought Process:
 * 1. Traverse both the list simultaneously with carry = 0 initially
 * 2. When any one of the pointers to the list becomes null, take zero for that pointer->data
 * 3. Rest everything is basic addition principles
*/

Node* addTwoNumbers(Node* headA, Node* headB){

    int carry = 0;
    Node* result = new Node(-1);
    Node* rHead = result;

    Node* tempA = headA;
    Node* tempB = headB;

    while(tempA != NULL or tempB != NULL){
        int sum = ((tempA)?tempA->data:0) + ((tempB)?tempB->data:0) + carry;
        if(sum > 9){
            sum = sum - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        Node* node = new Node(sum);
        result->next = node;

        tempA = (tempA)?tempA->next:nullptr;
        tempB = (tempB)?tempB->next:nullptr;
        result = result->next;
    }
    if(carry == 1){
        Node* n = new Node(1);
        result->next = n;
    }
    Node* t = rHead;
    rHead =  rHead->next;
    delete t;
    return rHead;
}


int main(){
    vector<int> a{9,9,9,9,9,9,9};
    vector<int> b{9,9,9,9};
    Node* headA = convertArrayToLL(a);
    Node* headB = convertArrayToLL(b);
    headA = addTwoNumbers(headA, headB);
    printLL(headA);
}