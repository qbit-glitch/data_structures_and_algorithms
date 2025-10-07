/**
 * Code360: Flatten a Linked List
 * Link: https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(){
        data = 0;
        next = nullptr;
        child = nullptr;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
    }

    Node(int data1, Node* next1, Node* child1){
        data = data1;
        next = next1;
        child = child1;
    }
};


// Node* convertArrayToListOfLL(vector<vector<int>>& a){
//     if(a.size() == 0)
//         return nullptr;
//     Node* head = new Node(a[0][0]);
    
//     Node* temp = head;
//     Node* te = nullptr;
//     for(int i=0; i<a.size(); i++){
//         if(i != 0)
//             te = new Node(a[i][0]);
//         temp->next = te;
//         temp = te;
//         for(int j=0; j<a[i].size(); j++){
//             Node* t = new Node(a[i][j]);
//             temp->child = t;
//             temp = t;
//         }
//     }
//     return head;
// }

Node* convertArrayToListOfLL(vector<vector<int>>& a) {
    if (a.empty()) return nullptr;

    Node* head = nullptr;
    Node* prevRow = nullptr;

    for (int i = 0; i < a.size(); i++) {
        // Build the child list for this row
        Node* childHead = new Node(a[i][0]);
        Node* childTail = childHead;

        for (int j = 1; j < a[i].size(); j++) {
            childTail->child = new Node(a[i][j]);
            childTail = childTail->child;
        }

        if (!head) head = childHead;
        else prevRow->next = childHead;

        prevRow = childHead;
    }

    return head;
}




// void printListOfLL(Node* head){
//     Node* temp = head;
//     if(head == NULL)
//         return; 
//     while(temp != NULL){
//         Node* te = temp->child;
//         while(te != NULL)
//         {    
//             cout << te->data << " " << endl;
//             te = te->child;
//         }
//         temp = temp->next;
//     }
// }

void printListOfLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        Node* te = temp->child;
        while (te != nullptr) {
            cout << te->data << " ";
            te = te->child;
        }
        cout << endl;
        temp = temp->next;
    }
}


Node* merge(Node* list1, Node* list2){
    Node* dummyHead = new Node(-1);
    Node* t1 = list1;
    Node* t2 = list2;

    Node* res = dummyHead;

    while(t1!=NULL and t2!=NULL){
        if(t1->data < t2->data){
            res->child = t1;
            res = t1;
            t1 = t1->child;
        }
        else {
            res->child = t2;
            res = t2;
            t2 = t2->child;
        }
        res->next = NULL;
    }
    if(t1) res->child = t1;
    else  res->child = t2;
    if(dummyHead->child)
        dummyHead->child->next = nullptr;
    return dummyHead->child;
}


Node* flattenLinkedList(Node* head){
    if(head == NULL or head->next==NULL)
        return head;

    Node* mergedHead = flattenLinkedList(head -> next);
    Node* newHead = merge(head, mergedHead);
    return newHead;
}


int main(){
    vector<vector<int>> a{{1,2},{4,5,6,7},{8,9,10}};
    Node* head = convertArrayToListOfLL(a);
    Node* head2 = flattenLinkedList(head);
    printListOfLL(head2);
}