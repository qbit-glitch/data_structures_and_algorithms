/**
 * Leetcode-18: 4 Sum
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum_Optimal(vector<int> &nums, int target){
    vector<vector<int>> ls;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(i > 0 and nums[i] == nums[i-1])
            continue;

        for(int j=i+1; j<n; j++){
            if(j > i+1 and nums[j] == nums[j-1]) continue;

            int k = j+1, l=n-1;
            while(k < l){
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if(sum > target)
                    l--;
                else if(sum < target)
                    k++;
                else {
                    ls.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;
                    cout << k << " " << l << endl;
                    while(k < l and nums[k] == nums[k-1])   k++;
                    while(k < l and nums[l] == nums[l+1])   l--;
                }
            }
        }
    }
    return ls;
}

void printVector(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<int> a{2,2,2,2,2};
    auto ans = fourSum_Optimal(a,8);
    printVector(ans);
}