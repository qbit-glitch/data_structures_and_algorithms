/**
 * Leetcode-231: Power of Two
 * Link: https://leetcode.com/problems/power-of-two/description/
*/

#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int n){
    string s="";
    while(n>0){
        if(n%2 == 1)    s+= '1';
        else    s+= '0';
        n = n/2;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool isPowerOfTwo(int n) {
    string s = convertToBinary(n);
    for(int i=s.size()-1; i>=0; i--){
        if(i != 0 and s[i] == '1')
            return false;
    }
    return true;
}

bool isPowerOfTwo_Optimal(int n){
    if(n<=0)
        return false;
    int s = n & n-1;
    return (s == 0)? true: false;
}

int main(){
    int n = 256;
    cout << isPowerOfTwo_Optimal(n) << endl;
}