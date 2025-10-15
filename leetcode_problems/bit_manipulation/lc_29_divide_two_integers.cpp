/**
 * Leetcode-29: Divide Two Integers
 * 
*/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == divisor)
        return 1;
    
    if(dividend == INT_MIN and divisor == -1)   return INT_MAX;
    if(dividend == INT_MAX and divisor == -1)   return INT_MIN+1;
    if(divisor == 1)    return dividend;
    
    
    bool sign = true;
    if((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0))
        sign = false;



    long n = dividend;
    long d = divisor;

    n = abs(n);
    d = abs(d);

    long ans = 0;
    while(n >= d){
        int cnt = 0;
        while(n >= (d << (cnt+1)))
            cnt++;
        ans += (1 << cnt);
        n = n - (d << cnt);
    }
    if(ans >= INT_MAX and sign == true)
        return INT_MAX;
    if(ans >= INT_MAX and sign == false)
        return INT_MIN;

    return (sign) ? ans : (-1 * ans);
}

int main(){
    cout << divide(-10, 3) << endl;
}