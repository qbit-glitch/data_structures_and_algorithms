/**
 * Leetcode-904: Fruit into baskets
 * Link: https://leetcode.com/problems/fruit-into-baskets/description/
*/

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& a, int k) {
    unordered_map<int, int> mpp;

    int l=0, r=0, maxLen=0;
    while(r < a.size()){
        mpp[a[r]]++;
        if(mpp.size() > k){ 
            mpp[a[l]]--;
            if(mpp[a[l]] == 0)
                mpp.erase(a[l]);
            l++;
        }
        if(mpp.size() <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int totalFruit_Better(vector<int> &a, int k){
    unordered_map<int, int> mpp;

    int l=0, r=0, maxLen=0;
    while(r < a.size()){
        mpp[a[r]]++;
        if(mpp.size() > k){ 
            while(mpp.size() > k){
                mpp[a[l]]--;
                if(mpp[a[l]] == 0)
                    mpp.erase(a[l]);
                l++;
            }
        }
        if(mpp.size() <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}


int main(){
    vector<int> a{3,3,3,1,2,1,1,2,3,3,4};
    int k=2;
    cout << totalFruit(a, k) << endl;
}