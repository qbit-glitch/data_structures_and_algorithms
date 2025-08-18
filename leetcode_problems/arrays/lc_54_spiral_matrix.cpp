/**
 * Leetcode-54: Spiral Matrix
*/

#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>> &a){
    int n = a.size();
    int m = a[0].size();
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;

    while(top <= bottom and left <= right){
        for(int i=left; i<=right; i++)
            cout << a[top][i] << " ";
        top++;

        for(int i=top; i<= bottom; i++)
            cout << a[i][right] << " ";
        right--;
        if(top <= bottom){
            for(int i=right; i>=left; i--)
                cout << a[bottom][i] << " ";
            bottom--;
        }
        if(left <= right){
            for(int i=bottom; i>=top; i--)
                cout << a[i][left] << " ";
            left++;
        }
    }
    cout << endl;
}


int main(){
    vector<vector<int>> a{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    spiralMatrix(a);
}