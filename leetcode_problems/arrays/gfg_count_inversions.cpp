/**
 * GFG: Count Inversions
 * Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

int inverses = 0;

void merge(vector<int> &a, int l, int mid, int h);


void mergeSort(vector<int> &a, int l, int h){
    if(l >= h)
        return;
    
    int mid = (h+l)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, h);

    merge(a,l,mid, h);
}

void merge(vector<int> &a, int l, int mid, int h){
    
    vector<int> b(h-l+1, 0);
    int i=l, j=mid+1, k=l;

    while(i <= mid and j <= h){
        if(a[i] <= a[j]){
            b[k-l] = a[i++];
        }
        else if(a[i] > a[j]){
            inverses += mid-i + 1;
            b[k-l] = a[j];
            j++; 
        }
        k++;
    }

    if(i > mid) {
        for(int p=j; p<=h; p++)
        {    
            b[k-l] = a[p];
            k++;
        }
    }

    if (j > h){
        for(int p=i; p<=mid; p++){
            b[k++-l] = a[p];
        }
    }

    for(int p=l; p<=h; p++){
        a[p] = b[p-l];
    }
}


int inversionCount(vector<int> &a){
    mergeSort(a, 0, a.size()-1);
    return inverses;
}


int main(){
    vector<int> a{2,4,1,3,5};
    cout << inversionCount(a) << endl;
}
