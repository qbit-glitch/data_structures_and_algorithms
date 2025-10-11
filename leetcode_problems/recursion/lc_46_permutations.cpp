/**
 * Leetcode-46: Permutations 
*/

#include <bits/stdc++.h>
using namespace std;


/*-------------------- APPROACH 1 : using external map/array --------------*/

void func(vector<int> &ds, vector<vector<int>> &result, vector<int> &nums, unordered_map<int, int> mpp){
    if(ds.size() == nums.size()){
        result.push_back(ds);
        return;
    }

    for(int i=0; i<nums.size(); i++){
        if(!mpp[nums[i]]){
            ds.push_back(nums[i]);
            mpp[nums[i]] = 1;
            func(ds, result, nums, mpp);
            ds.pop_back();
            mpp[nums[i]] = 0;
        }
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result; 
    vector<int> ds;
    
    unordered_map<int, int>  mpp;
    for(int &i: nums){
        mpp[i] = 0;
    }

    func(ds, result, nums, mpp);
    return result;
}

/* ------------------------ APPROACH I - ends --------------------------------- */




/*--------- APPROACH II - using swapping and pointer to track indexes ---------*/

void funcRecur_Optimal(int ind, vector<int> &nums, vector<vector<int>> &result){
    if(ind == nums.size())
    {   
        result.push_back(nums);
        return;
    }

    for(int i=ind; i<nums.size(); i++){
        swap(nums[ind], nums[i]);
        funcRecur_Optimal(ind+1, nums, result);
        swap(nums[ind], nums[i]);
    }
}



vector<vector<int>> permute_Optimal(vector<int>& nums) {
    vector<vector<int>> result; 
    vector<int> ds;
    
    funcRecur_Optimal(0, nums, result);
    return result;
}

/* --------------------- APPROACH-II - ends -----------------------------------*/



void printVector(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j <<  " " ;
        cout << endl;
    }
}


int main(){
    vector<int> nums {1,2,3};
    vector<vector<int>> result = permute_Optimal(nums);
    printVector(result);
}
