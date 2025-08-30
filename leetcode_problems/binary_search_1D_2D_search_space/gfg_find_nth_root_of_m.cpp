/**
 * GFG: Find nth root of m using Binary search
 * Link:
*/

#include <bits/stdc++.h>
using namespace std;

long long findPowerM(int base, int exp){
    long long ans = 1;
    for(int i=1; i<=exp; i++)
        ans *= base;
    return ans;

}

int nthRoot(int n, int m){
    int low = 1, high = m;
    int ans = 1;
    int flag = 0;
    while(low <= high){
        long long mid = (low+high)/2;
        if(findPowerM(mid, n) == m)
        {
            return mid;
        }
        else if(findPowerM(mid, n) < m){
            low = mid+1;
        }
        else 
            high = mid-1;
    }
    return -1;
}

int main(){
    cout << nthRoot(1,14) << endl;
}