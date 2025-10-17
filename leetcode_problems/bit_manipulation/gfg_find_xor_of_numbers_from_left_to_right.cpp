/**
 * GFG: Find XOR of Numbers from L to R
 * Link: https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
 * 
 * NOTE: This is a good question. Try to memorize it for the rest of your life.
*/

#include <bits/stdc++.h>
using namespace std;

int findXORtilN(int n){
    if(n%4 == 1)    return 1;
    if(n%4 == 2)    return n+1;
    if(n%4 == 3)    return 0;
    return n;
}


int findXOR(int l, int r) {
    return findXORtilN(l-1) ^ findXORtilN(r);
}

int main(){
    cout << findXOR(4,8) << endl;
}