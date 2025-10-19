/**
 * Link: https://takeuforward.org/plus/dsa/problems/prime-factorisation-of-a-number
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> primeFactors(vector<int> &queries){
    vector<vector<int>> result{};
    vector<int> spf(100000+1, 0);

    for(int i=1 ; i<=100000; i++){
        spf[i] = i;
    }

    for(int i=2; i<=100000; i++){
        if(spf[i] == i){
            for(int j=i*i; j<=100000; j+=i){
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    for(int i=0; i < queries.size(); i++){
        int n = queries[i];
        if (n < 1 || n > 100000) {
            cout << "Query value out of bounds: " << n << endl;
            result.push_back({}); // Push an empty vector for invalid queries
            continue;
        }

        vector<int> r;
        while(n > 1){
            r.push_back(spf[n]);
            n = n/spf[n];
        }
        result.push_back(r);
    }

    return result;
}


void printVectors(vector<vector<int>> &a){
    for(auto &i: a){
        for(auto &j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> queries{2,3,4,5,6};
    vector<vector<int>> result = primeFactors(queries);
    printVectors(result);
}