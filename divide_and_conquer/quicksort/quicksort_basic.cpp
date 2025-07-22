#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partitionFirstElementAsPivot(vector<int>& a, int low, int high);
void printVector(vector<int> &a);
int partitionLastElementAsPivot(vector<int>& a, const int low, const int high);
int partitionFirstElementAsPivot2(vector<int> &a, int low, int high);

void swap(int& a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int> &a, int low, int high){
    if(low < high){
        int j = partitionFirstElementAsPivot2(a, low, high);
        quickSort(a, low, j-1);
        quickSort(a, j+1, high);
    }
}


int partitionLastElementAsPivot(vector<int> &a, const int low, const int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(a[j] <= pivot){
            i++;    // increment index of smaller element
            cout << "Swapping: " << a[i] << " and " << a[j] << endl;
            swap(a[i], a[j]);           
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

int partitionFirstElementAsPivot(vector<int> &a, int low, int high){
    int pivot = a[low];
    int i = high + 1;
    for(int j=high; j > low; j--){
        if(a[j] >= pivot) {
            i--;
            swap(a[j], a[i]);
        }
    }
    swap(a[i-1], a[low]);
    return i-1;
}

int partitionFirstElementAsPivot2(vector<int> &a, int low, int high){
    int pivot = a[low];
    int i = low, j = high+1;
    do {
        do{
            i++;
        } while(a[i] < pivot);

        do{
            j--;
        } while(a[j] > pivot);

        if(i<j){
            swap(a[i], a[j]);
        }
    } while(i < j);

    swap(a[low], a[j]);
    return j;
}



void printVector(vector<int> &a){
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> a {40,35, 25, 10, 20};
    
    cout << "Before Quicksort: ";
    printVector(a);
    
    quickSort(a, 0, a.size() - 1);

    cout << "After Quicksort: ";
    printVector(a);
}