/**
 * Leetcode-148: Sort List
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

/**
 * Use Tortoise and Hare Algo
 * 1. move slow by 1 steps and fast by 2 steps
 * 2. stop when fast->next = NULL
*/

Node* findMiddle(Node* head){
    if(head==NULL or head->next==NULL)
        return nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL and fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
 * Merge Two Sorted List - perform merge function on linked list
 * 
*/
Node* merge2SortedLists(Node* left, Node* right){
    Node* dummyHead = new Node(-1);
    Node* temp = dummyHead;

    while(left != NULL and right!=NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp=left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left) temp->next = left;
    else    temp->next = right;
    return dummyHead->next;
}


/**
 * Implement Merge Sort for sorting
 * 1. Find Middle element
 * 2. sort(head, middle)
 * 3. sort(middle+1, end)
 * 4. merge(sort1, sort2) lists
*/
Node* sortList(Node* head){
    if(head==NULL or head->next==NULL)
        return head;
    
    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = nullptr;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    Node* newHead = merge2SortedLists(leftHead, rightHead);

    return newHead;
}






int main(){
    vector<int> a{11,5,0,10,2,20,60,8};
    
    Node* headA = convertArrayToLL(a);

    headA = sortList(headA);
    // head = reverseList(head);
    // head = findMiddle(head);

    printLL(headA);
}