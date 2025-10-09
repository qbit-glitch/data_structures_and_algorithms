
#include <bits/stdc++.h>
using namespace std;



void printVectors(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}


int sequenceRecursive(int idx, vector<int> &arr, int &sum, int k){
    if(idx == arr.size()){
        // condition satisfied
        if(sum == k)    return 1;

        // condition not satisfied
        else return 0;
    }
    
    sum += arr[idx];    // pick the element
    int left = sequenceRecursive(idx+1, arr, sum, k);

    
    sum -= arr[idx];
    int right  = sequenceRecursive(idx+1, arr, sum, k);

    return left+right;
}

void printSubsequencesWithSumK(vector<int> &arr, int k) {
    // code here
    int sum=0;
    cout << sequenceRecursive(0, arr, sum, k) << endl;
}


int main(){
    vector<int> a{1,2,1};
    printSubsequencesWithSumK(a, 2);
}
