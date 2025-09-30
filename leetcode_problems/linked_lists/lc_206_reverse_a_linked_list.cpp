/**
 * Leetcode-206: Reverse a Linked List
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

Node* converArrayToLL(vector<int>& a){
    Node* head = new Node(a[0]);
    Node* temp = head;
    for(int i=1; i<a.size(); i++){
        Node* newNode = new Node(a[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void printLL(Node* head){
    while(head != nullptr){
        cout << head -> data << " " ;
        head = head->next;
    }
    cout << endl;
}

Node* reverseList(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!= nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* reverseList_Better(Node* head){
    if (head->next == NULL)
        return head;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!= NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* reverseList_Recursive(Node* head){
    if(head == NULL or head->next == NULL)
        return head;
    
    Node* newHead = reverseList_Recursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}



int main(){
    vector<int> a{4,9,10,11,18,91};
    Node* head = converArrayToLL(a);
    head = reverseList_Recursive(head);
    printLL(head);
}