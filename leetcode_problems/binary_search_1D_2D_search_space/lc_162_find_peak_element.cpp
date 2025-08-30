/**
 * Leetcode-162: Find Peak Element 
*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& a) {
    int n = a.size();
    if(n==1)   return 0;
    if(a[0] > a[1]) return 0;
    if(a[n-1] > a[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] > a[mid+1] and a[mid] > a[mid-1])
            return mid;
        
        else if(a[mid] > a[mid-1])
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main(){
    vector<int> a{1,2,3,4,1,1,1,6,7,9,3,2};
    cout << findPeakElement(a) << endl;

}