#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;

    pq.push(11);
    pq.push(2);
    pq.push(5);
    pq.push(10);
    pq.push(21);

    cout << "Element at Top : " << pq.top() << endl;
    pq.pop();
    cout << "Element at Top : " << pq.top() << endl;
    cout << "Size is : " << pq.top() << endl;

    if(pq.empty()) {
        cout << "pq is empty" << endl;
    }
    else {
        cout << "pq is not empty" << endl;
    }


    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(11);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(10);
    minHeap.push(21);

    cout << "Element at Top : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Element at Top : " << minHeap.top() << endl;
    cout << "Size is : " << minHeap.top() << endl;

    if(minHeap.empty()) {
        cout << "minHeap is empty" << endl;
    }
    else {
        cout << "minHeap is not empty" << endl;
    }
}
