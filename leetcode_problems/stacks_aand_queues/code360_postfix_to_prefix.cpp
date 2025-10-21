/**
 * Code360: Postfix to Prefix Conversion
 * Link: https://www.naukri.com/code360/problems/postfix-to-prefix_1788455
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    if((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
        return true;
    return false;
}

string postfixToPrefix(string& s) {
    stack<string> st;
    for(int i=0; i<s.size(); i++){
        if(isOperand(s[i]))
            st.push(string(1,s[i]));
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push(s[i] + t2 + t1);
        }
    }
    return st.top();
}

int main(){
    string s = "abc*+";
    cout << postfixToPrefix(s) << endl; 
}