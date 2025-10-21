/**
 * Code360: Infix to Postfix Conversion
 * Link: https://www.naukri.com/code360/problems/infix-to-postfix_1382146?leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h>
using namespace std;


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

string infixToPostfix(string& s) {
    stack<char> st;
    string ans = "";
    int i=0;
    
    while(i < s.size()){
        if(isOperand(s[i]))
            ans += s[i];
        
        else if(s[i] == '(')
            st.push(s[i]);
        
        else if(s[i] == ')'){
            while(!st.empty() and st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while(!st.empty() and (priority(s[i]) <= priority(st.top()))){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string s = "(a+b)*(c+d)";
    string ans = infixToPostfix(s);
    cout << ans << endl;
}