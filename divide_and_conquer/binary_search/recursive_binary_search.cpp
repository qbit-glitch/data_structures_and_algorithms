#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int recursiveBS(vector<int>& a, int low, int high, int x){
    if(low >= high){
        if(low == high){
            if (a[low] == x)
                return low;
            
        }
        return -1;
    }

    else {
        int mid = (low + high)/2;
        if(x < a[mid]){
            return recursiveBS(a, low, mid-1, x);
        }
        else if(x > a[mid])
            return recursiveBS(a, mid+1, high, x);
        else
            return mid;
    }
    
}

int main() {
    vector<int> a {2,4,5,8,10,12,15,20,25,30};
    int num = 25;
    cout << recursiveBS(a, 0 , a.size()-1, num) << endl;
}