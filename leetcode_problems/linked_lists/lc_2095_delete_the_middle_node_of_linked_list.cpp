/**
 * Leetcode-2095: Delete the middle node of the linked list
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
 * Use Tortoise and Hare Algo
 * 1. move slow by 1 steps and fast by 2 steps
 * 2. stop when fast->next = NULL
*/
// Node* deleteMiddle(Node* head){
//     if(head==NULL or head->next==NULL)
//         return nullptr;
//     Node* slow=head;
//     Node* fast = head;

//     while(fast != NULL and fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     Node* middle = slow;
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp ->next == middle)
//             break;
//         temp = temp->next;
//     }
//     temp->next = middle->next;
//     delete middle;
//     return head;
// }

Node* deleteMiddle(Node* head){
    if(head==NULL or head->next==NULL)
        return nullptr;

    Node* slow=head;
    Node* fast = head;
    fast = head->next->next;

    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}




int main(){
    vector<int> a{1,2,3,4,5,6,7,8};
    Node* head = convertArrayToLL(a);
    // head = reverseList(head);
    head = deleteMiddle(head);
    printLL(head);
}