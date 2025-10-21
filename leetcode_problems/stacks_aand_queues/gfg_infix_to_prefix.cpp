/**
 * GFG: Infix to Prefix
 * Link: https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1
*/

#include <bits/stdc++.h>
using namespace std;

string reverseTheString(string &s){
    string s1=""; 
    int n = s.size();
    for(int i=n-1; i >= 0; i--){
        if(s[i] == '(')
            s1 += ')';
        else if(s[i] == ')')
            s1 += '(';
        else
            s1 += s[i];
    }
    return s1;
}

bool isOperand(char c){
    if((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
        return true;
    return false;
}

int priority(char c){
    if(c == '^')
        return 3;
    else if(c == '*' or c == '/')
        return 2;
    else if(c == '+' or c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string &s) {
    s = reverseTheString(s);
    int i = 0;
    stack<char> st;
    string ans = "";

    while(i < s.size()){
        if(isOperand(s[i]))
            ans += s[i];
        else if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')'){
            while(!st.empty() and st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if(s[i] == '^'){
                while(!st.empty() and (priority(s[i]) <= priority(st.top()))){
                    ans += st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() and (priority(s[i]) < priority(st.top()))){
                    ans += st.top();
                    st.pop();
                }
                
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPrefix(s) << endl;
}