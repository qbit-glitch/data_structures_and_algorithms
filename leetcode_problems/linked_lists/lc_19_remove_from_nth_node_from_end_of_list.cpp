/**
 * Leetcode-19: Remove From Nth node from end of List
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
    if(head == NULL) cout << "NULL" << endl;
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

/**
 * 1. reverse the list
 * 2. forward traversal with new head to nth node
 * 3. reverse the list again to get back the original head
*/

Node* reverseList(Node* head){
    if(head == NULL or head->next==NULL)
        return head;
    Node* temp = head;
    Node* back = nullptr;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next =  back;
        back = temp;
        temp = front;
    }
    head = back;
    return head;
}

Node* removeNthFromEnd(Node* head, int n){
    if(head == NULL)   return nullptr;
    if(head->next == NULL and n==1)
        return nullptr;
    
    head = reverseList(head);
    if(n==1){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    else {
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            cnt++;
            if(cnt == n-1){
                Node* front = temp->next->next;
                Node* t = temp->next;
                temp->next = front;
                free(t);
            }
            temp = temp->next;
        }
    }
    head = reverseList(head);
    return head;
}


int main(){
    vector<int> a{1};
    Node* head = convertArrayToLL(a);
    // head = reverseList(head);
    head = removeNthFromEnd(head, 1);
    printLL(head);
}