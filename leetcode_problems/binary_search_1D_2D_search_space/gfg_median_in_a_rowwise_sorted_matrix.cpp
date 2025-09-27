/**
 * GFG: Median in a Row-wise sorted matrix
 * https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &a, int t){
    int n = a.size();
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] > t)
        {
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}


int countSmallEqual(vector<vector<int>> &a, int x){
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        cnt += upperBound(a[i], x);
    }
    return cnt;
}

int median(vector<vector<int>> &a){
    int m = a.size(), n = a[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i=0; i<m; i++){
        low = min(low, a[i][0]);
        high = max(high, a[i][n-1]);
    }
    int req = (m * n)/2;
    while(low <= high){
        int mid = (low + high)/2;
        int smallerEquals = countSmallEqual(a, mid);

        if(smallerEquals <= req)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}


int main(){
    vector<vector<int>> a{{1,3,5}, {2,6,9}, {3,6,9}};
    cout << median(a) << endl;
}



/**
 * #include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
 */

