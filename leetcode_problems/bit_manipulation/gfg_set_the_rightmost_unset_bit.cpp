/**
 * GFG: Set the rightmost unset bit
 * Link: 
*/

#include <bits/stdc++.h>
using namespace std;

int setBit(int n) {
    return (n | (n+1));
}

int main(){
    int n = 6;
    cout << setBit(n) << endl;
}