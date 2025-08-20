/**
 * Leetcode-118: Pascal's Triangle
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row){
    vector<int> ansRow;
    ansRow.push_back(1);

    int ans = 1;

    for(int col=1; col < row; col++){
        ans = ans * (row - col) / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>> ans;
    for(int i=1; i<=N; i++)
        ans.push_back(generateRow(i));
    return ans;
}

void printArray(vector<vector<int>> &arr){
    for(auto &i: arr){
        for(auto &j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    auto pascal = pascalTriangle(6);
    printArray(pascal);
}