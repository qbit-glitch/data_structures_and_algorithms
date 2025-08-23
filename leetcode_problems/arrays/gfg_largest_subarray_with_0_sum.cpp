/**
 * GFG: Largest Subarray with 0 Sum
 * Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

#include <bits/stdc++.h>
using namespace std;

int maxLength_Better(vector<int> &a){
    int maxLen = 0;

    for(int i=0; i< a.size(); i++){
        int sum = 0;
        for(int j=i; j<a.size(); j++){
            sum += a[j];
            if(sum == 0){
                int l = j-i+1;
                if(l > maxLen)
                    maxLen = l;
            }
        }
    }
    return maxLen;
}

int maxLength_Optimal(vector<int> &a){
    map<int,int> mpp;
    int preSum = 0, maxLen = 0;
    int target = 0;
    for(int i=0; i<a.size(); i++){
        preSum += a[i];

        if(preSum == target){
            maxLen = i + 1;
        }

        int rem = preSum - target;
        if(mpp.find(rem) != mpp.end()){
            maxLen = max(maxLen, i-mpp[rem]);   
        }

        if(mpp.find(preSum) == mpp.end())
            mpp[preSum] = i;
    }
    return maxLen;
}


int main(){
    vector<int> a {2, 10, 4, 0,0,0,-1,1};
    cout << maxLength_Optimal(a) << endl;
}