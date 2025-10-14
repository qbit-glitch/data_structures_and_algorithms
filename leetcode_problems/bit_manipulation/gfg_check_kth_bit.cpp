/**
 * GFG: Check Kth Bit 
 * Link: https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

string convertInt2Binary(int n){
    string s="";
    while(n!= 0){
        if(n%2 == 0)    s+='0';
        if(n%2 == 1)    s += '1';
        n = n/2;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool checkKthBit(int n, int k) {
    string binary = convertInt2Binary(n);
    
    int cnt = 0;
    for(int i = binary.size()-1; i>=0; i--){
        if(cnt == k){
            if(binary[i] == '1')
                return true;
            return false;    
        }
        cnt++;
    }
    return false;
}

int main(){
    int n=500, k=3;
    cout << checkKthBit(n,k) << endl;
}