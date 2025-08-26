/**
 * GFG: Count Inversions
 * Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

int inverses = 0;


void merge(vector<int> &a, int l, int mid, int h){
    
    vector<int> b;
    b.reserve(h-l+1);
    int i=l, j=mid+1;

    while(i <= mid and j <= h){
        if(a[i] <= a[j]){
            b.push_back(a[i++]);
        }
        else if(a[i] > a[j]){
            inverses += (long long)(mid-i + 1);
            b.push_back(a[j++]);
        }
    }
    while(i <= mid)    b.push_back(a[i++]);
    while(j<= h)     b.push_back(a[j++]);
    int idx=0;
    for(int p=l; p<=h; p++){
        a[p] = b[idx++];
    }

}


void mergeSort(vector<int> &a, int l, int h){
    if(l >= h)
        return;
    
    int mid = l + (h-l)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, h);

    merge(a,l,mid, h);
}


int inversionCount(vector<int> &a){
    mergeSort(a, 0, a.size()-1);
    return inverses;
}

int main(){
    vector<int> a{2,4,1,3,5};
    cout << inversionCount(a) << endl;
}
