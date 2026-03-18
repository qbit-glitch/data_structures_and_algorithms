/**
 * Array Representation of Binary Tree in C++
*/

#include <iostream>
#include <vector>
using namespace std;


template <typename T>

struct BinaryTree {
    vector<T> data;
    int size;

    BinaryTree(int capacity) {
        data.resize(capacity+1);
        size = 0;
    }

    int insert(T value) {
        size += 1;
        data[size] = value;
        return size;
    }

    int getSize() {
        return size;
    }

    int deleteNode(int idx) {
        data[idx] = data[size];
        data.erase(data.begin() + size);
        size--;
        return size;
    }

    int search(T value) {
        for(int i=1; i<=size; i++){
            if(data[i] == value)
                return i;
        }   
        return -1;
    }

    void preOrder(vector<T> &res, int idx) {        
        if(idx > size) {
            return;
        }
        res.push_back(data[idx]);
        preOrder(res, 2*idx);
        preOrder(res, 2*idx+1);
    }


    void inOrder(vector<T> &res, int idx) {
        if(idx > size) {
            return;
        }
        inOrder(res, 2*idx);
        res.push_back(data[idx]);
        inOrder(res, 2*idx+1);
    }


    void postOrder(vector<T> &res, int idx) {
        
        if(idx > size) {
            return;
        }
        postOrder(res, 2*idx);
        postOrder(res, 2*idx+1);
        res.push_back(data[idx]);
    }
};


template <typename T>
void printBinaryTree(BinaryTree<T> bt){
    printf("Size of Binary Tree: %d\n", bt.size);
    for(auto &i: bt.data){
        cout << i << " | ";
    }
    cout << endl;
}


template <typename T>
void printVector(vector<T> a) {
    for(auto &i: a){
        cout << i << " | ";
    }
    cout << endl;
}


int main(){
    BinaryTree<int> bt(5);
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    printBinaryTree(bt);

    vector<int> preOrderRes, postOrderRes, inOrderRes;
    bt.preOrder(preOrderRes, 1);
    bt.inOrder(inOrderRes, 1);
    bt.postOrder(postOrderRes, 1);

    printVector(preOrderRes);
    printVector(inOrderRes);
    printVector(postOrderRes);
    
}


