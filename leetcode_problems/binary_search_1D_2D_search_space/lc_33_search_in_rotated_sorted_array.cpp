/**
 * Leetcode-33: Search in Rotated Sorted Array
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int x) {
    int n = a.size();
    int low = 0, high=n-1;

    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == x)
            return mid;
        
        // Check for sorted array
        if(a[low] <= a[mid]) // -> Left is sorted
        {
            if(a[low] <= x and x <= a[mid])
                high = mid-1;   // element present in the sorted part. Therefore eliminate the right half
            else
                low = mid+1;
        }

        else // -> right is sorted
        {
            if(a[mid] <= x and x <= a[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> a{5,1,3};
    cout << search(a, 3) << endl;
}

