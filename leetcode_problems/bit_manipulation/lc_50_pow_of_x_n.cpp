/**
 * Leetcode-50: Pow(x,n)
*/

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    if(x == 1 or n == 0)
        return 1;
    if(n == INT_MIN)
        return 1.0/(x * myPow(x, -(n+1)));
    
    double ans=1.0;
    int m = abs(n);
    while(m > 0){
        if(m%2 == 1){
            ans = ans * x;
            m = m-1;
        }
        else{
            x = x*x;
            m = m/2;
        }
    }
    if(n<0)
        ans = 1.0/ans;
    return ans;

}

int main(){
    cout << myPow(2, -2) << endl;
}