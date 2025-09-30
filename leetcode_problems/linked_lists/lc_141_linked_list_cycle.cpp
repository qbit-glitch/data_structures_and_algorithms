/**
 * Leetcode-141: Linked List Cycle
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

bool hasCycle(Node* head){
    if(head == NULL or head->next==NULL or head->next->next==NULL)
        return false;
    Node* step = head;
    Node* two_steps = step;
    while(two_steps!=NULL and two_steps->next != NULL){
        step = step->next;
        two_steps = two_steps->next->next;
        if(step == two_steps)
            return true;
    }
    return false;
}

Node* buildCLL(Node* head, Node* node){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return head;
}





int main(){
    vector<int> a{4,9,10};
    Node* head = converArrayToLL(a);
    head = buildCLL(head, head->next->next);
    
    cout << hasCycle(head) << endl;
}