/**
 * GFG: Missing and Repeating numbers
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
    // code here
    vector<int> b(1+arr.size(),0);
    for(int i=0; i<arr.size(); i++){
        b[arr[i]]++;
    }
    int missing, repeating;
    for(int i=0; i<b.size(); i++){
        if(b[i] == 2)
            repeating = i;
        if(b[i] == 0 and i > 0)
            missing = i;
    }
    return vector<int>{repeating, missing};
}

void printArr(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{2,2};
    auto ans = findTwoElement(a);
    printArr(ans);
}