/**
 * Leetcode-153: Find Minimum in Rotated Sorted Array
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& a) {
    int n = a.size();
    int low = 0, high = n-1;
    int minEl = INT_MAX;
    while(low <= high){
        int mid = (low + high)/2;
        minEl = min(minEl, a[mid]);
        // We know the min element will be in the unsorted part
        if(a[low] <= a[mid]){
            // Left half is sorted. So eliminate the left half
            minEl = min(minEl, a[low]);
            low = mid+1;
        }
        else {
            // Right half is sorted
            minEl = min(minEl, a[mid]);
            high = mid - 1;
        }
    }
    return minEl;
}

int main(){
    vector<int> a{4,5,6,7,-2,1,2};
    cout << findMin(a) << endl;
}