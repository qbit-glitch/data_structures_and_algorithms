/** Code360: Median in a Stream
 * Link: https://www.naukri.com/code360/problems/median-in-a-stream_975268
*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


/* Approach : 
    - We are trying to divide the array into two parts along the median 
    - as the input arrives we will have two choices to insert the element
        - Left
        - Right
    - So there are three cases which are possible :
        1. ---(n-1)--- M ----(n)----
        2. ----(n)---- M ---(n-1)---
        3. ----(n)---- M ----(n)----
        and we have to handle them separately
    - Use the signum function
        signum(a,b) : 0 if a == b
                      1 if a > b
                     -1 if a < b
    - so handle the number of elements on both sides of the median via 
        this signum function

*/ 


int signum(int a, int b){
    if(a == b)
        return 0;
    else if(a > b)
        return 1;
    else
        return -1;
}

void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median){
    switch(signum(maxHeap.size(), minHeap.size())){
        case 0: // maxHeap.size == minHeap.size : n, n
            if(element > median){
                minHeap.push(element);  // size becomes n+1, so median lies here
                median = minHeap.top();
            } else {
                maxHeap.push(element);  // size of maxHeap becomes n+1, so median lies here
                median = maxHeap.top();
            }
            break;
        case 1: // maxHeap.size > minHeap.size : n, n-1
            if(element > median){ // insert into minHeap
                minHeap.push(element);
                median = (minHeap.top() + maxHeap.top())/2;
            } 
            else { // insert into maxHeap since element < median, but since size will become n+1, n-1, it will be not be possible to find the median using minHeap.top and maxHeap.top, hence transfer one element from maxHeap to minHeap
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
                median = (minHeap.top() + maxHeap.top())/2;
            }
            break;
        case -1:
            if(element > median){ // insert into minHeap, but size will become n-1, n+1, hence move one element from minHeap to maxHeap
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
                median = (minHeap.top() + maxHeap.top())/2;
            }
            else { // insert into maxHeap, size becomes n,n
                maxHeap.push(element);
                median = (minHeap.top() + maxHeap.top())/2;
            }
            break;
    }
}


vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;

    for(int i=0; i<arr.size(); i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{1,2,3};

    printArray(a);

    vector<int> medianStreamArray = findMedian(a, a.size());
    printArray(medianStreamArray);
}