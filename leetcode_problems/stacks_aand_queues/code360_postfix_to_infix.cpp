/**
 * Code360: Postfix to Infix Conversion
 * Link: https://www.naukri.com/code360/problems/postfix-to-infix_8382386
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    if((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
        return true;
    return false;
}

string postToInfix(string postfix) {
    stack<string> st;
    for(int i=0; i<postfix.size(); i++){
        if(isOperand(postfix[i]))
            st.push(string(1,postfix[i]));
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push("(" + t2 + postfix[i] + t1 + ")");
        }
    }
    return st.top();
}

int main(){
    string postfix = "ab+c+";
    cout << postToInfix(postfix) << endl; 
}