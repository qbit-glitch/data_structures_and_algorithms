/** Leetcode-215: Kth largest Element in an Array
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/**
 * Since we have to find the kth largest element, hence we will use minHeap.
 * coz for every rest of the n-k elements, we will update the heap with the min of the heap ka top and the ith element
 * Hence after all the iterations, the max K elements will be present in
 * minHeap with the kth smallest element present at the top of the minHeap
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Syntax : priority_queue<type, container, comparator>
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0; i<k; i++){
            minHeap.push(nums[i]);
        }

        for(int i=k; i<nums.size(); i++){
            if(minHeap.top() < nums[i]){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};

int main(){
    vector<int> a{3,2,3,1,2,4,5,5,6};
    Solution sol;
    cout << sol.findKthLargest(a, 4) << endl;
    cout << sol.findKthLargest(a, 4) << endl;
    cout << sol.findKthLargest(a, 6) << endl;
}