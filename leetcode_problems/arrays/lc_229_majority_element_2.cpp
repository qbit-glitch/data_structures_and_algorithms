/**
 * Leetcode-229: Majority Element 2
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &a){
    vector<int> ans;
    map<int, int> hashMap;
    int min = floor(a.size()/3) + 1;
    
    for(auto &i: a){
        hashMap[i]++;
        if(hashMap[i] == min)
            ans.push_back(i);
    }
    return ans;
}

vector<int> majorityElement_Optimal(vector<int>& a) {
    int cnt1=0, cnt2=0, el1=INT_MIN, el2=INT_MIN;
    for(auto &i: a){
        if(cnt1 == 0 and el2 != i){
            cnt1 = 1; el1 = i;
        }
        else if(cnt2 == 0 and el1 != i){
            cnt2 = 1; el2 = i;
        }
        else if(i == el1)   
            cnt1++;
        else if (i == el2)  
            cnt2++;
        else{
            cnt1--; cnt2--;
        }
    }
    cnt1=0, cnt2=0;
    vector<int> ls;
    for(auto &i: a){
        if(el1 == i)
            cnt1++;
        if (el2 == i)
            cnt2++;
    }
    if(cnt1 >= floor(a.size()/3)+1)
        ls.push_back(el1);
    if(cnt2 >= floor(a.size()/3)+1)
        ls.push_back(el2);
    return ls;
}

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{1,1,1,1,3,3,2,3};
    vector<int> ans = majorityElement_Optimal(a);
    printArray(ans);
}