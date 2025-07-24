#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool majorityElementExistsOrNot(vector<int>& a, int low, int high){
    int mid = (low + high)/2;
    int size = (high-low)/2;
    
    int firstOccMid = distance(a.begin(), find(a.begin(), a.end(), a[mid]));
    
    if(a[firstOccMid + size/2] == a[mid])
    {
        cout << "Majority Element:" << a[mid] << endl;
        return true;
    }
    else
        return false;
}

int main(){
    vector<int> a{2,2,4,4,4,4,4,4,8,8,10};
    cout << majorityElementExistsOrNot(a, 0, a.size()-1) << endl;
}