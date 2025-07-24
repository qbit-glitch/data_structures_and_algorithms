#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int firstOccurance(const vector<int> &a, int low, int high, int x){
    while(low <= high){
        int mid = (low + high)/2;
        if(x < a[mid])
            high = mid-1;
        else if(x > a[mid])
            low = mid+1;
        else{
            if(mid > 0 and a[mid] == a[mid-1])
                high = mid - 1;
            else
                return mid;
        }
    }
    return -1;
}

int lastOccurance(const vector<int> &a, int low, int high, int x){
    while(low <= high){
        int mid = (low + high)/2;
        if(x < a[mid])
            high = mid-1;
        else if(x > a[mid])
            low = mid+1;
        else{
            if(mid < high and a[mid] == a[mid+1])
                low = mid + 1;
            else
                return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> a {2,3,4,4,4,8,8,8,8,9,10,10};
    int x = 10;
    cout << firstOccurance(a, 0, a.size() - 1, x) << endl;
    cout << lastOccurance(a, 0, a.size() - 1, x) << endl;

    cout << firstOccurance(a, 0, a.size() - 1, 4) << endl;
    cout << lastOccurance(a, 0, a.size() - 1, 4) << endl;
}