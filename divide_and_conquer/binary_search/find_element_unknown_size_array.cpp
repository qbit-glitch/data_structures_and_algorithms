#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair<bool, int> binarySearch(const vector<int>& a, int low, int high, int x){
    while(low <= high){
        int mid = (low + high)/2;
        if(x < a[mid])
            high = mid-1;
        else if(x > a[mid])
            low = mid+1;
        else
            return make_pair(true,mid);
    }
    return make_pair(false, -1);
}

void findElementInUnkownSizeArray(const vector<int> &a, int startIndex, int x){
    int i = startIndex+1;
    
    while(a[i] < x){
        i *= 2;    
    }
    

    int low = i/2;
    int high = i;
    
    cout << "Range Index: " << low << " to " << high << endl;
    
    auto result = binarySearch(a, low, high, x);
    if(!result.first){
        cout << "ELement not found !" << endl;
        return;
    }
    cout << "Element Found at position: " << result.second << endl;
}

int main(){
    vector<int> a {2,4,6,8,10,12,15,20,25,30,31,35,40,45,51,54,102,108,200,220};
    findElementInUnkownSizeArray(a, 0, 12);
}