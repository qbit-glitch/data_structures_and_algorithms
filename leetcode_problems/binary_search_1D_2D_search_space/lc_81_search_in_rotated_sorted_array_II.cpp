/**
 * Leetcode-81: Search in Rotated Sorted Array II
*/

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& a, int x) {
    int n = a.size();
    int low = 0, high = n-1;
    cout << low << " " << high << endl;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == x)
            return true;
        
        if(a[mid] == a[low] and a[mid] == a[high]){
            low++; high--;
            continue;
        }


        if(a[low] <= a[mid]){
            // Left part is sorted
            if(a[low] <= x and x <= a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else {
            if(a[mid] <= x and x <= a[high])
                low = mid + 1;
            else
                high = mid-1;
        }
    }
    return false;
}


int main(){
    vector<int> a{1};
    cout << search(a, 1) << endl;
}
