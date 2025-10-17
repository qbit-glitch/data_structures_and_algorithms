/**
 * Leetcode-1390: Four Divisors
 * Link: https://leetcode.com/problems/four-divisors/description/
*/

#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &a){
    for(int &i: a)
        cout << i << " ";
    cout << endl;
}


vector<int> calDivisors(int n){
    vector<int> d{};
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            d.push_back(i);
            if(i != n/i)
                d.push_back(n/i);
        }
    }

    return d;
}

int sumFourDivisors(vector<int>& nums) {
    int sum=0;
    for(auto &i: nums){
        vector<int> divisors = calDivisors(i);
        if(divisors.size() == 4){
            
            sum += accumulate(divisors.begin(), divisors.end(), 0);
            
        }
    }    
    return sum;
}

int main(){
    vector<int> a{21, 21};
    cout << sumFourDivisors(a)  << endl;
}
