/** Leetcode-1331: Rank Transform of an Array
 * Link: https://leetcode.com/problems/rank-transform-of-an-array/description/
*/

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> rankMap;  // (element, freq)
        set<int> setOfUniqueElements;
        
        for(auto &i: arr){
            setOfUniqueElements.insert(i);
        }

        int count = 1;
        for(auto &i: setOfUniqueElements){
            rankMap[i] = count++;
        }

        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(rankMap[arr[i]]);
        }
        return ans;
    }
};

int main(){
    vector<int> a{37,12,28,9,100,56,80,5,12};
    Solution sol;
    vector<int> result = sol.arrayRankTransform(a);

    for(auto &i: result){
        cout << i << " ";
    } cout << endl;
}