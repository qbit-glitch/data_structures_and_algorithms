/**
 * GFG: Generate all Binary String
 * Link: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> bstr(int n){
    if(n==1){
        vector<string> v = {"0", "1"};
        return v;
    }    
    vector<string> prev = bstr(n-1);
    vector<string> result;

    for(auto i: vector<string>{"0", "1"}){
        for(auto &j: prev){
            result.push_back(i+j);
        }
    }
    return result;
}

void printVector(vector<string> v){
    for(auto &i: v){
        cout << i << endl;
    }
}


int main(){
    vector<string> result = bstr(5);
    printVector(result);
}