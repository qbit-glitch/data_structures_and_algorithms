/**
 * Leetcode-402: Remove K digits
 * Link: https://leetcode.com/problems/remove-k-digits/description/
*/

#include <bits/stdc++.h>
using namespace std;



/** Thought Process:
 * 1. Keep smaller digits at the start
 * 2. Get rid of the larger ones
*/
string removeKdigits(string a, int k) {
    if(k == a.size())
        return "0";
    stack<char> st;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() and k>0 and (st.top()-'0') > (a[i]-'0')){
            st.pop();
            k--;
        }
        st.push(a[i]);
    }    

    while(k > 0){
        st.pop();
        k--;
    }

    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    while(!ans.empty() and ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());

    if(ans.empty())     return "0";
    return ans;
}

int main(){
    string a = "1432219";
    cout << removeKdigits(a, 3) << endl;
}