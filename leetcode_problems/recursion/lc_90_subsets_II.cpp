/**
 * Leetcode-90: Subsets - II
*/

#include <bits/stdc++.h>
using namespace std;

void func(int ind, vector<int> &ds, vector<vector<int>> &result, vector<int> &a){
    if(ind >= a.size())
    {   
        result.push_back(ds); 
        return;
    }
    result.push_back(ds);
    for(int i=ind; i<a.size(); i++){
        if(i > ind and a[i]==a[i-1])
            continue;
        ds.push_back(a[i]);
        func(i+1, ds, result, a);
        ds.pop_back();
    }
}



vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> ds;
    func(0, ds, result, nums);
    return result;
}


void printVector(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j <<  " " ;
        cout << endl;
    }
}


int main(){
    vector<int> a{1,2,2};
    vector<vector<int>> result = subsetsWithDup(a);
    printVector(result);
}