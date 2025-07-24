#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int mooresVoting(const vector<int>& a, int low, int high){
    int cand = a[low];
    int count = 1;
    for(int i=low+1; i<high; i++){
        if(a[i] == cand)
            count++;
        else {
            count--;
            if(count == 0){
                cand = a[i];
                count = 1;
            }
        }
    }
    return cand;
}

pair<bool,int> majorityElementWithMooresVoting(const vector<int> &a, int low, int high){
    int cand = mooresVoting(a, low, high);
    int count = 0;
    for(auto i: a){
        if(cand == i)
            count++;
    }
    if(count >= (high-low)/2)
        return make_pair(true,cand);
    else 
        return make_pair(false,cand);
}

int main(){
    vector<int> a{2,2,4,4,4,4,4,4,8,8,10};
    pair<bool, int> result = majorityElementWithMooresVoting(a, 0, a.size()-1);
    cout << result.first << " " << result.second << endl;
}