/**
 * GFG: Find Square Root using Binary Search
 * Link: https://www.geeksforgeeks.org/problems/square-root/1
*/

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    // code here
    int low = 1, high=n;
    int ans;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(mid * mid <= n)
        {    
            ans = mid;
            low = mid+1;
        }
        else
            high = high-1;
        
    }
    return ans;
}

int main(){
    cout << floorSqrt(30) << endl;
}