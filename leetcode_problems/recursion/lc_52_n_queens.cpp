/**
 * Leetcode-51: N Queens
*/

#include <bits/stdc++.h>
using namespace std;


/** THought Process:
 * 1. Make an empty board
 * 2. Iterate through each column
 * 3. then for each row of that col check whether Q can be placed at cell (row, col)
 *      i. use hashing to mark and unmark the position of Queens placed at each row
 *      ii. use hashing to mark and unmark the position of Queens placed at lowerDiagonal
 *              use formula for calulating index : (row + col)
 *      iii. Use hashing to mark and unmark the position of Queens in upperDiagonal
 *              formula for index :  ((n-1) + (col-row))
 * 4. recursively call the func with the column index and the board data structure
 * 5. Note: While coming back make sure to undo the changes in the board and the hashMaps,
 *      so that it can move the sibling recursion.
*/


void func(int col, vector<string> &board, vector<vector<string>> &result, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n){
    if(col == n){
        result.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(leftRow[row] == 0 and lowerDiagonal[row+col] == 0 and upperDiagonal[n-1 + col-row] == 0){
            
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1 + col-row] = 1;

            func(col+1, board, result, leftRow, lowerDiagonal, upperDiagonal, n);

            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1 + col-row] = 0;
            
        }
    }
}

vector<vector<string>> solveQueens(int n){
    vector<vector<string>> result;
    vector<string> board(n);
    string s(n, '.');
    
    for(int i=0; i<n; i++)
        board[i] = s;

    vector<int> leftRow(n,0);
    vector<int> lowerDiagonal(2*n-1, 0);
    vector<int> upperDiagonal(2*n-1, 0);

    func(0, board, result, leftRow, lowerDiagonal, upperDiagonal, n);

    return result;
}

void printVectors(vector<vector<string>> &a){
    for(auto& i: a){
        for(auto&j: i)
            cout << j << " ";
        cout << endl;
    }
}



int main(){
    int  n = 4;
    auto result = solveQueens(n);
    printVectors(result);
}