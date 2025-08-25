/**
 * Leetcode-88: Merge Sorted Array
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0, j=0;
    int c=0;
    while(i < m and j < n){
        if(nums1[i] <= nums2[j]){
            continue;
            i++;
        }
        else{
            c++;
            for(int k=m+c; k > i; k--){
                nums1[k] = nums1[k-1]; 
            }
            nums1[i] = nums2[j];
            i++; j++;
        }
    }        
}

void mergeFromEnd(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1, j=n-1, pos=m+n-1;
    while(j>=0){
        if(i>=0 and nums1[i] > nums2[j]){
            nums1[pos] = nums1[i];
            pos--; i--; 
        }
        else {
            nums1[pos] = nums2[j];
            pos--; j--;
        }
    }
}



void printVector(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> a{1,6,9,0,0,0};
    vector<int> b{4,5,6};

    mergeFromEnd(a,3,b, 3);
    printVector(a);
}

