/**
 * Description: Doubly Linked List Basic Functions
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

void printDLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head -> next;
    }
    cout << endl;
}

Node* convertArrayToDLL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); i++){
        Node* newNode = new Node(a[i], nullptr, mover);
        mover->next = newNode;
        mover = newNode;
    }
    return head;
}

Node* deleteHead(Node* head){
    if (head == NULL)
        return NULL;
    Node* temp = head;
    head = head -> next;
    temp -> next = nullptr;
    head -> prev = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL)    return NULL;
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* prev = temp -> prev;
    prev -> next = NULL;
    temp -> prev = NULL;
    delete temp;
    return head;
}

Node* deleteKthElement(Node* head, int k){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k)
            break;
        temp =  temp->next;
    }

    Node* prev = temp->prev;
    Node* front = temp->next;

    if(prev == NULL and front == NULL)
        return NULL;
    else if(prev == NULL)
        return deleteHead(head);
    else if(front == NULL)
        return deleteTail(head);
    else{
        prev->next = front;
        front->prev = prev;
        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
}

void deleteGivenNode(Node* node){
    Node* prev = node->prev;
    Node* front = node->next;
    if(front == NULL){
        prev->next = NULL;
        node->prev = NULL;
        delete node;
        return;
    }
    
    prev->next = front;
    front->prev = prev;
    node->prev = nullptr;
    node->next = nullptr;

}


Node* insertBeforeHead(Node* head, int val){
    if(head == NULL)    return new Node(val);
    Node* newNode = new Node(val, head, nullptr);
    head->prev = newNode;
    head = newNode;
    return head;
}

Node* insertBeforeTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* prev = temp->prev;
    Node* newNode = new Node(val, temp, prev);

    prev -> next = newNode;
    temp-> prev = newNode;

    return head;
}

Node* insertBeforeKthPos(Node* head, int val, int k){
    if(k==1)
        return insertBeforeHead(head, val);
    int cnt=0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k)    break;
        temp = temp -> next;
    }
    Node* prev = temp->prev;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->prev = newNode;
    return head;
}

void insertBeforeAGivenNode(Node* node, int val){
    Node* prev = node->prev;
    Node* newNode = new Node(val, node, prev);
    prev -> next = newNode;
    node-> prev = newNode;
}



int main(){
    vector<int> a{1,5,2,7,10,11,90,18};
    Node* head = convertArrayToDLL(a);
    // head = insertBeforeKthPos(head, 100, 8);
    insertBeforeAGivenNode(head->next->next, 10000);
    printDLL(head);
}