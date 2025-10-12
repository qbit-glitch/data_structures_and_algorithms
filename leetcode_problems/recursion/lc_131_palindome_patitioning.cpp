/**
 * Leetcode-131: Palindrome Partitioning
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s1){
    int l = s1.size();
    for(int i=0; i<l/2; i++){
        if(s1[i] != s1[l-i-1])
            return false;
    }
    return true;
}


void print1DVector(vector<string> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

void func(int ind, vector<string> &ds, vector<vector<string>> &result, string &s){
    if(ind == s.size()){
        result.push_back(ds);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        string s1 = s.substr(ind, i-ind+1);
        if(isPalindrome(s1)){
            ds.push_back(s1);
            func(i+1, ds, result, s);
            ds.pop_back();
        }
    }
}





vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> ds{};
    func(0, ds, result, s);
    return result;    
}


void printVectors(vector<vector<string>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}


int main(){
    string s = "aabb";
    vector<vector<string>> result = partition(s);
    printVectors(result);
}