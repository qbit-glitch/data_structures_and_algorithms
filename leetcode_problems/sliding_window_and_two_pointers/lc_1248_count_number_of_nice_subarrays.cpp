/**
 * Leetcode-1248: Count Number of Nice Subarrays
 * Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * Given an array of integers nums and an integer k. 
 * A continuous subarray is called nice if there are k odd numbers on it.
 * Return the number of nice sub-arrays.
*/

// Function to find Number of Subarrays with Odds <= k
int subarraysOddsLessThanEqualToCnt(vector<int>& nums, int k) {
    if(k < 0)
        return 0;
    int l=0, r=0, cnt=0, oddCnt=0;
    while(r < nums.size()){
        if(nums[r]%2==1)
            oddCnt++;
        while(oddCnt > k){
            if(nums[l]%2 == 1)
                oddCnt--;
            l++;
        }
        cnt += r-l+1;
        cout << l << "," << r << endl;
        r++;

    }    
    return cnt;
}


/** Thought Process: 
 * Ans = (number of Subarrays with Odds <= k) - (number of subarrays with odds <= k-1) 
*/
int numberOfSubarrays(vector<int> nums, int k){
    return subarraysOddsLessThanEqualToCnt(nums, k) - subarraysOddsLessThanEqualToCnt(nums, k-1);
}

int main(){
    vector<int> a{2,4,6};
    int k=1;
    cout << numberOfSubarrays(a, k) << endl;
}