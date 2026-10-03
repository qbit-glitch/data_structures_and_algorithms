/** Leetcode-846: Hand of Straights
 * Link: https://leetcode.com/problems/hand-of-straights/description/
*/

#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;



/* THinking :
    - The base case is very easy, divide the length by group size, if there is remainder => false
    - The hard part is the consecutive numbers
    - what if :
        - i create a map<number, freq> and create a minHeap of this based on the number
        - then pop from the minHeap until size == group size, and if the element in the array != minHeap.top() - 1 => Not a consecutive number right ??
*/


/* Example :
    Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
    Output: true
    Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
*/

class comparator{
public:
    bool operator()(pair<int, int> a, pair<int,int> b){
        return a.first > b.first;
    }
};


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(!(hand.size() % groupSize == 0))
            return false;


        map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> minHeap;

        // Store the frequency of each element
        for(int &i: hand){
            mp[i]++;
        }

        // Store the map in priority queue - minHeap
        for(auto& it: mp){
            minHeap.push(pair<int, int>(it.first, it.second));
        }
        vector<vector<int>> ans;

        while(!minHeap.empty()){
            vector<pair<int, int>> temp;
            

            for(int i=0; i<groupSize; i++){
                pair<int, int> node = minHeap.top();
                minHeap.pop();
                
                node.second--;

                if(temp.size() == 0)
                    temp.push_back(node);
                else{
                    if(temp[temp.size()-1].first + 1 == node.first)              
                        temp.push_back(node);
                    else
                        return false;
                }
            }

            for(auto &i: temp){
                if(i.second > 0)
                    minHeap.push(i);
            }
        }
        return true;
    }
};

int main(){
    vector<int> hand1{1,2,3,6,2,3,4,7,8};
    Solution sol;

    cout << sol.isNStraightHand(hand1, 3) << endl;

    vector<int> hand2{1,2,3,4,5};
    cout << sol.isNStraightHand(hand2, 3) << endl;
    
}