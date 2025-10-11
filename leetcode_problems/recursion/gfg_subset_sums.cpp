/**
 * GFG: Subset Sums
 * Link: https://www.geeksforgeeks.org/problems/subset-sums2234/1
*/

#include <bits/stdc++.h>
using namespace std;

void func(int i, vector<int> &ds, vector<int> &result, vector<int> &a){
    if(i>=a.size()){
        int sum = accumulate(ds.begin(), ds.end(), 0);
        result.push_back(sum);
        return;
    }

    ds.push_back(a[i]);
    func(i+1, ds, result, a);
    ds.pop_back();
    func(i+1, ds, result, a);
}


vector<int> subsetSums(vector<int>& arr) {
    vector<int> result;
    vector<int> ds;
    func(0, ds, result, arr);
    return result;    
}

void printVector(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}


int main(){
    vector<int> a{2,3};
    vector<int> result = subsetSums(a);
    printVector(result);
}