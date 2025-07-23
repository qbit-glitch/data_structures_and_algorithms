#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

// Function declarations
int medianOfMedians(vector<int>&, int, int);
void swap(int&, int&);
void quickSort(vector<int>&, int, int);
int partitionFirstElementAsPivot(vector<int>&, int, int);



int medianOfMedians(vector<int>& a, int low, int high){
    
    if(high-low+1 <= 5){
        vector<int> r (a.begin()+low, a.begin()+high+1);
        sort(r.begin(), r.end());
        return r[r.size()/2];
    }

    vector<int> mediansArray;
    int windowSize = 5;
    for(int i=low; i<= high; i += windowSize){
        int endIndex = min(i+windowSize, (int)a.size());
        vector<int> auxArray = vector<int>(a.begin()+i, a.begin() + endIndex);
        sort(auxArray.begin(), auxArray.end());
        mediansArray.push_back(auxArray[auxArray.size()/2]);
    }
    return medianOfMedians(mediansArray, 0, mediansArray.size()-1);
}

void swap(int& a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int> &a, int low, int high){
    if(low < high){
        int median = medianOfMedians(a, low, high);
        cout << "Median: " << median << endl;
        int k = distance(a.begin(), find(a.begin()+low, a.begin()+high, median));
        
        swap(a[k], a[low]);
        int j = partitionFirstElementAsPivot(a, low, high);
        quickSort(a, low, j-1);
        quickSort(a, j+1, high);
    }
}

int partitionFirstElementAsPivot(vector<int>& a, int low, int high){
    int pivot = a[low];
    int i = low, j = high+1;

    do{
        do{
            i++;
        } while(a[i] < pivot);

        do{
            j--;
        } while(a[j] > pivot);

        if (i < j)
            swap(a[i], a[j]);
    } while (i < j);

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
    vector<int> a{8,4,6,2,1,7,9,11,3};
    cout << "Before Quicksort: ";
    printVector(a);
    
    quickSort(a, 0, a.size() - 1);

    cout << "After Quicksort: ";
    printVector(a);
}