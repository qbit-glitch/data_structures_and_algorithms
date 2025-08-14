/**
 * GFG: Longest subarray with sum K
 * 
 * Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

    Examples:

    Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
    Output: 6
    Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

    Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
    Output: 5
    Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

    Input: arr[] = [10, -10, 20, 30], k = 5
    Output: 0
    Explanation: No subarray with sum = 5 is present in arr[].

    Constraints:
    1 ≤ arr.size() ≤ 105
    -104 ≤ arr[i] ≤ 104
    -109 ≤ k ≤ 109
*/



#include <bits/stdc++.h> 
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    map<int, int> hashmap = {{0,-1}};
    int prefix_sum = 0;
    int maxLen = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        
        prefix_sum += nums[i];
        
        hashmap.insert({prefix_sum, i});

        if(hashmap[prefix_sum - k] == true){
            int l = i - hashmap[prefix_sum - k];
            cout << l << endl;
            if(l > maxLen){
                maxLen = l;
            }
        }
    }
    return maxLen;
}

int main(){
    vector<int> a{1,2,3,1,1,1,1,4,2,3};
    cout << getLongestSubarray(a, 3) << endl;
}