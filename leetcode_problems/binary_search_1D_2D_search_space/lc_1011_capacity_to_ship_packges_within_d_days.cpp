/**
 * Leetcode-1011: Capacity to Ship packages within d days
*/

#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &a, int sum){
    int w=0, d=1, c=0;
    for(auto &i: a){
        if(c+i <= sum)
            c += i;
        else
        {
            c = i;
            d++;
        }
    }
    return d;
}

int findSumOfArray(vector<int> &a){
    int c = 0;
    for(auto &i: a)
        c += i;
    return c;
}

int findMaxElement(vector<int> &a){
    int maxEl = INT_MIN;
    for(auto &i: a){
        maxEl = max(maxEl, i);
    }
    return maxEl;
}


int shipWithinDays(vector<int>& weights, int days) {
    int low = findMaxElement(weights), high = findSumOfArray(weights);
    int w = INT_MAX, d;
    while(low <= high){
        int mid = (low + high)/2;
        auto d = findDays(weights, mid);
        
        if(d <= days){
            high = mid-1;
            w = min(mid, w);
        }
        else{
            low = mid+1;
        }
    }
    return w;
}

int main(){
    vector<int> weights {1,2,3,1,1};
    int days = 4;
    cout << shipWithinDays(weights, days) << endl;
    // cout << findDays(weights, 4) << endl;
}