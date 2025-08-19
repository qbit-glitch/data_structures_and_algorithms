/**
 * Leetcode-560: Subarray sum equals k
*/

#include <bits/stdc++.h>
using namespace std;

int subArraySum(vector<int> &nums, int k){
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum=0, cnt=0;
    for(int i=0;i <nums.size();i++){
        preSum += nums[i];
        int rem = preSum-k;
        if(mpp.find(rem) != mpp.end()){
            cnt += mpp[rem];
        }
        mpp[preSum]++;
    }
    return cnt;
}

int main(){
    vector<int> a{1,2,1,2,1};
    cout << subArraySum(a, 3) << endl;
}