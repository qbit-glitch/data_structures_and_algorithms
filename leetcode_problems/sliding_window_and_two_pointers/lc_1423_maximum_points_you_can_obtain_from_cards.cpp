/**
 * Leetcode-1423: Maximum Points You can obtain from cards
 * Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
*/

/** Problem Description:
 * There are several cards arranged in a row, and each card has an associated 
 *      number of points. The points are given in the integer array cardPoints.
 * In one step, you can take one card from the beginning or from the end of the row. 
 * You have to take exactly k cards. 
 * Your score is the sum of the points of the cards you have taken. 
 * Given the integer array cardPoints and the integer k, 
 *      return the maximum score you can obtain.
*/

#include <bits/stdc++.h>
using namespace std;

/**Thought Process:
 * 1. Add from begining upto k elements in lsum
 * 2. Put maxSum = lsum
 * 3. Decrease from (k-1) elements to 0 while 
 *      adding 1 element each time from back in rsum
 */
int maxScore(vector<int>& a, int k) {
    int lsum = 0, rsum = 0, maxSum = 0, rInd = a.size()-1;
    for(int i=0; i<k; i++)
        lsum += a[i];
    
    maxSum = lsum;

    for(int i = k-1; i>=0; i--){
        lsum -= a[i];
        rsum += a[rInd];
        rInd--;
        maxSum = max(maxSum, lsum+rsum);
    }
    return maxSum;
}

int main(){
    vector<int> a{11,49,100,20,86,29,72};
    int k=4;
    cout << maxScore(a,k) << endl;
}