/**
 * Leetcode-225: Implement Stack using Queue
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {

private:
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int s = q.size();
        for(int i=1; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()){
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int el = q.front();
        q.pop();
        return el;
    }
    
    int top() {
        if(q.empty()){
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        if(q.size() == 0)
            return true;
        else    return false;
    }

    int size(){
        return q.size();
    }
};

int main(){
    MyStack st;
    st.push(1);
    st.push(2);

    cout << st.top() << ", " << st.size() << endl;
    st.pop();
    cout << st.top() << ", " << st.size() << endl;
    st.pop();
    cout << st.top() << ", " << st.size() << endl;
    
}
