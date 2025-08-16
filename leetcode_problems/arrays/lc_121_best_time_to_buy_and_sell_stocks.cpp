/**
 * Leetcode-121 : Best Time to Buy and Sell stocks
*/

#include <bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &a){
    int i=0, j=0;
    int maxi = 0;
    while(i < a.size()){
        int diff = a[i] - a[j];
        while(diff < 0){
            j++;
            diff = a[i] - a[j];
        }
        maxi = max(diff, maxi);
        i++;
    }
    return maxi;
}

int main(){
    vector<int> a{7,1,5,3,6,4};
    cout << maxProfit(a) << endl;
}