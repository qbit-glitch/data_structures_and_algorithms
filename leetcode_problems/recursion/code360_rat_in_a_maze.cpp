/**
 * Code 360: Rat in a Maze
 * Link : https://www.naukri.com/code360/problems/rat-in-a-maze_1215030_1215030
*/

#include <bits/stdc++.h>
using namespace std;

bool func(int row, int col, string ds, vector<string> &result, vector<vector<int>> &a, int n){
    if(row == n-1 and col == n-1){
        result.push_back(ds);
        return true;
    }

    if(row < 0 or col < 0 or row >= n or col >= n or a[row][col] == 0 or a[row][col] == -1)
        return false;

    int c = a[row][col];
    a[row][col] = -1;

    bool down = func(row+1, col, ds+"D", result, a, n);
    bool left = func(row, col-1, ds+"L", result, a, n);
    bool right = func(row, col+1, ds+"R", result, a, n);
    bool up = func(row-1, col, ds+"U", result, a, n);

    a[row][col] = c;
    return up || down || left || right;
}


vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> result;
    string ds = "";
    
    if(func(0,0, ds, result, arr, n))
        return result;
    return {};
}

void printVectors(vector<string> &a){
    
    for(auto&j: a)
        cout << j << " ";
    cout << endl;

}

int main(){
    int  n = 4;
    vector<vector<int>> a{{1,0,0,0}, {1,1,0,0}, {1,1,0,0}, {0,1,1,1}};
    auto result = searchMaze(a, n);
    printVectors(result);
}