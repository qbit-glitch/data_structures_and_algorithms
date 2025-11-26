/**
 * Leetcode-45: Jump Game - II
 * Link: https://leetcode.com/problems/jump-game-ii/description/
*/

#include <bits/stdc++.h>
using namespace std;

int fn_r(vector<int> &nums, int ind, int cnt){
    if(ind >= nums.size()-1)
        return cnt;

    if(nums[ind] == 0)
        return INT_MAX;
    
    int mini = nums.size() + 1;
    for(int i=1; i <= nums[ind]; i++){
        mini = min(mini, fn_r(nums, ind+i, cnt+1));
    }
    // cout << mini << endl;
    return mini;
}

int jump_rec(vector<int>& nums) {
    int cnt = 0, ind = 0;
    return fn_r(nums, ind, cnt);
}


int jump(vector<int>& nums){
    int jumps = 0, l=0, r=0;
    while(r < nums.size()-1){
        int farthest = 0;
        for(int i=l; i<=r; i++){
            farthest = max(farthest, i+nums[i]);
        }
        l = r+1;
        r = farthest;
        jumps ++;
    }
    return jumps;
}




int main(){
    vector<int> nums{2,3,1,1,4};
    cout << jump(nums) << endl;
}

