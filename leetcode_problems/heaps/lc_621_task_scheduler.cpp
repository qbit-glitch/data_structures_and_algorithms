/** Leetcode 621: Task Scheduler
 * Link: https://leetcode.com/problems/task-scheduler/
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(char &i: tasks){
            mp[i-'A']++;
        }
        int time = 0;
        priority_queue<int> maxHeap;
        for(int &i: mp){
            if(i > 0)   
                maxHeap.push(i);
        }

        while(!maxHeap.empty()){
            vector<int> temp;
            
            for(int i = 1; i <= n+1; i++){
                if(!maxHeap.empty()){
                    int freq = maxHeap.top();
                    maxHeap.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &i: temp){
                if(i > 0)
                    maxHeap.push(i);
            }

            if(maxHeap.empty()){
                time += temp.size();
            } else {
                time += n+1;
            }
            cout << time << " ";
        }
        cout << time << endl;
        return time;
        
    }
};

int main(){
    vector<char> tasks{'A', 'B', 'C', 'D', 'A', 'B'};
    Solution sol;

    cout << sol.leastInterval(tasks, 1) << endl;
}