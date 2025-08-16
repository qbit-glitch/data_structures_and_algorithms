/**
 * Leetcode-31: Next Permutation
*/
#include <bits/stdc++.h>
using namespace std;

void nextGreaterPermutation(vector<int> &a){
    int ind = -1;
    int n = a.size();
    for(int i=n-2; i>=0; i--){
        if(a[i] < a[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(a.begin(), a.end());
        return;
    }

    for(int i=n-1; i>ind; i--){
        if(a[ind] < a[i]){
            swap(a[ind], a[i]);
            break;
        }
    }
    reverse(a.begin()+ind+1, a.end());
    return;
}

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{1,2,3,4,5,6};
    nextGreaterPermutation(a);
    printArray(a);    
}