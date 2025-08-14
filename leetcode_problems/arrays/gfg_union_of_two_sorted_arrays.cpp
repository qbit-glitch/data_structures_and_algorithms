/**
 * GFG: Union of two sorted array
 * 
 * Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
    Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

    Examples:

    Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
    Output: [1, 2, 3, 4, 5, 6, 7]
    Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
    Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
    Output: [1, 2, 3, 4, 5]
    Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
    Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
    Output: [1, 2]
    Explanation: Distinct elements including both the arrays are: 1 2.
    Constraints:
         1  ≤  a.size(), b.size()  ≤  105
        -109 ≤ a[i], b[i] ≤109
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &a);


void printArray(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> unionOf2SortedArrays(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size(), i=0, j=0;
    set<int> res;
    while( i < n and j < m ){
        if(a[i] < b[j]){
            res.insert(a[i]);
            i++;
        }
        else if(a[i] > b[j]){
            res.insert(b[j]);
            j++;
        }
        else {
            res.insert(a[i]);
            i++;j++;
        }
    }
    if(i >= n){
        for(int k=j; k<m; k++)
            res.insert(b[k]);
    }
    if( j >= m){
        for(int k=i; k < n; k++)
            res.insert(a[k]);
    }
    vector<int> result;
    std::copy(res.begin(), res.end(), back_inserter(result));
    return result;
}


vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // code here
    int n = removeDuplicates(a), m = removeDuplicates(b), i=0, j=0;
    vector<int> res;
    while( i < n and j < m ){
        if(a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]){
            res.push_back(b[j]);
            j++;
        }
        else {
            res.push_back(a[i]);
            i++;j++;
        }
    }
    if(i >= n){
        for(int k=j; k<m; k++)
            res.push_back(b[k]);
    }
    if( j >= m){
        for(int k=i; k < n; k++)
            res.push_back(a[k]);
    }
    return res;
}

int removeDuplicates(vector<int> &a){
    if (a.size() == 0) {
        return 0;
    }
    if(a.size() == 1){
        return 1;
    }

    int k = 0, item = a[0];
    for(int i=1; i<a.size(); i++){
        if( a[i] == item)
            continue;
        else{
            k++;
            item = a[i];
            swap(a[i], a[k]);
        }
    } 
    return k+1;

}



int main(){
    vector<int> a{1,2,4,4,5}, b{4};
    vector<int> res = unionOf2SortedArrays(a,b);
    printArray(res);
}