/**
 * Leetcode-232: Implement Queue using stacks
*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;


public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int el =  s2.top();
        s2.pop();
        return el;
    }
    
    int peek() {

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
    
    bool empty() {
        return (s1.empty() and s2.empty());
    }
};

int main(){
    MyQueue q;
    q.push(9);
    q.push(8);
    q.push(7);
    q.push(6);
    q.push(5);

    cout << q.peek() << endl;
    q.pop();
    q.pop();
    q.pop();

    cout << q.peek() << endl;
    
}
