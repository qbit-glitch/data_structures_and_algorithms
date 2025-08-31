/**
 * Leetcode-1482: Minimum Number of Days to make `m` bouquets
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findRange(vector<int> &a){
    int minEl = INT_MAX, maxEl = INT_MIN;
    for(auto &i: a){
        minEl = min(i, minEl);
        maxEl = max(maxEl, i);
    }
    return make_pair(minEl, maxEl);
}

bool checkIfPossible(vector<int> &a, int day, int m, int k){
    int count = 0, total=0;
    for(auto &i: a){
        if(i <= day)
            count ++;
        else {
            total += count/k;
            count=0;
        }
    }
    total+= count/k;
    return (total >= m) ? true : false;
}

int minDays(vector<int> &bloomDay, int m, int k){
    if(bloomDay.size() < m*k)
        return -1;
    
    auto range = findRange(bloomDay);
    int low = range.first, high = range.second;
    int ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(checkIfPossible(bloomDay, mid, m, k))
        {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> a{7,7,7,7,13,11,12,7};
    cout << minDays(a, 2, 3) << endl;
}