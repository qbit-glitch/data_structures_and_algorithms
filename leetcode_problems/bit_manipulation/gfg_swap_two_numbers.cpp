/**
 * GFG: Swap Two Numbers
 * Link: 
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b) {
    // code here
    a = a ^ b;
    b = a^b;
    a = a^b;
    return make_pair(a,b);
}

int main(){
    int a = 10;
    int b = 30;
    auto c = get(a,b);
    cout << c.first << " " << c.second << endl;
}