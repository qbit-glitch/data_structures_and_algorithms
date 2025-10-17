/**
 * GFG: All divisors of a number
 * Link: https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
*/

#include <bits/stdc++.h>
using namespace std;

void print_divisors(int n) {
    vector<int> a;
    for(int i=0; i <= sqrt(n); i++){
        if(n%i == 0) {
            a.push_back(i);
            if(i != n/i)
                a.push_back(n/i);
        }
    }
    if(n != 1)
        a.push_back(n);

    sort(a.begin(), a.end());
    for(auto &i: a)
        cout << i << " ";
}

int main(){
    print_divisors(1);
}

