/**
 * Leetcode-2220: Minimum Bit Flips to Convert Number
*/

#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    string s1 = bitset<32>(start).to_string();
    string s2 = bitset<32>(goal).to_string();
    int c = 0;
    for(int i=0; i<32; i++){
        if(s1[i] != s2[i])
            c++;
    }
    return c;
}

int main(){
    int start=10;
    int goal = 7;
    cout << minBitFlips(start, goal) << endl;
}