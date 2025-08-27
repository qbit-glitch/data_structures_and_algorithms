/**
 * Leetcode-153: Maximum Product Subarray
*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int pref=1, suf=1, n=nums.size();
    int maxP = INT_MIN;
    for(int i=0; i<n; i++){
        if(pref == 0)   pref=1;
        if(suf == 0)    suf=1;
        pref *= nums[i];
        suf *= nums[(n-1)-i];
        maxP = max(pref, max(suf, maxP));
        
    }
    return maxP;
}

int main(){
    vector<int> a{2,4,-2,1,3,9};
    cout << maxProduct(a) << endl;
}