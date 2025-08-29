/**
 * Leetcode-540: Single Element in Sorted Array
*/

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& a) {
    int n=a.size();
    if(n==1)    return a[0];
    if(a[0] != a[1])    return a[0];
    if(a[n-1] != a[n-2])    return a[n-1];

    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if((mid > 0 and mid < n-1) and (a[mid] != a[mid-1] and a[mid] != a[mid+1]))
            return a[mid];
        if((mid%2==1 and a[mid] == a[mid-1]) || (mid % 2 == 0 and a[mid] == a[mid+1]))
            // Element is on the right half. Therefore eliminate the left half.
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main(){
    vector<int> a{1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(a) << endl;
}