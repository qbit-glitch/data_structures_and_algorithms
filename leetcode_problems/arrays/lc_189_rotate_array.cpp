/** Leetcode-189: Rotate Array
 * 
 * Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

    **Example 1:**

    ```
    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

    ```

    **Example 2:**

    ```
    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation:
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]

    ```

    **Constraints:**

    - `1 <= nums.length <= 105`
    - `231 <= nums[i] <= 231 - 1`
    - `0 <= k <= 105`

    **Follow up:**

    - Try to come up with as many solutions as you can. There are at least **three** different ways to solve this problem.
    - Could you do it in-place with `O(1)` extra space?
 */

#include <bits/stdc++.h>
using namespace std;

void rightRotateByOne(vector<int> &a){
    int item = a[0];
    for(int i = a.size()-1; i>=0; i--){
        a[(i+1) % a.size()] = a[i];
    }
    a[1] = item;
}

void rightRotateByK(vector<int> &a, int k){
    if(a.size() <= 1)
        return;

    int count = 1;

    while(count <= k){
        rightRotateByOne(a);
        count++;
    }
}

void rightRotateByK_2(vector<int> &a, int k){
    if (a.size() <= 1)
        return;
        
    int n = a.size();
    vector<int> b(n);
    k = k % n;

    for(int i=0; i<n; i++){
        b[(i+k) % n] = a[i];
    }
    for(int i = 0; i<n; i++)
        a[i] = b[i];
}



void printArray(vector<int> a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

void rightRotateByK_3(vector<int> &a, int k){
    if(a.size() <= 1)
        return;

    k = k % a.size();

    vector<int> items(k);
    
    for(int i=0; i<k; i++)
        items[i] = a[i];
    

    for(int i = a.size()-1; i>=k; i--){
        a[(i+k)%a.size()] = a[i];
    }

    printArray(items);

    for(int i=0; i<k; i++){
        a[(i+k)%a.size()] = items[i]; 
    }
    
    printArray(a);
}


int main(){
    vector<int> a{1,2,3,4,5,6,7,8};
    rightRotateByK_3(a,3);
    printArray(a);
}

