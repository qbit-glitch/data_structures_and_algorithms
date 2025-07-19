#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& a, int low, int mid, int high);

void mergeSort(vector<int>& a, int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);

        // Merge the parts
        merge(a, low, mid, high);
    }
}

void merge(vector<int>& a, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int size = high - low + 1;

    while (i <= mid && j <= high){
        if(a[i] > a[j]){
            int temp = a[j];
            for(int t = j; t >= i+1; t--){
                a[t] = a[t-1];
            }
            a[i] = temp;
            j++;
        }
        else {
            i++;
        }
    }
}

void printVector(vector<int>& a){
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
}


int main(){
    vector<int> arr {25,15,60,30,8,4,5,90,65,30,60};
    cout << "Vector before merge sort : ";
    printVector(arr);

    mergeSort(arr, 0, arr.size()-1);
    cout << "Vector after merge sort : ";
    printVector(arr);    
}