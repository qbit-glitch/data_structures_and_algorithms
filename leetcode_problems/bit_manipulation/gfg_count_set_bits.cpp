/**
 * GFG: Count Set Bits
 * Link: https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
 * 
 * NOTE: TO be completed
*/

#include <bits/stdc++.h>
using namespace std;

int countSetBitsOfSingleNumber(int n){
    int cnt = 0;
    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}


int countSetBits(int n) {
    int c = 0;
    for(int i=1; i<=n; i++){
        c += countSetBitsOfSingleNumber(i);
    }
    return c;
}

int main(){
    int n = 17;
    cout << countSetBits(n) << endl;
}