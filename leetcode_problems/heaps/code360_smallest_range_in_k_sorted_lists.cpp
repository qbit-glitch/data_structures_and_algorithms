/** Code360: Smallest Range in K sorted Lists
 * Link: https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356
*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/* Algo :
    - Create a min Heap for starting element of each list and track the mini / maxi values
    - process ranges
        - mini fetch
        - range or answer updation
        - next element exists or not
    - returning the difference between the range

*/

class Node{

public:
    int data;
    int i;
    int j;

    Node(int data, int i, int j): data(data), i(i), j(j){}
};

class compareMin{
public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here
    priority_queue<Node*, vector<Node*>, compareMin> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;

    for(int i=0; i < a.size(); i++){
        Node* node = new Node(a[i][0], i, 0);
        minHeap.push(node);
        mini = min(mini, node->data);
        maxi = max(maxi, node->data);
    }

    int start = mini, end = maxi;

    while(!minHeap.empty()){
        Node* minNode = minHeap.top();
        minHeap.pop();

        if(maxi - minNode->data < end - start){
            start = minNode->data;
            end = maxi;
        }

        int i = minNode->i;
        int j = minNode->j;
        if(minNode->j + 1 < n){
            Node* newNode = new Node(a[i][j + 1], i, j+1);
            minHeap.push(newNode);
            maxi = max(maxi, a[i][j+1]);
        } else {
            break;
        }   
    }
    return (end - start + 1);
}

int main(){
    vector<vector<int>> a{{1,10,11}, {2,3,20}, {5,6,12}};
    cout << kSorted(a, 3, 3) << endl;
}