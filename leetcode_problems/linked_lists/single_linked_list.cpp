/**
 * A2Z DSA: Single Linked List
 * Link: https://youtu.be/Nq7ok-OyEpg
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayToSLL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); i++){
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    if(head == nullptr)
        return 0;
    Node* mover = head;
    int cnt = 1;
    while(mover->next != nullptr){
        cnt++;
        mover = mover->next;
    }
    return cnt;
}

bool checkIfPresent(Node* head, int target){
    if(head == nullptr)
        return false;
    Node* mover = head;
    while(mover != nullptr){
        if(mover->data == target)
            return true;
        mover = mover->next;
    }
    return false;
}


int main(){
    cout << "Hello Single LL" << endl;
    Node* node1 = new Node(17);
    Node* node2 = new Node(18, node1);
    cout << node1->data << endl;
    cout << node2->data << " " << node2->next->data << endl;

    vector<int> a {5,3,8,1,0,7,10};
    Node* a2L_head = convertArrayToSLL(a);
    cout << a2L_head->next->data << endl;

    cout << lengthOfLL(a2L_head) << endl;

    cout << checkIfPresent(a2L_head, 20) << endl;
}