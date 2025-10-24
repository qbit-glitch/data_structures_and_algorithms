/**
 * GFG: Celebrity Problem
 * Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
*/

#include <bits/stdc++.h>
using namespace std;


/** Thought Process:
 * 1. Find out the candidate for the celebrity using two pointers and method of elimination
 * 2. If any candidate exist :
 *      - traverse the entire row and entire column of that candidate : 
 *          for celebrity : 
 *          a. row elements = 0
 *          b. column elements = 1 
*/
int celebrity(vector<vector<int>>& mat) {
    int top = 0, down = mat.size()-1;
    while(top < down){
        if(mat[top][down] == 1)
            top++;
        else if(mat[down][top] == 1)
            down--;
        else{
            top++; down--;
        }
    }

    if(top > down)      return -1;
    for(int i=0; i<mat.size(); i++){
        if(i == top)
            continue;
        if(mat[i][top] != 1 or mat[top][i] != 0)
            return -1;
    }
    return top;
}

int main(){
    vector<vector<int>> mat = {{0,1,1,0}, {0,0,0,0}, {0,1,0,0}, {1,1,0,0}};
    cout << celebrity(mat) << endl;
}