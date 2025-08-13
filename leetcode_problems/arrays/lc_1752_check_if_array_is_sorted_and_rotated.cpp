/** Leetcode: 1752 | Check if Array is sorted and Rotated
 *  Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
 * 
 * - Sample
    
    Given an array `nums`, return `true` *if the array was originally sorted in non-decreasing order, then rotated **some** number of positions (including zero)*. Otherwise, return `false`.
    
    There may be **duplicates** in the original array.
    
    **Note:** An array `A` rotated by `x` positions results in an array `B` of the same length such that `B[i] == A[(i+x) % A.length]` for every valid index `i`.
    
    **Example 1:**
    
    ```
    Input: nums = [3,4,5,1,2]
    Output: true
    Explanation: [1,2,3,4,5] is the original sorted array.
    You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
    
    ```
    
    **Example 2:**
    
    ```
    Input: nums = [2,1,3,4]
    Output: false
    Explanation: There is no sorted array once rotated that can make nums.
    
    ```
    
    **Example 3:**
    
    ```
    Input: nums = [1,2,3]
    Output: true
    Explanation: [1,2,3] is the original sorted array.
    You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
    
    ```
    
    **Constraints:**
    
    - `1 <= nums.length <= 100`
    - `1 <= nums[i] <= 100`
 */


#include <bits/stdc++.h>
#include <utility>
using namespace std;


// pair<bool, int> checkIfSorted(vector<int> &a);
// bool check(vector<int>& nums);





// bool check(vector<int>& nums) {
//     vector<int> b(nums.size());
//     pair<bool, int> res1 = checkIfSorted(nums);
//     if (res1.first == true)
//         return true;
//     else {
//         int x = res1.second;
//         vector<int> b = nums;
//         for(int i=0; i<b.size(); i++){
//             b[i] = nums[(i+x) % nums.size()];
//         }
//         for(int i=0; i<b.size(); i++){
//             nums[i] = b[i];
//         }
//         auto res2 = checkIfSorted(nums);
//         if (res2.first == true){
//             return true;
//         }
//         else
//             return false;
//     }

// }

// pair<bool, int> checkIfSorted(vector<int> &a){
//     if (a.size() == 0)
//         return make_pair(false, -1);
    
//         int prev = a[0];

//     for(int i=0; i<a.size(); i++){
//         if(a[i] < prev){
//             int n = (a.size()-1) - i;
//             return make_pair(false, n);
//         }
//     }

//     return make_pair(true, 0);
// }

// int main(){
//     vector<int> a {3,4,5,1,2};
//     cout << check(a) << endl;
// }

bool isSorted(vector<int> &a){
    if(a.size() == 0)
        return false;
    if(a.size() == 1)
        return true;

    for(int i=1; i<a.size(); i++){
        if(a[i] < a[i-1])
            return false;
    }
    return true;
}

void rightRotate(vector<int> &a, int x){
    vector<int> b(a.size());
    for(int i=0; i<a.size(); i++){
        b[(i + x)%a.size()] = a[i];
    }
    for(int i = 0; i<b.size(); i++){
        a[i] = b[i];
    }
    cout << endl;
}

void printArray(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

bool checkIfSortedAndRotated(vector<int> &a){
    
    bool isSort = isSorted(a);

    if(isSort == true)
        return true;
    else if(a.size() != 0){
        int x;
        for(int i=1 ;i < a.size(); i++){
            if(a[i] < a[i-1]){
                x = a.size() - i;
                break;   
            }
        }
        rightRotate(a,x);
        if(isSorted(a)){
            return true;
        }
    }
    return false;

}

int main(){
    vector<int> a{7,8,1,2,3,4,5,6};
    cout << checkIfSortedAndRotated(a) << endl;

}

