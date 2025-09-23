/**
 * Leetcode-240: Search 2D Matrix II
*/

#include <bits/stdc++.h>
using namespace std;

int findElementInRow(vector<int> &a, int t){
    int low = 0, high = a.size(), ans=-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == t)     return mid;
        else if(a[mid] > t)     high = mid-1;
        else    low = mid+1;
    }
    return -1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(auto i: matrix){
        if(findElementInRow(i, target) != -1)
            return true;
    }
    return false;
}

bool searchMatrix_Optimal(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m-1;
    while(row < n and col >= 0){
        if(matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}


int main(){
    vector<vector<int>> a{{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    cout << searchMatrix_Optimal(a, 20) << endl;
}
