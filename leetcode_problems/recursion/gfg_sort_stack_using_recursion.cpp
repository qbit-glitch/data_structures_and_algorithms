/**
 * GFG: Sort Stack Using Recursion
*/

#include <bits/stdc++.h>
using namespace std;


void sortedInsert(stack<int> &st, int k){
    if(st.empty() or (!st.empty() and st.top() < k)){
        st.push(k);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st, k);

    st.push(n);
}

void sortStack(stack<int>& st){
    if(st.empty())
        return;
    int n = st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st, n);
}


stack<int> convertArrayToStack(vector<int> &a){
    stack<int> st;
    for(auto &i: a){
        st.push(i);
    }
    return st;
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    vector<int> a{41,3,32,11,-9,19};
    stack<int> st = convertArrayToStack(a);
    printStack(st);
    sortStack(st);
    printStack(st);
}