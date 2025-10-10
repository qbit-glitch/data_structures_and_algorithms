/**
 * Leetcode-39: Combination Sum
*/

#include <bits/stdc++.h>
using namespace std;

void combSumRecursion(int i, int target, vector<int>& instance, vector<vector<int>> &result, vector<int>& a){
    // base case
    if(i >= a.size()){
        if(target == 0)
        {
            result.push_back(instance);
            return;
        }
        else    return;
    }

    if(target < 0)
        return;

    instance.push_back(a[i]);
    combSumRecursion(i, target-a[i], instance, result, a);
    instance.pop_back();

    combSumRecursion(i+1, target, instance, result, a);
}



vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> instance{};
    combSumRecursion(0, target, instance, result, candidates);
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
    vector<int> candidates{2,3,5};
    int target = 8;
    auto result = combinationSum(candidates, target);
    printVectors(result);
}