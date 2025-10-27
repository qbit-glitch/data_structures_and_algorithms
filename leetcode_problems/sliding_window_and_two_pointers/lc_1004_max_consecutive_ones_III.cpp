/**
 * Leetcode-1004: Max Consecutive Ones - III
 * Link: https://leetcode.com/problems/max-consecutive-ones-iii/
*/

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& a, int k) {
    int cnt1=0, cnt0=0, l=0, r=0, max1s=0;
    while(r < a.size()){
        if(a[r] == 1)
            cnt1++;
        else{
            cnt0++;
            if(cnt0 <= k)
                cnt1++;
            else{ 
                while(cnt0 > k and l<=r){
                    if(a[l] == 0)
                        cnt0--;
                    if(a[l] == 1)
                        cnt1--;
                    l++;
                }
            }
        }
        max1s = max(max1s, cnt1);
        r++;
    }
    return max1s;
}

int main(){
    vector<int> a{1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout << longestOnes(a,k) << endl;
}