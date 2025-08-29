/**
 * GFG: Find kth rotation
 * Link: https://www.geeksforgeeks.org/problems/rotation4723/1
*/

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &a) {
    // Code Here
    int n = a.size();
    int low = 0, high=n-1;
    int minIdx = 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[minIdx] > a[mid])
            minIdx = mid;
        
        if(a[low] <= a[mid]){
            if(a[minIdx] > a[low])
                minIdx = low;
            low = mid+1;
            
        }
        
        else{
            if(a[minIdx] > high)
                minIdx = mid;
            high = mid-1;
        }
    }
    return minIdx;
}

int main(){
    vector<int> a{5,6,7,8,1,2,3,4};
    cout << findKRotation(a) << endl;
}