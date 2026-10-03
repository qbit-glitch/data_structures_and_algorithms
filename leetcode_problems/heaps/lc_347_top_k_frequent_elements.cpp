/** Leetcode-347: Top K Frequent Elements
 * Link: https://leetcode.com/problems/top-k-frequent-elements/description/
*/

#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

void printVector(vector<int> &nums){
    for(auto &i: nums)
        cout << i << " ";
    cout << endl;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;
        vector<int> kfreq;
        for(int &i: nums)
            freqCount[i]++;

        priority_queue<pair<int, int>> pq;  // (freq, val) -> coz maxHeap is automatically without needing the use of custom comparator because the default stl use the pair.first element

        for(auto &i: freqCount){
            pq.push({i.second, i.first});
        }

        for(int i=k; i>0; i--){
            if(!pq.empty()){
                kfreq.push_back(pq.top().second);
                pq.pop();
            }
        }
        return kfreq;
    }
};

int main(){
    vector<int> nums{1,2,1,2,1,2,3,1,3,2};
    Solution sol;
    auto result = sol.topKFrequent(nums, 2);
    printVector(result);
}
