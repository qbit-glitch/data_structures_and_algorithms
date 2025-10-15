/**
 * GFG: Number of 1 Bits
 * Link: https://www.geeksforgeeks.org/problems/set-bits0143/1
*/

#include <bits/stdc++.h>
using namespace std;

int setBits(int n){
    int cnt = 0;
    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}



int main(){
    int n = 15;
    cout << setBits(n) << endl;
}