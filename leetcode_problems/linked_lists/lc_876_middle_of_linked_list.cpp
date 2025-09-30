/**
 * Leetcode-876: Middle Of Linked List 
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

Node* middleOfLL(Node* head){
    Node* temp = head;
    int cnt=0;
    while(temp != nullptr){
        cnt++;
        temp = temp-> next;
    }

    int mid = cnt/2+1;

    temp = head; cnt=0;
    while(temp != nullptr){
        cnt++;
        if(cnt==mid)    break;
        temp = temp-> next;
    }
    return temp;
}


int main(){
    vector<int> a{4,9,10,11,18,91};
    Node* head = converArrayToLL(a);
    head = middleOfLL(head);
    printLL(head);
}