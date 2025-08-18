/**
 * Leetcode-48: Rotate Image
*/

#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

void rotate(vector<vector<int>> &a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(a[i][j], a[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(a[i].begin(), a[i].end());
    }
}

void printArray(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<int>> a{{1,2,3}, {4,5,6}, {7,8,9}};
    rotate(a);
    printArray(a);
}