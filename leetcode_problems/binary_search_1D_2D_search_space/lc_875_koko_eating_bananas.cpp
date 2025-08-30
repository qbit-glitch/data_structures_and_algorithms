/**
 * Leetcode-875: Koko Eating Bananas
*/

#include <bits/stdc++.h>
using namespace std;


int findMaxPile(vector<int> &a){
    int maxi = a[0];
    for(auto &i: a)
        maxi = max(maxi, i);
    return maxi;
}

long long findTotalHours(vector<int> &piles, int a){
    long long totalH = 0; 
    for(auto &i: piles){
        totalH += (long long)ceil((double)i / (double)a);
    }
    return totalH;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = findMaxPile(piles);
    int ans = 0;
    while(low <= high){
        int mid = (low + high)/2;
        long long totalH = findTotalHours(piles, mid);

        if(totalH <= h){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int main(){
    vector<int> a{30,11,23,4,20};
    int h=6;
    cout << minEatingSpeed(a, h) << endl;
}