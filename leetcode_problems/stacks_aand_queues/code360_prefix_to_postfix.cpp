/**
 * Code360: Prefix to Postfix
 * Link: https://www.naukri.com/code360/problems/convert-prefix-to-postfix_8391014
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    if((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
        return true;
    return false;
}

string preToPost(string& s) {
    stack<string> st;
    for(int i=s.size()-1; i >= 0; i--){
        if(isOperand(s[i]))
            st.push(string(1,s[i]));
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push(t1 + t2 + s[i]);
        }
    }
    return st.top();
}

int main(){
    string s = "/A+BC";
    cout << preToPost(s) << endl; 
}