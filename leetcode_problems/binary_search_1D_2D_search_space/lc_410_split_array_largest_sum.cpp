/**
 * Leetcode-410: Split Array Largest Sum
*/

#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int> &nums, int k);
int calcBucketsRequired(vector<int> &nums, int sum);

int main(){
    vector<int> nums{1,2,3,4,5};
    int k= 2;
    cout << splitArray(nums, k) << endl; 
}


int splitArray(vector<int> &nums, int k){
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high){
        int mid = (low + high)/2;
        int buckets = calcBucketsRequired(nums, mid);

        if(buckets <= k)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}

int calcBucketsRequired(vector<int> &nums, int sum){
    int bucketCnt = 1;
    int bucketSum = 0;

    for(auto &i: nums){
        if (bucketSum + i <= sum)
            bucketSum += i;
        else{
            bucketCnt++;
            bucketSum = i;
        }
    }
    return bucketCnt;
}
