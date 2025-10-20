/**
 * Leetcode-155: Min Stack
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack{
    private:
    stack<long long> st;
    long long mini = INT64_MAX;

    public:
    MinStack(){

    }

    void push(long long x){
        if(st.empty()){
            mini = x;
            st.push(x);
        }
        else {
            if(x > mini)    st.push(x);
            else{
                st.push(2*x - mini);
                mini = x;
            }
        }
    }

    void pop(){
        if(st.empty()){
            cout << "Stack is empty! Cannot pop .." << endl;
            return;
        }
        long long x = st.top();
        st.pop();

        if(mini > x)
            mini = 2*mini - x;
    }

    long long top(){
        if(st.empty()){
            cout << "Stack is empty! Returning -1 |>" << endl;
            return -1;
        }
        long long x = st.top();
        if(mini < x){
            return x;
        }
        return mini;
    }

    long long getMin(){
        return mini;
    }
};

int main(){
    MinStack st;
    st.push(10);
    st.push(20);
    st.push(9);
    st.push(12);

    cout << st.top() << "," << st.getMin() << endl;
    
    st.pop();
    cout << st.top() << "," << st.getMin() << endl;

    st.pop();
    cout << st.top() << "," << st.getMin() << endl;
}