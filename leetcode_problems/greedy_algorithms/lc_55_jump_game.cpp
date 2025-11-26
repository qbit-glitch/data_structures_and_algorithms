/**
 * Leetcode-55: jump Game
 * Link: https://leetcode.com/problems/jump-game/
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * [3,2,1,0,4]
 * []
 * 
 */


bool canJump(vector<int>& nums) {
    if(nums[0] == 0)
        return false;
    int maxIndex = 0;
    for(int i=0; i<nums.size(); i++){
        if(i > maxIndex)
            return false;
        maxIndex = max(maxIndex, i+nums[i]);
    }    
    return true;
}

int main(){
    vector<int> nums {1,2,3,1,1,0,2,5};
    cout << canJump(nums) << endl;
}