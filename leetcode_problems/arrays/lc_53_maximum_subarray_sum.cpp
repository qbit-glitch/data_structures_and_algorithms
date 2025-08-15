/**
* Leetcode-53: Maximum Subarray Sum
*/

#include <bits/stdc++.h>
using namespace std;

void printSubArray(vector<int> &a, int start, int end){
    for(int i=start; i<=end; i++)
        cout << a[i] << " ";
    cout << endl;
}


int maxSubArray(vector<int> &a){
    int maxi = INT_MIN;
    int sum = 0, start = 0, ansStart = 0, ansEnd = 0;

    for(int i=0; i < a.size(); i++){

        sum += a[i];
        
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        
        if(sum < 0){
            sum = 0;
            start = i+1;
        }
    }

    printSubArray(a, ansStart, ansEnd);

    if (maxi < 0) return 0;
    return maxi;
}

int main(){
    vector<int> a{-71, 92, 0, 67, -8, 67, -78, -7};
    cout << maxSubArray(a) << endl;
}