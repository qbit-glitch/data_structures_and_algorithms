/** Code360: Merge two Binary Max heaps
 * Link: https://www.naukri.com/code360/problems/merge-two-binary-max-heaps_1170049
*/

#include <vector> 
#include <iostream>
using namespace std;


/** Algo : 
 * merge the two arrays
 * build max heap of the new array - using heapify
*/


void printHeap(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

void heapify(vector<int> &a, int n, int i){
    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[largest] < a[left])
        largest = left;
    if(right < n && a[largest] < a[right])
        largest = right;

    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}


vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Write your code here
    vector<int> res;

    // merge the two arrays
    for(auto &i: arr1)
        res.push_back(i);
    for(auto &i: arr2)
        res.push_back(i);

    // printHeap(res);
    // Build maxheap of the new array
    int length = res.size();

    for(int i = length/2-1; i>=0; i--){
        heapify(res, length, i);
    }
    // printHeap(res);
    return res;   
}


int main(){
    vector<int> a{10,5,6,2};
    vector<int> b{12,7,9};

    vector<int> c = mergeHeap(a.size(), b.size(), a, b);
    printHeap(c);
    
}