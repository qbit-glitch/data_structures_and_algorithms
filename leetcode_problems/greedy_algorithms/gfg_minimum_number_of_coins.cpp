/**
 * GFG: Minimum Number Of Coins
 * Link: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(int n) {
    vector<int> coins {10,5,2,1};
    int total_coins = 0;
    for(int &i: coins){
        int q = n/i;
        if(q != 0){
            total_coins += q;
            n = n - i*q;
        }
    }
    return total_coins;
}

int main(){
    cout << findMin(39) << endl;
}