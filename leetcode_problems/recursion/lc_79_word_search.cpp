/**
 * Leetcode-79: Word Search
*/

#include <bits/stdc++.h>
using namespace std;

bool func(int i, int j, int ind, vector<vector<char>> &board, string &word){
    if(ind >= word.size()){
        return true;
    }

    if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] != word[ind] or board[i][j] == '!')
        return false;

    char c = board[i][j];
    board[i][j] = '!';

    bool top = func(i-1, j, ind+1, board, word);
    bool down = func(i+1, j, ind+1, board, word);
    bool left = func(i, j-1, ind+1, board, word);
    bool right = func(i, j+1, ind+1, board, word);
    
    board[i][j] = c;

    return left or right or top or down;
}


bool exist(vector<vector<char>>& board, string word) {
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
    
    // search the first character :
    for(int i=0; i<board.size(); i++){
        for(int j=0; j < board[i].size(); j++){
            if(board[i][j] == word[0])
                if(func(i,j, 0, board, word))
                    return true;    
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board{{'A', 'B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "SEE";
    cout << exist(board, word) << endl;
}