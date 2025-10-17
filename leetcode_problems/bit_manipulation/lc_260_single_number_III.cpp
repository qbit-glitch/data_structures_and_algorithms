/**
 * Leetcode-260: Single Number-III
 * Link: https://leetcode.com/problems/single-number-iii/description/
*/

#include <bits/stdc++.h>
using namespace std;



/** A simple thought process
 * 1. Do XOR of all numbers
 * 2. Find the rightmost set bit of the XOR
 * 3. if((nums[i] & rightmost) != 0)
 *          transfer all numbers to bucket 1 and do XOR for all numbers in bucket 2
 *    else
 *          transfer all numbers to bucket 2 and do XOR for all numbers in bucket 2
*/
vector<int> singleNumber(vector<int>& nums) {
    long res = 0;
    for(int i=0; i<nums.size(); i++){
        res ^= nums[i];
    }

    long rightmost = (res & (res-1)) ^ res;
    int b1=0, b2=0;
    for(int i=0; i<nums.size(); i++){
        if((nums[i] & rightmost) != 0)
            b1 ^= nums[i];
        else
            b2 ^= nums[i];
    }
    return {b1,b2};
}

void printVector(vector<int> &res){
    for(int &i: res)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{2,4,2,7,3,7,3,6};
    vector<int> result = singleNumber(a);
    printVector(result);
}