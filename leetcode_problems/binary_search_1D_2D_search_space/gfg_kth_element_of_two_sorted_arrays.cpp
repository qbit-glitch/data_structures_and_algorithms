/**
 * GFG: Kth Element of Two Sorted Arrays
 * Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
*/

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {
    // code here
    int n1 = a.size(), n2 = b.size();
    if(n1 > n2) return kthElement(b,a,k);
    
    int low = max(0, k-n2), high = min(k, n1);

    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = k - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1)   r1 = a[mid1];
        if(mid2 < n2)   r2 = b[mid2];

        if(mid1 - 1 >=0)     l1 = a[mid1-1];
        if(mid2 - 1 >= 0)   l2 = b[mid2-1];

        if(l1 <= r2 and l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2)
            high = mid1-1;
        else 
            low = mid1+1;
    }
    return 0;
}

int main(){
    vector<int> a{1,2,7,8,9,23,44,54,5656,7667,4576};
    vector<int> b{1,4,8,10};
    int k = 8;
    cout << kthElement(a,b,k) << endl;
}