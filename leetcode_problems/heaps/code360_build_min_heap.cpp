/** Code360: Build Min Heap
 * Link: https://www.naukri.com/code360/problems/build-min-heap_1171167
*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int smallest = i;

    int leftChild = i*2+1;
    int rightChild = i*2 + 2;

    if(leftChild < n and arr[smallest] > arr[leftChild]){
        smallest = leftChild;
    }
    if(rightChild < n and arr[smallest] > arr[rightChild]){
        smallest = rightChild;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}



vector<int> buildMinHeap(vector<int> &arr){
    int n = arr.size();

    for(int i=n/2; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
}

void printHeap(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    } cout << endl;
}

int main(){
    vector<int> a{9,3,2,6,7};

    printHeap(a);
    buildMinHeap(a);
    printHeap(a);

    vector<int> b{8,9,0};

    printHeap(b);
    buildMinHeap(b);
    printHeap(b);
}