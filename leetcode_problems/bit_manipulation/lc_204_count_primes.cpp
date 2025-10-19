/**
 * Leetcode-204: Count Primes
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * 1. Make a primes[] array which stores all numbers from 2 to n
 * 2. As you move from 2 to n, 
 *      - check whether primes[i]==1
 *      - mark all multiples of i as 0
 * 3. At the end of the iteration, all non-prime numbers will be marked as zeros.
 * 4. Loop again, check whether primes[i]==1      
*/

int countPrimes(int n) {
    vector<int> primes(n+1,1);
    for(int i=2; i*i <= n; i++){
        if(primes[i] == 1){
            for(int j=i*i; j<=n; j+=i)
                primes[j] = 0;
        }
    }
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(primes[i] == 1)
            cnt++;
    }
    return cnt;
}

int main(){
    int n=30;
    cout << countPrimes(n) << endl;
}

