/**
 * GFG: Delete all occurances of a Key in Doubly Linked List
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertArrayToDLL(vector<int> &a){
    if(a.size() == 0)
        return nullptr;
    Node* head = new Node(a[0]);
    Node* temp = head;

    for(int i=1; i<a.size(); i++){
        Node* n = new Node(a[i], nullptr, temp);
        temp->next = n;
        temp = temp->next;
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* deleteAllOccurOfX(Node* head, int x){
    Node* temp = head;
    Node* t;
    while(temp != NULL){
        if(temp->data == x){
            if(temp == head){
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if(nextNode)
                nextNode->prev = prevNode;
            if(prevNode)
                prevNode->next = nextNode;
            
            delete temp;
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }  
    }
    return head;
}




int main(){
    vector<int> a{10,4,10,2,3,20,10};
    Node* head = convertArrayToDLL(a);
    head = deleteAllOccurOfX(head, 10);
    printDLL(head);
}