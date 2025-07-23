#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int partition(vector<int>& a, int low, int high){
    int pivotIdx = a[low];
    int i = low, j = high+1;

    do {
        do {
            i++;
        }while(a[i] < pivotIdx);

        do{
            j--;
        }while(a[j] > pivotIdx);
        
        if(i<j)
            swap(a[i], a[j]);
    } while (i<j);
    swap(a[low], a[j]);
    return j;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int kthSmallest(vector<int>& a, int low, int high, int k){
    
    if (low >= high) {
        if (low == high){
            if (low == k)
                return a[k];
        }
        return -1;
    }
    
    else {
    // If k is smaller than the number of elements
        int pivotIdx = partition(a, low, high);
        if(k == pivotIdx - low + 1)
            return a[pivotIdx];
        else if(k < pivotIdx - low + 1){
            return kthSmallest(a, low, pivotIdx - 1, k);
        }
        else {
            return kthSmallest(a, pivotIdx + 1, high, k);
        }
    }  
     
}

int main(){
    vector<int> a {8,4,6,2,1,7,9,11,3};
    cout << "Kth Smallest Element: " << kthSmallest(a, 0, a.size()-1, 5) << endl;
}