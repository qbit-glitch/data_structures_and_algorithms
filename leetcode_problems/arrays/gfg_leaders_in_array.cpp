/**
 * GFG: Leaders in an Array
 * Link: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &a){
    vector<int> leadersArray;
    int prev_leader = a[a.size()-1];
    leadersArray.push_back(prev_leader);
    for(int i = a.size()-2; i >= 0; i--){
        if(a[i] >= prev_leader){
            leadersArray.insert(leadersArray.begin(),a[i]);
            prev_leader = a[i];
        }
    }
    return leadersArray;
}

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{16,17,4,3,5,2};
    auto b = leaders(a);
    printArray(b);
}