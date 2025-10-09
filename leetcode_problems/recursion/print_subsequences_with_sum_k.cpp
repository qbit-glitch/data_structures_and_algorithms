
#include <bits/stdc++.h>
using namespace std;



void printVectors(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}


void sequenceRecursive(int idx, vector<int>& instance, vector<vector<int>> &result, vector<int> &arr, int &sum, int k){
    if(idx == arr.size()){
        if(sum == k)
        {
            result.push_back(instance);
        }
        return;
    }
    instance.push_back(arr[idx]);
    sum += arr[idx];    // pick the element
    sequenceRecursive(idx+1, instance, result, arr, sum, k);

    instance.pop_back();
    sum -= arr[idx];
    sequenceRecursive(idx+1, instance, result, arr, sum, k);
}

void printSubsequencesWithSumK(vector<int> &arr, int k) {
    // code here
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
