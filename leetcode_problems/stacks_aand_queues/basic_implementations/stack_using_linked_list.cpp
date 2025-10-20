/**
 * Stack Implementation using Linked List
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

class StackImpl{
    private:
    Node* tp = nullptr;
    int size = 0;

    public:
    void push(int x){
        Node* n = new Node(x, tp);
        tp = n;
        size++;
    }

    void pop(){
        if(tp == nullptr){
            cout << "Stack is empty !" << endl;
            return;
        }
        Node* temp = tp;
        tp = tp->next;
        delete temp;
        size--;
    }

    int top(){
        if(tp == nullptr){
            cout << "Stack is empty ! returning -1 >> " ;
            return -1;
        }
        return tp->data;
    }

    int get_size(){
        return size;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    StackImpl st;
    st.push(9);
    st.push(10);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.top() << endl;
}