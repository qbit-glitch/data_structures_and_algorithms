#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> straightMM(vector<vector<int>>& a, int p, int q, vector<vector<int>>& b, int r){
    vector<vector<int>> c (p, vector<int>(r,0));
    for(int i=0; i < p; i++){
        for(int j=0; j < q; j++){
            for(int k=0; k < r; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

void printVector(vector<vector<int>> c){
    for(auto i: c){
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int>> a {{1,2,3}, {4,5,6}};
    vector<vector<int>> b {{1,2}, {3,4}, {5,6}};
    printVector(straightMM(a,a.size(),a[1].size(),b,b[1].size()));
}