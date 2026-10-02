/** Code360: Merge K sorted arrays 
 * Link: https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379
 * Very Very Important Question
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;


/* Approach :
    - minHeap : consisting of the first element of each array
    - minHeap -> top : ans array me daal dena
                     : insert next element of the same array into heap if present
    - iterate this while minHeap.size() >  0 
*/

class Node{
public:
    int data;
    int i;
    int j;

    Node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Step 1: saare arrays ke first element ko heap me insert kar do
    for(int i=0; i<k; i++){
        Node* tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    // Step 2:
    vector<int> ans; 

    while(!minHeap.empty()){
        Node* n = minHeap.top();
        minHeap.pop();

        ans.push_back(n->data);

        int i = n->i;
        int j = n->j;
        
        if(j+1 < kArrays[i].size()){
            Node* newNode = new Node(kArrays[i][j+1], i, j+1);
            minHeap.push(newNode);
        }
    }
    return ans;
}


void printArray(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<vector<int>> a{{3,5,9}, {1,2,3,8}};
    auto res = mergeKSortedArrays(a, 2);

    printArray(res);
}

