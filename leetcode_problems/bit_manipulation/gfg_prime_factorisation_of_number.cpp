/**
 * Prime Factorisation of a Number
 * Link: https://www.geeksforgeeks.org/problems/prime-factors5052/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> primeFac(int n) {
    vector<int> primeFactors{};
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            primeFactors.push_back(i);
            while(n%i == 0)
                n = n/i;
        }
    }
    if(n!=1)
        primeFactors.push_back(n);
    
    return primeFactors;
}

void printVector(vector<int> &a){
    for(int &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    int n = 780;
    vector<int> result = primeFac(n);
    printVector(result);
}