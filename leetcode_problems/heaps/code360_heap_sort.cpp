/** Code360: Heap Sort
 * Link : https://www.naukri.com/code360/problems/heap-sort_1262153
*/


#include <iostream>
#include <vector>
using namespace std;


// Since I want to sort in ascending order, I'll build max-heap
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if(leftChild < n and arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild < n and arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &a, int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(a, n, i);
    }
}

// Let's assume it is a zero based indexing
vector<int> heapSort(vector<int>& arr, int n) {
    /** Steps
     * 1. Swap root node and last node
     * 2. Move the root node to it's correct position -> Heapify on that node
    */
    int size = n;

    buildHeap(arr,n);

    while(size > 0) {
        swap(arr[size-1], arr[0]);
        size--;

        heapify(arr, size, 0);
    }
    return arr;
}
 


void printHeap(vector<int> &arr){
    for(auto &i: arr){
        cout << i << " ";
    } cout << endl;
}

int main(){
    vector<int> a{5, -2, 3, -1, 8};
    int n = a.size();

    printHeap(a);

    buildHeap(a, n);
    
    printHeap(a);
    
    heapSort(a,n);
    printHeap(a);
}