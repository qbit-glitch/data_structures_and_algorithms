/**
 * Leetcode-40: Combination Sum II
*/

#include <bits/stdc++.h>
using namespace std;


void func(int ind, int target, vector<int> ds, vector<vector<int>> &result, vector<int> &a){
    if(target == 0){
        result.push_back(ds);
        return;
    }

    for(int i=ind; i<a.size(); i++){
        if(i>ind and a[i] == a[i-1])
            break;
        if(a[i] > target)
            break;
        ds.push_back(a[i]);
        func(i+1, target-a[i], ds, result, a);
        ds.pop_back();
    }
}



vector<vector<int>> combinationSum2_Better(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> ds;
    
    sort(candidates.begin(), candidates.end());
    func(0, target, ds, result, candidates);
    
    return result;
}



void printVectors(vector<vector<int>> &a){
    for(auto& i: a){
        for(auto&j: i)
            cout << j << " ";
        cout << endl;
    }
}



int main(){
    vector<int> candidates{10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result;
    result = combinationSum2_Better(candidates, target);
    printVectors(result);
}