/**
 * Leetcode-1: Two Sum
 * 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &a, int k){
    int sum = 0;
    map<int, int> preSumMap = {{0,-1}};
    vector<int> res;
    for(int i=0; i< a.size(); i++){
        
        int rem = k - a[i];
        if(preSumMap.find(rem) != preSumMap.end()){
            res.insert(res.end(), {preSumMap[rem], i});
        }

        preSumMap[a[i]] = i;
    }
    return res;
}

void printArray(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> a{3,2,3};
    vector<int> res = twoSum(a, 6);
    printArray(res);
}
