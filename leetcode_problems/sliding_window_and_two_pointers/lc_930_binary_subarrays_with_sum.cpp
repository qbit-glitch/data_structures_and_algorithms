/**
 * Leetcode-930: Binary Subarrays with Sum
 * Link: https://leetcode.com/problems/binary-subarrays-with-sum/description/
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * goal = 0
 *   0,1,2,3,4
 *  [1,0,1,0,1]
 * l,r
 * 
 * sum = 0
 * cnt = 0
 * 
 * if(sum == goal)
 *      cnt++;
 *      while(a[l] == 0 and l<=r)
 *          cnt++;
 *          
 * while(sum > goal)
 *      sum -= a[l]
 *      l++
 * 
 * map<sum, ind>
 * sum += a[r]
 * 
*/




int numSubarraysWithSumLessEqualGoal(vector<int>& a, int goal) {
    if(goal < 0)
        return 0;
    int l=0, r=0;

    int sum = 0;
    int cnt = 0;
    while(r < a.size()){
        sum += a[r];
        while(sum > goal){
            sum -= a[l];
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    
    return cnt;

}

int numSubarraysWithSum(vector<int> &a, int goal){
    return numSubarraysWithSumLessEqualGoal(a, goal) - numSubarraysWithSumLessEqualGoal(a,goal-1);
}

int main(){
    vector<int> nums {1,0,1,0,1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal) << endl;
}