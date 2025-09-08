/**
 * Leetcode-1539: Kth Missing Positive Number
*/

#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low=0, high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k) low = mid+1;
        else    high = mid-1;
    }
    return high+1+k;
}

int main(){
    vector<int> a{2,3,4,7,11};
    cout << findKthPositive(a, 5) << endl;
}