/**
 * Coding Ninjas: Get Floor and Ceil in a Sorted Array
 * Link: https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTab=0
*/

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int t){
    if(t < a[0])
        return -1;
    int low = 0,  high = a.size()-1;
    int ans;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] < t)
            low = mid+1;
        else if(a[mid] > t)
            high = mid-1;
        else{
            if(mid > 0 and a[mid-1] == a[mid])
                high = mid-1;
            else
                return mid;
        }
    }
    return a[high];
}

int upperBound(vector<int> &a, int t){
    if(t > a[a.size()-1])
        return -1;
    int low = 0,  high = a.size()-1;
    int ans;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] < t)
            low = mid+1;
        else if(a[mid] > t)
            high = mid-1;
        else{
            if(mid < a.size()-1 and a[mid+1] == a[mid])
                low = mid+1;
            else
                return mid;
        }
    }
    return a[low];
}



int ceil(vector<int> &a, int x){
    // exactly the lower bound algo
    int ans=-1, low=0, high=a.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] >= x){
            ans = a[mid];
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}


int floor(vector<int> &a, int x){
    // Tweaking the lower bound algo
    int ans=-1, low=0, high=a.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] <= x){
            ans = a[mid];
            low = mid+1;
        }else {
            high = mid - 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	// return make_pair(lowerBound(a,x), upperBound(a,x));
    
    return make_pair(floor(a,x), ceil(a,x));    
}



int main(){
    vector<int> a{2, 3, 10,10,10,10, 10, 11, 11, 25};
    auto ans =  getFloorAndCeil(a, a.size()-1, 7);
    cout << ans.first << " " << ans.second << endl;
}
