#include <bits/stdc++.h>
using namespace std;

void insertionSortRecursive(vector<int> &arr, int n){
    // We have assumed arr is already sorted in 0 to n-1 and now we want to insert n
    if (n == 1){
        return;
    }
    insertionSortRecursive(arr, n-1);
    
    int item = arr[n-1];
    int j = n-2;
    while(j >= 0 and arr[j] > item){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = item;
}

void printArray(vector<int> &arr){
    for (auto &i : arr){
        printf("%d ", i);
    }
    cout << endl;
}

int main(){
    vector<int> arr {60,50,20,10,30,80,40,50};
    insertionSortRecursive(arr, arr.size());
    printArray(arr);
}