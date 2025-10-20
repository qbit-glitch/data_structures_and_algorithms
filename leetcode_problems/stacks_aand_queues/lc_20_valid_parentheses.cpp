/**
 * Leetcode-20: Valid Parentheses
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mpp = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
    for(char &c: s){
        if(!st.empty() and mpp.find(c) != mpp.end() and mpp[c] == st.top()){
            st.pop();
            continue;
        }
        st.push(c);

    }

    if(st.empty())
        return true;
    return false;
}

int main(){
    string s = "()";
    cout << isValid(s) << endl;
}