
#include <bits/stdc++.h>
using namespace std;



void printVectors(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}


bool sequenceRecursive(int idx, vector<int>& instance, vector<vector<int>> &result, vector<int> &arr, int &sum, int k){
    if(idx == arr.size()){
        if(sum == k)
        {
            result.push_back(instance);
            return true;
        }
        return false;
    }
    instance.push_back(arr[idx]);
    sum += arr[idx];    // pick the element
    if(sequenceRecursive(idx+1, instance, result, arr, sum, k) == true) 
        return true;

    instance.pop_back();
    sum -= arr[idx];
    if(sequenceRecursive(idx+1, instance, result, arr, sum, k) == true)
        return true;

    return false;
}

void printSubsequencesWithSumK(vector<int> &arr, int k) {
    int ans = 0, sum=0;
    vector<int> instance{};
    vector<vector<int>> res;
    sequenceRecursive(0, instance, res, arr, sum, k);
    printVectors(res);
    
}


int main(){
    vector<int> a{1,2,1};
    printSubsequencesWithSumK(a, 2);
}
