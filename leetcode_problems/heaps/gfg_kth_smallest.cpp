/** GFG: Kth Smallest element
 * Link : https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
 */


/** For kth smallest, use maxHeap data structure coz 
 *  we are sorting k elements in descending order
 * Steps :
 * 1. Build maxHeap from first K elements
 * 2. For rest of the elements
 *      - if element < heap.top()
 *              heap.pop()
 *              heap.push()     // push the small element in the max heap
 *                              // So that the max heap contains only the small elements
 * 3. When all iterations are completed, Heap will contain the K smallest elements
 *      - Among those small elements, the max element will be present at the root of max heap
 *      - hence, the Kth smallest element will be the root of maxHeap
 *              
 *      
*/


// NOTE: When finding kth smallest element use max heap so that 
// among the k small elements, the max of them would lie on the 
// root of the max heap

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // convert first k elements into max heap
        priority_queue<int> maxHeap;
        for(int i=0; i<k; i++){
            maxHeap.push(arr[i]);
        }

        for(int i=k; i<arr.size(); i++){
            if(maxHeap.top() > arr[i]){
                // Pop the max value and Push the smaller value into the heap
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }

        // Now the heap contains only the k small elements, 
        // and the max of them is the root, therefore the kth smallest is the root
        return maxHeap.top();
    }
};





int main(){
    vector<int> arr{10,5,4,3,48,6,2,33,53,10};
    Solution sol;
    cout << sol.kthSmallest(arr, 4) << endl;
    cout << sol.kthSmallest(arr, 1) << endl;
    cout << sol.kthSmallest(arr, 6) << endl;
}