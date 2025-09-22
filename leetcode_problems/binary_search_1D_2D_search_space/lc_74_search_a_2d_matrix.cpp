/**
 * Leetcode-74: Search a 2D Matrix
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = n*m-1;
    while(low <= high){
        int mid = (low + high)/2;
        int i = mid / m;
        int j = (mid % m);
        // cout << matrix[i][j] << " " << endl;
        if(matrix[i][j] == target)
            return true;
        else if(matrix[i][j] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
}

int main(){
    vector<vector<int>> a{{1}};
    int k = 11;
    cout << searchMatrix(a, k) << endl;
}