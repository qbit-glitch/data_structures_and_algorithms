/**
 * Code360: Prefix to Infix
 * Link: https://www.naukri.com/code360/problems/prefix-to-infix_1215000
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    if((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
        return true;
    return false;
}

string prefixToInfixConversion(string& s) {
    stack<string> st;
    for(int i=s.size()-1; i >= 0; i--){
        if(isOperand(s[i]))
            st.push(string(1,s[i]));
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push("(" + t1 + s[i] + t2 + ")");
        }
    }
    return st.top();
}

int main(){
    string s = "/-ab+-cde";
    cout << prefixToInfixConversion(s) << endl; 
}