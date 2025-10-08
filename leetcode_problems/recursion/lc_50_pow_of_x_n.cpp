/**
 * Leetcode-50: Pow(x,n)
*/

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    if(n==0 or x==1)
        return 1;
    double power=1.0;
    if(n>0)
        power = myPow(x, n/2);
    else
        power = myPow(1/x, abs(n/2));

    if(n%2 == 0)
        return power*power;
    else{
        if(n > 0)
            return power*power*x;
        else
            return power*power*1/x;
    }
}

int main(){
    cout << myPow(9, -5) << endl;
}