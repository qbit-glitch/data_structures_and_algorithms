/**
 * GFG: Row with Max 1s
 * Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
*/

#include <bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int> &a, int k){
    int low = 0, high = a.size();
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == k){
            if(a[mid] == k and a[mid-1] == k)
                high = mid-1;
            else
                return mid;
        }
        else if(a[mid] > k)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}



int rowWithMax1s(vector<vector<int>> &arr) {
    // code here
    int ans = INT_MIN, ansIdx = -1;
    for(int i=0; i<arr.size(); i++){
        int ind1 = firstOccurance(arr[i], 1);
        int numberOfOnes = arr[i].size() - ((ind1 != -1) ? ind1 : INT_MAX);
        if(ans < numberOfOnes){
            ansIdx = i;
            ans = numberOfOnes;
        }
    }
    return ansIdx;
}

int main(){
    vector<vector<int>> arr {{0,0,1,1}, {0,1,1,1}, {1,1,1,1}, {0,0,0,0}};
    cout << rowWithMax1s(arr) << endl;
}