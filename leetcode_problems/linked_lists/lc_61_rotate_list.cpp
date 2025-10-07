/**
 * Leetcode-61: Rotate list
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

int listLength(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}



Node* findKthNode(Node* temp, int k){
    Node* t = temp;
    int cnt = 0;
    while(t != NULL){
        cnt++;
        if(cnt == k)
            break;
        t = t->next;
    }
    return t;
}

/**
 * 1. Find the kth Node
 * 2. Find the distance between the kth Node and the end node
 * 3. Bring the end node to the front
 * 4. Make the kth node point to nULL
*/

Node* rotateRight(Node* head, int k){
    Node* h1 = head;
    int l = listLength(head);
    if(k == 0 or head == nullptr or head->next == nullptr)
        return head;
    k = l - k % l;
    
    Node* kthNode = findKthNode(head, k);
    Node* nextNode = kthNode->next;

    kthNode->next = nullptr;
    Node* temp = nextNode;

    while(temp != nullptr and temp->next != nullptr){
        temp = temp->next;
    }
    // check whether we have k = Length and have reached the end of the LL
    if(temp != nullptr)
        temp->next = head;
    else
        nextNode = head;

    return nextNode;
}









int main(){
    vector<int> a{1,2,3,4,5};
    Node* head = convertArrayToLL(a);

    Node* head2 = rotateRight(head, 2);
    printLL(head2);
    
}
