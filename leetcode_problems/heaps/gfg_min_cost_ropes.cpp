/** GFG : Minimum cost to connect Ropes
 * Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
  public:
    void printHeap(priority_queue<int, vector<int>, greater<int>> minHeap) {
        while(!minHeap.empty()){
            cout << minHeap.top() << " ";
            minHeap.pop();
        }
        cout << endl;
    }

    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto &i: arr)
            minHeap.push(i);

        int minSum = 0;
        while(!minHeap.empty()){
            printHeap(minHeap);
            int a = minHeap.top(); minHeap.pop();
            int b = minHeap.top(); minHeap.pop();

            if(minHeap.size() != 0)
                minHeap.push(a+b);

            minSum += a+b;
        }
        return minSum;
    }
};

int main(){
    vector<int> a{4,2,6,7,9};
    Solution sol;
    cout << sol.minCost(a) << endl;
}