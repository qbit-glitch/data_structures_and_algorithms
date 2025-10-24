/**
 * Leetcode-239: Sliding Window Maximum
 * Link: https://leetcode.com/problems/sliding-window-maximum/description/
*/

#include <bits/stdc++.h>
using namespace std;

/** Thought Process:
 * 1. We need a data structure to keep k elements window
 * 2. We need to define a monotonic stack, through 
 *      which we can keep track of the second greatest element.
 * 3. The Data Structure which meets the above requirements -> DeQueue
 * 4. Algo :
 *      - push element into deque
 *      - if dq.front() == i-k  => k+1 elements --> pop from front
 *      - while a[dq.back()] < a[i] -> ith element is the greatest  
 *          => pop the smaller elements
 *      - the front of dequeue will keep track of the maximum of the elements in the deque
 *      - if num of elements == k :  start adding the front of deque into the vector
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++){
        if(!dq.empty() and dq.front() <= i-k)
            dq.pop_front();
        while(!dq.empty() and nums[dq.back()] < nums[i]){
            dq.pop_back();
        }    
        dq.push_back(i);
        if(i >= k-1)
            ans.push_back(nums[dq.front()]);
    }    
    return ans;
}

void printVector(vector<int> &a){
    for(int &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(a, 3);
    printVector(res);
}