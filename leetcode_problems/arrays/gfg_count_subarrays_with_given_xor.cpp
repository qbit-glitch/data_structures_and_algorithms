/**
 * GFG: Count Subarray with Given XOR
 * Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
*/

#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &a, int k){
    map<long, long> mpp;
    long preXOR = 0;
    mpp[preXOR]++;
    long count = 0;
    for(int i=0; i < a.size(); i++){
        preXOR = preXOR ^ a[i];
        int x = preXOR ^ k;
        count += mpp[x];
        mpp[preXOR]++;
    }
    return count;
}

int main(){
    vector<int> a{4, 2, 2, 6, 4};
    int k = 6;

    cout << subarrayXor(a,k) << endl;
}