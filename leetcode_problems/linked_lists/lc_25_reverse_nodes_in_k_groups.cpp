/**
 * GFG: Reverse Linked List in groups of Size K
 * Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
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

Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* findKthNode(Node* temp, int k){
    int cnt = 0;
    Node* t = temp;
    while(t != NULL){
        cnt++;
        if(cnt == k)
            break;
        t = t->next;
    }
    return t;
}





/** Some thinking
 * 1. Find Kth Node for each group
 * 2. make the kthNode->next=null but before 
 *      make sure to keep a track of the next node
 * 3. After reversing the group of k nodes, attach the prevNode to the kthNode
 * 4. Make sure to cover the edge cases when 
 *      i. kthNode==NULL  --> means we have the end of list and haven't gotten our kth node
 *      ii. temp==head    --> when it's the very first group in our linked list
*/
Node* reverseKGroup(Node* head, int k){
    Node* temp = head;
    Node* prevNode = nullptr;
    while(temp != NULL){
        Node* kthNode = findKthNode(temp, k);
        if(kthNode == NULL){
            if(prevNode)
                prevNode->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseLL(temp);
        if(temp == head)
            head = kthNode;
        else
            prevNode->next = kthNode;
            
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}


int main(){
    vector<int> a{1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    Node* head = convertArrayToLL(a);
    // Node* head1 = reverseBetweenTwoNodes(head, head->next->next->next->next);
    // printLL(head1);

    Node* head2 = reverseKGroup(head, 5);
    printLL(head2);
    
}
