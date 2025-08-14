/** Leetcode-283: Move Zeroes
 * 
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

    Example 1:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Example 2:

    Input: nums = [0]
    Output: [0]
    

    Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
    

    Follow up: Could you minimize the total number of operations done?
 * 
*/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> a){
    for(auto &i:a){
        cout << i << " "; 
    }
    cout << endl;
}

void leftShiftByK(vector<int> &a, int k, int low){
    if(k==0)
        return;
    
    vector<int> items(k);
    int c = 0;
    for(int i=low; i < low+k; i++){
        items[c] = a[i];
        c++;
    }
    
    for(int i=(low + k); i < a.size(); i++){
        a[i-k] = a[i];
    }

    for(int i = a.size()-1; i >= a.size()-k; i--){
        a[i] = items[c-1];
        c--;
    }
}

void moveZeroes_2(vector<int> &a){
    int shifts = 0;
    int i = 0;
    while(i < a.size()){
        if(a[i] == 0){
            shifts++;
            i++;
            continue;
        }
        else {
            if(shifts != 0){
                leftShiftByK(a, shifts, i-shifts);
                i = i - shifts;
                shifts = 0;
            }
            else {
                i++;
            }
        }
    }
}


void moveZeroes(vector<int> &a){
    int j = -1;
    for(int i=0; i< a.size(); i++){
        if(a[i] == 0){
            j=i;
            break;
        }
    }
    for(int i=j+1; i<a.size(); i++){
        if(a[i] != 0){
            swap(a[i], a[j]);
            j++;
        }
    }
}




int main(){
    vector<int> a{0,1,0,3,12};
    moveZeroes(a);
    printArray(a);

    vector<int> a1{0,0,1,0,2,0,3,4};
    moveZeroes(a1);
    printArray(a1);
}

