/**
 * Queue Implementation using linked list
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

class QueueImpl{
    private:
    Node* start = nullptr;
    Node* end = nullptr;

    int size = 0;

    public:
    void push(int x){
        Node* n = new Node(x);
        if(start == nullptr and end == nullptr){
            start = end = n;
        }
        end->next = n;
        end = n;
        size++;
    }

    void pop(){
        if(start == nullptr){
            cout << "Queue is Empty! Cannot pop any value!" << endl;
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
    }

    int top(){
        if(start == nullptr){
            cout << "Queue is Empty! Cannot get any value! returning -1 |> " << endl;
            return -1;
        }
        return start->data;
    }

    int get_size(){
        return size;
    }
};

int main(){
    QueueImpl q;
    q.push(90);
    q.push(80);
    q.push(1);
    q.push(5);

    cout << q.top() << ", " << q.get_size() << endl;

    q.pop();
    q.pop();
    q.pop();


    cout << q.top() << ", " << q.get_size() << endl;
    q.pop();
    q.pop();

    cout << q.top() << ", " << q.get_size() << endl;

}