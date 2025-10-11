/**
 * Leetcode-216: Combination Sum - III
 * 
*/

#include <bits/stdc++.h>
using namespace std;

void print1DVector(vector<int> &a){
    for(int &i: a)
        cout << i << " ";
    cout << endl;
}


/** Thought Process :
 * 1. Find all subsets of length 3 and sum = n
 * 2. if (length of subset > 3) or (a[ind] > n) return from the function 
*/

void func(int ind, int k, int n, vector<int>&ds, vector<vector<int>> &result, vector<int> &a){
    if(n == 0 and ds.size() == k){
        result.push_back(ds);
        return;
    }

    if(ds.size() > k)   return;
    if(a[ind] > n) return;
    
    ds.push_back(a[ind]);
    func(ind+1, k, n-a[ind], ds, result, a);
    ds.pop_back();
    func(ind+1, k, n, ds, result, a);
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result{};
    vector<int> ds{};
    vector<int> a{1,2,3,4,5,6,7,8,9};
    func(0, k, n, ds, result, a);
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
    cout << "Combination Sum 3" << endl;
    vector<vector<int>> result = combinationSum3(3, 9);
    printVector(result);
}
