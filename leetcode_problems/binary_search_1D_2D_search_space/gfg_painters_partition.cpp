/**
 * GFG: Painter's Partition Problem
 * Problem Link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
*/

#include <bits/stdc++.h>
using namespace std;

int paintersRequired(vector<int> &arr, int maxTime){
    int paintersCnt = 1, timeRequired = 0;
    for(auto &i: arr){
        if(timeRequired + i <= maxTime)
            timeRequired += i;
        else {
            paintersCnt++;
            timeRequired = i;
        }
    }
    return paintersCnt;
}



int minTime(vector<int>&arr, int k){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = (low+high)/2;
        int paintersCount = paintersRequired(arr, mid);
        if(paintersCount <= k)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}

int main(){
    vector<int> arr{10, 20, 30, 40};
    int k = 2;
    cout << minTime(arr, k) << endl;
}