/**
 * Leetcode-907: Sum of Subarray Minimums
 * Link: https://leetcode.com/problems/sum-of-subarray-minimums/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int> &a){
    vector<int> nse(a.size(), 0);
    stack<int> st;
    for(int i=a.size()-1; i>=0; i--){
        while(!st.empty() and a[st.top()] >= a[i])
            st.pop();
        nse[i] = st.empty() ? a.size() : st.top();
        st.push(i); 
    }
    return nse;
}

vector<int> findPSEE(vector<int> &a){
    vector<int> psee(a.size(), 0);
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() and a[st.top()] > a[i])
            st.pop();
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

/** Thought Process:
 * 1. Subarrrays which can have contribution of a[i] as minimum:
 *      - is upto NSE of a[i] on the right
 *      - is upto PSEE of a[i] on the left
 * 2. Therefore total contribution:
 *     #number of subarrays which have a[i] as min = (nse[i] - i) * (i - psee[i])
 *     totalContrbution += #number of contributions * a[i] 
*/
int sumSubarrayMins(vector<int>& a) {
    vector<int> nse = findNSE(a);
    vector<int> psee = findPSEE(a);
    long long total = 0;
    int mod = (int)(1e9+7);

    for(int i=0; i<a.size(); i++){
        int leftSub = nse[i] - i;
        int rightSub = i - psee[i]; 
        total = (total + (leftSub * rightSub * 1ll * a[i])%mod) % mod;
    }
    return total;
}

int main(){
    vector<int> a{3,1,2,4};
    cout << sumSubarrayMins(a) << endl;
}