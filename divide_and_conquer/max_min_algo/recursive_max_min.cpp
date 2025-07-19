#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void recursiveMaxMin(vector<int>& a, int low, int high, int& max, int& min){
    if(low == high) {
        max = min = a[low];
    }
    else if(high - low == 1){
        if (a[high] > a[low]){
            max = a[high];
            min = a[low];
        }
        else {
            max = a[low];
            min = a[high];
        }
    }
    else {
        int mid = (low + high)/2;
        recursiveMaxMin(a, low, mid, max, min);

        int max1, min1;
        recursiveMaxMin(a, mid+1, high, max1, min1);

        // Conquer
        if(max < max1)
            max = max1;
        if(min > min1)
            min = min1;
    }
}

int main(){
    vector<int> a {20,5,2,10,6,5,-5,15,7,12, 40};
    int max = a[0], min = a[0];
    recursiveMaxMin(a, 0, a.size()-1, max, min);
    cout << max << " " << min << endl;
}