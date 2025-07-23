#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int partition(vector<int>& a, int low, int high){
    int pivot = a[low];
    int i = low, j = high+1;
    do {
        do {
            i++;
        } while(a[i] < pivot);
        do {
            j--;
        } while(a[j] > pivot);
        if (i<j)
            swap(a[i], a[j]);
    } while(i < j);

    swap(a[low], a[j]);
    return j;
}

void quicksort(vector<int> &a, int low, int high){
    if(low < high){

        int min_range = low;
        int max_range = high;
        int randomIndex = min_range + (rand() % (max_range - min_range + 1));

        swap(a[randomIndex], a[low]);

        int j = partition(a, low, high);
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);

    }
}

void printVector(vector<int> &a){
    for(auto i: a)
        cout << i << " ";
    cout <<  endl;
}

int main(){
    vector<int> a {40,35, 25, 10, 20};
    
    cout << "Before Quicksort: ";
    printVector(a);
    
    quicksort(a, 0, a.size() - 1);

    cout << "After Quicksort: ";
    printVector(a);
}