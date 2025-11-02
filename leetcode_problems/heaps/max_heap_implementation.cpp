/**
 * Max Heap Implementation
*/

#include <bits/stdc++.h>
using namespace std;

/** Some Notes:
 * 1. In 0-based indexing: leafnodes: 2i+1, 2i+2 | parentNode = (i-1)/2
 * 2. 
*/



class MaxHeap{
private:
    vector<int> a;
    int size=0;

public:
    MaxHeap(){
        a = vector<int> (100, 0);
        size = 0;
    }

    void insert(int val){
        int i = size;
        while(i > 0 and a[(i-1)/2] < val){
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

    int deleteFromHeap(){
        int maxVal = a[0];
        a[0] = a[size-1];
        size--;
        adjust(a, 0, size-1);
        return maxVal;
    }

    void adjust(vector<int>& a, int i, int n){
        int item = a[i];
        int j = 2*i+1;
        while(j <= n){
            if(j < n and a[j] < a[j+1])
                j++;
            if(a[j] <= item)
                break;
            a[(j-1)/2] = a[j];
            j = 2*j + 1;
        }
        a[(j-1)/2] = item;
    }
};

int main(){
    MaxHeap mh;
    mh.insert(10);
    mh.insert(20);
    mh.insert(30);
    mh.insert(40);
    mh.insert(25);
    mh.insert(15);
    mh.print();

    cout << mh.deleteFromHeap() << endl;
    mh.print();


    cout << mh.deleteFromHeap() << endl;
    mh.print();
}