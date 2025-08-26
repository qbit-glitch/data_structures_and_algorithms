/**
 * Leetcode-493: Reverse Pairs
*/

#include <bits/stdc++.h>
using namespace std;


void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int countPairs(vector<int> &a, int low, int mid, int high){
    int right = mid+1;
    int count = 0;

    for(int i = low; i <= mid; i++){
        while(right <= high and a[i] > 2*a[right])
            right++;
        count += right-(mid+1);       
    }
    return count;
}



void merge(vector<int> &a, int low, int mid, int high){
    vector<int> b;
    int i=low, j=mid+1;
    while(i <= mid and j <= high){
        if(a[i] <= a[j])
            b.push_back(a[i++]);
        else
            b.push_back(a[j++]);
    }

    while(i <= mid)    b.push_back(a[i++]);
    while(j <= high)    b.push_back(a[j++]);

    for(int i=low; i<=high; i++)
        a[i] = b[i-low];
}


int mergeSort(vector<int>& a, int low, int high){
    int cnt = 0;
    if(low >= high){
        return cnt;
    }

    int mid = (high+low)/2;
    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid+1, high);
    cnt += countPairs(a, low, mid, high);
    merge(a, low, mid, high);
    return cnt;
}



int reversePairs_Better(vector<int> &a){
    return mergeSort(a, 0, a.size()-1);
}


// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1;   // starting index of right half of arr

//     //storing elements in the temporary array in a sorted manner//

//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // if elements on the left half are still left //

//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     //  if elements on the right half are still left //
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // transfering all elements from temporary to arr //
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }

// int countPairs(vector<int> &arr, int low, int mid, int high) {
//     int right = mid + 1;
//     int cnt = 0;
//     for (int i = low; i <= mid; i++) {
//         while (right <= high && arr[i] > 2 * arr[right]) right++;
//         cnt += (right - (mid + 1));
//     }
//     return cnt;
// }

// int mergeSort(vector<int> &arr, int low, int high) {
//     int cnt = 0;
//     if (low >= high) return cnt;
//     int mid = (low + high) / 2 ;
//     cnt += mergeSort(arr, low, mid);  // left half
//     cnt += mergeSort(arr, mid + 1, high); // right half
//     cnt += countPairs(arr, low, mid, high); //Modification
//     merge(arr, low, mid, high);  // merging sorted halves
//     return cnt;
// }

// int team(vector <int> & skill, int n)
// {
//     return mergeSort(skill, 0, n - 1);
// }

// int main()
// {
//     vector<int> a = {2,4,3,5,1};
//     int n = 5;
//     int cnt = team(a, n);
//     cout << "The number of reverse pair is: "
//          << cnt << endl;
//     return 0;
// }






int main(){
    vector<int> a{2,4,3,5,1};
    cout << reversePairs_Better(a) << endl;
}