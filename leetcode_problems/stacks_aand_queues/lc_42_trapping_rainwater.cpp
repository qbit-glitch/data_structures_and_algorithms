/**
 * Leetcode-42: Trapping Rainwater
 * Link: https://leetcode.com/problems/trapping-rain-water/description/
*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& a) {
    int lMax=0, rMax=0, total=0, l=0, r=a.size()-1;
    while(l < r){
        if(a[l] <= a[r]){
            if(lMax > a[l])
                total += lMax-a[l];
            else
                lMax = a[l];
            l++;
        }
        else {
            if(rMax > a[r])
                total += rMax-a[r];
            else
                rMax = a[r];
            r--;
        }
    }    
    return total;
}

int main(){
    vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(a) << endl;
}