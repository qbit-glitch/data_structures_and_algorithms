/**
 * Leetcode-1901: Find the Peak Element-II
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxElementInCol(vector<vector<int>> &a, int m){
    int max=INT_MIN, maxInd = -1;
    for(int i=0; i <= a.size()-1; i++){
        if(a[i][m] > max){
            max = a[i][m];
            maxInd = i;
        }
    }
    return maxInd;
}


vector<int> findPeakGrid(vector<vector<int>>& a) {
    int low = 0, high = a[0].size()-1;
    int n = a.size(), m = a[0].size();
    while(low <= high){
        int mid = (low + high)/2;
        int row = findMaxElementInCol(a, mid);
        int left = (mid-1 >= 0) ? a[row][mid-1] : -1;
        int right = (mid+1 < m) ? a[row][mid+1] : -1;

        if(a[row][mid] > left and a[row][mid] > right)
            return vector<int>{row, mid};
        else if(a[row][mid] < left)
            high = mid-1;
        else
            low = mid+1;
    }    
    return vector<int>{-1,-1};
}

void printVector(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<vector<int>> a{{1,4}, {3,2}};
    auto res = findPeakGrid(a);
    printVector(res);
}