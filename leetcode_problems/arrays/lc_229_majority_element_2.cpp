/**
 * Leetcode-229: Majority Element 2
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &a){
    vector<int> ans;
    map<int, int> hashMap;
    for(auto &i: a){
        hashMap[i]++;
    }
    for(auto i: hashMap){
        if(i.second > a.size()/3)
            ans.push_back(i.first);
    }
    return ans;
}

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{3,2,3};
    vector<int> ans = majorityElement(a);
    printArray(ans);
}