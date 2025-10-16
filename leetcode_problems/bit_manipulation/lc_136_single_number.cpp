/**
 * Leetcode-136: Single Number
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& a) {
    int n;
    for(auto &i: a){
        n ^= i;
    }    
    return n;
}

int main(){
    vector<int> a{1,3,4,1,4,5,3};
    cout << singleNumber(a) << endl;
}