/**
 * GFG: Allocate Minimum Pages
 * Problem Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
*/

#include <bits/stdc++.h>
using namespace std;


int calculateStudentsRequired(vector<int> &arr, int pages){
    int cntStud = 1, pagesCount = 0;
    for(auto &i: arr){
        if(pagesCount + i <= pages)
            pagesCount += i;
        else{
            cntStud++;
            pagesCount = i;
        }
    }
    return cntStud;
}

pair<int,int> sumWithMaxElement(vector<int>&a){
    int maxi = INT_MIN, sum=0;
    for(auto &i: a){
        maxi = max(i, maxi);
        sum += i;
    }
    return make_pair(sum, maxi);
}


int findPages(vector<int> &arr, int k){
    if(arr.size() < k)
        return -1;
        
    auto sum_max = sumWithMaxElement(arr);
    int low = sum_max.second, high = sum_max.first;
    int ans = INT_MAX;
    
    while(low <= high){
        int mid = (low+high)/2;
        int cntStud = calculateStudentsRequired(arr, mid);
        
        if(cntStud <= k)
        {
            ans = min(ans, mid);    
            high = mid-1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> books{25,46,28,49,24};
    int k = 4;
    cout << findPages(books,k) << endl;
}