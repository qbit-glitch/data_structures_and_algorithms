/**
 * Leetcode-73: Set Matrix Zeroes
*/

#include <bits/stdc++.h>
using namespace std;

void setZeroesSelf(vector<vector<int>> &matrix){
    vector<pair<int, int>> coordinates;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0)
                coordinates.push_back(make_pair(i,j));
        }
    }

    for(pair<int, int> i: coordinates){
        for(int k=0; k<m; k++)
            matrix[i.first][k] = 0;
        for(int k=0; k < n; k++)
            matrix[k][i.second] = 0;
    }
}

void printMatrix(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

void setZeroes_Better(vector<vector<int>> &a){
    int n = a.size(), m = a[0].size();
    int row[n] = {0};
    int col[m] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){
                col[j] = 1;
                row[i] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] || col[j]){
                a[i][j] = 0;
            }
        }
    }
}


void setZeroes_Optimal(vector<vector<int>> &a){
    int col0 = 1;
    int n = a.size();
    int m = a[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){
                a[i][0] = 0;    // row array
                // col array

                if(j != 0)
                    a[0][j] = 0;    
                else
                    col0 = 0;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;
        }
    }

    if(a[0][0] == 0){
        for(int j=0; j<m; j++)
            a[0][j] = 0;
    }

    if(col0 == 0){
        for(int i=0; i<n; i++)
            a[i][0] = 0;
    }

}


int main(){
    vector<vector<int>> matrix{{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    setZeroes_Optimal(matrix);
    printMatrix(matrix);
}