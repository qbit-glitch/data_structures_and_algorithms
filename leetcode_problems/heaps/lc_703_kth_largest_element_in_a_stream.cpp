/** Leetcode-703: Kth largest element in a stream
 * Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;



/* Some thinking :
    - during the initialization, I will run the program for the kth largest element using minHeap on n numbers
    - when the new number enters, I'll just compare the number with the minHeap.top()
        - if newNumber > minHeap.top() -> insert the new number in minHeap
        - else -> don't do anything to the minHeap
    - Some corrections :
        - Priority queue has to have atmax k elements
        - but if the pq has < k elements -> push the new element inside the pq unless pq.size() < k
        - other wise check on the top element of the pq and the new value
*/



class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int &i: nums){
            if(pq.size() < k)
                pq.push(i);
            else if(i > pq.top()){
                pq.pop();
                pq.push(i); 
            }
        }
        
    }
    
    int add(int val) {
        
        if(pq.size() < k)
            pq.push(val);

        else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
*/

int main(){
    vector<int> nums{};
    KthLargest* obj = new KthLargest(2, nums);
    cout << obj->add(2) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(9) << endl;
}