/**
 * Leetcode-17: Letter Combinations of a Phone Number
*/

#include <bits/stdc++.h>
using namespace std;

void func(int ind, string ds, vector<string> &result, string &digits, unordered_map<int,string> &mpp){
    if(ds.size() == digits.size()){
        result.push_back(ds);
        return;
    }
    int digit = digits[ind] - '0';
    for(char c: mpp[digit]){
        func(ind+1, ds+c, result, digits, mpp);
    }
}


vector<string> letterCombinations(string digits) {
    vector<string> result;
    string ds = "";
    unordered_map<int, string> mpp = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };
    func(0, ds, result, digits, mpp);
    return result;
}

void printStr(vector<string> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    string digits = "23";
    vector<string> result = letterCombinations(digits);
    printStr(result);
}