/**
 * Leetcode-22: Generate Parentheses
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(string s, int open, int close, int n, vector<string> &res){
    if(s.length() == 2*n){
        res.push_back(s);
        return;
    }
    if(open < n)
        backtrack(s+'(', open+1, close, n, res);
    if(close < open)
        backtrack(s+')', open, close+1, n, res);
}

vector<string> generateParentheses(int n){
    
    vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;

}

void printVector(vector<string> v){
    for(auto &i: v) 
        cout << i << endl;
}


vector<string> findDifferenceBetweenVectors(vector<string> a, vector<string> b){
    unordered_map<string, int> mpp;
    for(auto &i: a){
        mpp[i]++;
    }

    vector<string> r;
    for(auto &j: b){
        if(mpp.find(j) == mpp.end())
            r.push_back(j);
    }
    return r;
}


int main(){
    vector<string> result = generateParentheses(3);
    cout << result.size() << endl;
    printVector(result);

}