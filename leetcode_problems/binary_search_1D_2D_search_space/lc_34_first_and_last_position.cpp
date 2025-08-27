/**
 * Leetcode-34: First and Last Position of Element in a Sorted Array
*/

#include <bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int> &a, int x){
    int n = a.size();
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] > x)
            high = mid-1;
        else if(a[mid] < x)
            low = mid+1;
        else{
            if(mid >0 and a[mid-1] == a[mid])
                high = mid-1;
            else
                return mid;
        }
    }
    return -1;
}

int lastOccurance(vector<int> &a, int x){
    int n = a.size();
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] > x)
            high = mid-1;
        else if(a[mid] < x)
            low = mid+1;
        else{
            if(mid < n-1 and a[mid+1] == a[mid])
                low = mid+1;
            else
                return mid;
        }
    }
    return -1;
}


vector<int> searchRange(vector<int>& nums, int target) {
    return vector<int>({firstOccurance(nums, target), lastOccurance(nums, target)});
}

int main(){
    vector<int> a{5,7,7,7,8,8,8,8,8,9,10,11,11,13,14};
    auto ans = searchRange(a, 8);
    cout << ans[0] << " " << ans[1] << endl;
}