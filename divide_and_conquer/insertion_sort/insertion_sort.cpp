#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a);

void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i < n-1 ; i++){
        int item = arr[i+1];
        int j = i;

        while(j >= 0 and item < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = item;
    }
    printArray(arr);
}

void printArray(vector<int> &a){
    for (auto &i: a){
        printf("%d ", i);
    }
    cout << endl;
}

int main(){
    vector<int> arr {60,50,20,10,30,80,40,50};
    insertionSort(arr);
    printArray(arr);
}