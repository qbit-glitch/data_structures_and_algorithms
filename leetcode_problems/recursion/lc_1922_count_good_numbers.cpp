/**
 * Leetcode-1922: Count Good Numbers
*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007;

long long power(long long x, long long y){
    if(y==0)    return 1;
    long long pow = power(x, y/2);
    pow = (pow * pow) % mod;
    if(y%2)
        pow *= x;
    pow %= mod;
    return pow;
}


int countGoodNumbers(long long n) {
    long long odd = n/2;
    long long even = n/2 + n%2;
    return power(5,even) * power(4, odd) % mod;
}



int main(){
    long long n = 1345678;
    cout << countGoodNumbers(n) << endl;
}