#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void merge(vector<int>& arr, int low, int mid, int high);

void printVector(vector<int> arr){
  for(int i: arr){
    cout << i << " ";
  }
  cout << endl;
}

void mergeSort(vector<int> &arr, int low, int high){
  // arr[low, high] --> Array of elements
  
  if(low < high){
    int mid = (low + high) / 2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1, high);

    // conquer
    merge(arr,low,mid,high);
  }
}

void merge(vector<int>& arr, int low, int mid, int high){
  int size = high - low + 1;
  int i = low;
  int j = mid+1;
  int k = low;
  vector<int> b(size);

  while (i<= mid && j <= high){
    if(arr[i] < arr[j]){
      b[k] = arr[i];
      i++;
    }
    else {
      b[k] = arr[j];
      j++;
    }
    k++;
  }

  if (i > mid) {
    for(int l=j; l<=high; l++){
      b[k] = arr[l];
      k++;
    }
  }

  if (j > high) {
    for(int l=i; l<= mid; l++){
      b[k] = arr[l];
      k++;
    }
  }

  for(int l=low; l<=high; l++){
    arr[l] = b[l];
  }


}



int main(){
  vector<int> arr {25,15,60,30,8,4,5,90,65,30,60};
  cout << "Vector before merge sort : ";
  printVector(arr);

  mergeSort(arr, 0, arr.size()-1);
  cout << "Vector after merge sort : ";
  printVector(arr);

}

