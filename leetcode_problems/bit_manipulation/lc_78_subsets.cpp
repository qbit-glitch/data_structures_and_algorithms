/**
 * Leetcode-78: Subsets
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int subs = (1 << nums.size());
    vector<vector<int>> res{};
    for(int i=0; i<subs; i++){
        vector<int> list{};
        for(int j = 0; j<nums.size(); j++){
            if(i & (1 << j))
                list.push_back(nums[j]);
        }
        res.push_back(list);
    }
    return res;
}

void printVectors(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<int> a{1,2,3,4};
    vector<vector<int>> result = subsets(a);
    printVectors(result);
}