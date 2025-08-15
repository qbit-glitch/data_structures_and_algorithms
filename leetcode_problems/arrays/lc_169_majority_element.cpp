/**
 * Leetcode-169: Majority Element
*/

#include <bits/stdc++.h>
using namespace std;


int mooresCandidate(vector<int> &a){
    int candidate = a[0];
    int count = 1;
    for(int i=1; i<a.size(); i++){
        if(a[i] == candidate)
            count++;
        else{
            count--;
            if(count == 0){
                candidate = a[i];
                count = 1;
            }
        }
    }
    return candidate;
}

int majorityElement(vector<int> &a){
    if(a.size() == 1)
        return a[0];
    int countOccurance = 0;
    int candidate = mooresCandidate(a);
    cout << candidate << endl;
    for(int i=0; i<a.size(); i++){
        if(a[i] == candidate)
            countOccurance ++;
    }
    cout << countOccurance << endl;
    if (countOccurance > a.size()/2)
        return candidate;
    else return -1;
}

int main(){
    vector<int> a{2,2,1,1,1,2,2};
    cout << majorityElement(a) << endl;
}