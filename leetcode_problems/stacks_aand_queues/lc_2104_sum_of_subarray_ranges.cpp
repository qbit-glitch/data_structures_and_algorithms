/**
 * Leetcode-2104: Sum of Subarray ranges
 * Link: https://leetcode.com/problems/sum-of-subarray-ranges/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int> &a){
    vector<int> ans(a.size(),0);
    stack<int> st;
    for(int i=a.size()-1; i>=0; i--){
        while(!st.empty() and a[st.top()] >= a[i])
            st.pop();
        ans[i] = st.empty() ? a.size() : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findPSEE(vector<int> &a){
    vector<int> ans(a.size(), 0);
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() and a[st.top()] > a[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}


vector<int> findNGE(vector<int> &a){
    vector<int> ans(a.size(),0);
    stack<int> st;
    for(int i=a.size()-1; i>=0; i--){
        while(!st.empty() and a[st.top()] <= a[i])
            st.pop();
        ans[i] = st.empty() ? a.size() : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findPGEE(vector<int> &a){
    vector<int> ans(a.size(), 0);
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() and a[st.top()] < a[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}


/** Thought Process:
 * 1. Find the sumOfSubArrayMins(a)
 * 2. Find sumOfSubArrayMaxs(a)
 * 3. return the difference of the above two
 */
long long subArrayRanges(vector<int>& a) {
    vector<int> psee = findPSEE(a);
    vector<int> nse = findNSE(a);
    vector<int> pgee = findPGEE(a);
    vector<int> nge = findNGE(a);
    int sTotal = 0, gTotal = 0;

    for(int i=0; i<a.size(); i++){
        int sLeft = i - psee[i];
        int sRight = nse[i] - i;
        sTotal += (sLeft * sRight * 1ll * a[i]);
        
        int gLeft = i - pgee[i];
        int gRight = nge[i] - i;
        gTotal += (gLeft * gRight * 1ll * a[i]);
    }

    return (gTotal - sTotal);
}

int main(){
    vector<int> a{1,3,3};
    cout << subArrayRanges(a) << endl;
}