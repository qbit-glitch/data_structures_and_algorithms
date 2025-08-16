/**
 * Leetcode-2149: Rearrange Array elements by Sign
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> a){
    int evenPos = 0, oddPosition = 1;
    vector<int> b(a.size(), 0);
    for(int i=0; i<a.size(); i++){
        if(a[i] >= 0){
            b[evenPos] = a[i];
            evenPos += 2;
        }
        else{
            b[oddPosition] = a[i];
            oddPosition += 2;
        }
    }
    return b;
}

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{3,1,-2,-5,2,-4};
    vector<int> b = rearrangeArray(a);
    printArray(b);
}