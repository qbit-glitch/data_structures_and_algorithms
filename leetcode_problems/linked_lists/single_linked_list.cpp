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



int main(){
    cout << "Hello Single LL" << endl;
    Node* node1 = new Node(17);
    Node* node2 = new Node(18, node1);
    cout << node1->data << endl;
    cout << node2->data << " " << node2->next->data << endl;
}