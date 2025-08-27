/**
 * Leetcode-704: Binary Search
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int target) {
    int ind = -1;
    int low=0, high=a.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(target < a[mid])
            high = mid-1;
        else if(target > a[mid])
            low = mid+1;
        else
            return mid;
    }
    return -1;
}

int main(){
    vector<int> a{-1,0,3,5,9,12};
    cout << search(a, 12) << endl;
}