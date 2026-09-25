#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;

        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        } cout << endl;
    }

    void delete_node(){
        /** Note: Deleting a node from Heap means deleting the root node. Steps :
         * 1. Swap first node and last node
         * 2. Remove last node
         * 3. Propagate root node in it's correct position
        */

        if(size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }

        // Put the last element into first index
        arr[1] = arr[size];

        // remove the last element
        size--;

        // take root node to its correct position
        int i = 1;
        while(i < size){
            int leftChild = 2*i;
            int rightChild = 2*i + 1;

            if(leftChild < size and arr[i] < arr[leftChild]){
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if(rightChild < size and arr[i] < arr[rightChild]){
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else {
                return;
            }
        }

    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);


    h.print();

    h.delete_node();
    h.print();
}