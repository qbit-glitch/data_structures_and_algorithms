/**
 * Code360: Implement Min Heap
 * Link: https://www.naukri.com/code360/problems/min-heap-implementation_5480527
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> a;
    int size;

public:
    // Constructor for the class.
    MinHeap(){
        a = vector<int>(100,0);
        size = 0;
    }

    void adjust(vector<int> &a, int i, int n){
        int j = 2*i+1;
        int item = a[i];
        while(j <= n){
            if(j<n and a[j] > a[j+1])
                j++;
            if(a[j] > item)
                break;
            a[(j-1)/2] = a[j];
            j = 2*j+1;
        }
        a[(j-1)/2] = item;
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        int minVal = a[0];
        a[0] = a[size-1];
        size--;
        adjust(a, 0, size-1);
        return minVal;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        a[ind] = a[size-1];
        size--;
        adjust(a, ind, size-1);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        int i = size;
        while(i > 0 and a[(i-1)/2] > val){
            a[i] = a[(i-1)/2];
            i = (i-1)/2;
        }
        a[i] = val;
        size++;
    }

    void print(){
        for(int i=0; i<size; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main(){
    MinHeap mh;
    
    mh.insert(10);
    mh.insert(20);
    mh.insert(30);
    mh.insert(40);
    mh.insert(25);
    mh.insert(15);
    mh.print();

    cout << mh.extractMinElement() << endl;
    mh.print();


    cout << mh.extractMinElement() << endl;
    mh.print();

    mh.deleteElement(1);
    mh.print();
}