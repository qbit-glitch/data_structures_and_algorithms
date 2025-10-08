/**
 * GFG: Reverse Stack using recursion
 * Link: https://www.geeksforgeeks.org/problems/reverse-a-stack/1
*/



#include <bits/stdc++.h>
using namespace std;



void revStack(stack<int>& st, stack<int>& temp){
    if(st.empty())
        return;
    int n = st.top();
    st.pop();
    
    temp.push(n);
    revStack(st, temp);    
}

void reverseStack(stack<int> &st){
    stack<int> temp;
    revStack(st, temp);
    st = temp;
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

    reverseStack(st);
    printStack(st);
}
