/**
 * GFG: Implement Lower Bound
    Link: https://www.geeksforgeeks.org/problems/implement-lower-bound/1
*/

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int target){
    int low=0, high = a.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(target < a[mid])
            high = mid-1;
        else {
            if(target > a[mid])
                low = mid+1;
            else {
                if(mid > 0 and a[mid] == a[mid-1])
                    high = mid-1;
                else
                    return mid;
            }   
        }
    }
    return high+1;
}

int main(){
    vector<int> a{2, 3, 7,7,7,7,7,7,7,10,10,10,10, 10, 11, 11, 25};
    cout << lowerBound(a, 11) << endl;
}