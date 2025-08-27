/**
 * GFG: Number of Occurance
 * Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
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


int countFreq(vector<int>& arr, int target) {
    int loc = lastOccurance(arr, target);
    int foc =  firstOccurance(arr,target);
    if(loc != -1 and foc != -1)
        return loc-foc+1;
    else
        return 0;
}

int main(){
    vector<int> a{1,1,2,2,2,2,3};
    auto ans = countFreq(a, 2);
    cout << ans << endl;
}