/**
 * Leetcode-35: Search Insert Position
*/

#include <bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int>& a, int target){
    int n=a.size();
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(target > a[mid])
            low = mid+1;
        else if(target < a[mid])
            high = mid-1;
        else{
            if(mid > 0 and a[mid-1] == a[mid])
                high = mid-1;
            else
                return mid;
        }
    }
    return high+1;
}

int searchInsert(vector<int>& nums, int target) {
    return findLowerBound(nums, target);
}

int main(){
    vector<int> a{2, 3, 7,7,7,7,7,7,7,10,10,10,10, 10, 11, 11, 25};
    cout << searchInsert(a, 11) << endl;
}