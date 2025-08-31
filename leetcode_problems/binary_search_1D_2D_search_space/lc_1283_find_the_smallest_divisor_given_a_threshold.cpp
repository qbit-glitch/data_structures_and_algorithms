/**
 * Leetcode-1283: Find the Smallest Divisor given the threshold
*/

#include <bits/stdc++.h>
using namespace std;

int findSum(vector<int> &nums, int d){
    int total = 0;
    for(auto &i: nums){
        total += ceil((double)i/(double)d);
    }
    return total;
}

int findMax(vector<int> &nums){
    int maxEl = nums[0];
    for(auto &i: nums){
        maxEl = max(i, maxEl);
    }
    return maxEl;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = findMax(nums);
    int ans;
    while(low <= high){
        int mid = (low+high)/2;
        if(findSum(nums, mid) <= threshold)
        {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> a{1,2,5,9};
    cout << smallestDivisor(a, 5) << endl;
}