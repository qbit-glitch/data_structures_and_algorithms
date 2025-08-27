/**
 * GFG: Implemennt Upper Bound
 * Link: https://www.geeksforgeeks.org/problems/implement-upper-bound/1
*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &a, int target){
    int n=a.size();
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(target < a[mid])
            high = mid-1;
        else {
            if(target > a[mid])
                low = mid+1;
            else {
                if(mid < n-1 and a[mid+1] == a[mid])
                    low = mid+1;
                else 
                    return mid+1;
            }
        }
    }
    return low;
}

int main(){
    vector<int> a{2, 3, 7, 10, 11, 11, 25};
    cout << upperBound(a, 11) << endl;
}