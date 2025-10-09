/**
 * Leetcode-78: Subsets
*/

#include <bits/stdc++.h>
using namespace std;

void findSubsequences(int idx, vector<int> &instance, vector<vector<int>> &result, vector<int>& nums, int n){
    if(idx >= n){
        result.push_back(instance);
        return;
    }
    // pick the element to be included in the subsequence
    instance.push_back(nums[idx]);
    findSubsequences(idx+1, instance, result, nums, n);

    // do not pick the element for the subsequence
    instance.pop_back();
    findSubsequences(idx+1, instance, result, nums, n);
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> instance{};
    findSubsequences(0, instance, result, nums, nums.size());
    return result;
}


void printVectors(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<int> nums{1,2,3,4};
    auto res = subsets(nums);
    printVectors(res);
}