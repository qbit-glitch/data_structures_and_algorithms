#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int straightBS(vector<int>& a, int low, int high, int x){
    
    while(low <= high) {
        int mid = (low + high)/2;
        
        if (x < a[mid]) {
            high = mid - 1 ;
        }
        else if(x > a[mid]) {
            low = mid + 1;
        }
        else
            return mid;
        
    }
    return -1;
}

int main() {
    vector<int> a {2,4,5,8,10,12,15,20,25,30};
    int num = 25;
    cout << straightBS(a, 0 , a.size()-1, num) << endl;
}