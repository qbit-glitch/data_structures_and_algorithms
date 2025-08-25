/**
 * Leetcode-56: Merge Intervals
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &a){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++){
        if(ans.empty() || a[i][0] >= ans.back()[1])
            ans.push_back(a[i]);
        else
            ans.back()[1] = max(ans.back()[1], a[i][1]);
    }
    return ans;
}

void print2DVector(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<int>> a{{1,3}, {2,6}, {8,10}, {15,18}};
    auto ans = mergeIntervals(a);
    print2DVector(ans);
}