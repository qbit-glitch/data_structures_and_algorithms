/**
 * Leetcode-503: Next Greater Element-II
 * Link: https://leetcode.com/problems/next-greater-element-ii/description/
*/

#include <bits/stdc++.h>
using namespace std;

void fillStackS1(stack<int> &st, vector<int> &nums){
    for(int i= nums.size()-1; i>=0; i--){
        st.push(nums[i]);
    }
}

/** Thought Process
 * 1. Take 2 stacks :
 *      a. s1: one is filled with back-traversal of the vector
 *      b. s2: other one for keeping track of the elements on the 
 *          right side as we are doing back-traversal
 * 2. Check for next greater element on s2 first,
 *      if s2 becomes empty, check for nge on s1.  
*/

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s1;
    fillStackS1(s1, nums);
    
    stack<int> s2;
    vector<int> ans(nums.size(), 0);

    for(int i=nums.size()-1; i>=0; i--){
        while(!s2.empty() and s2.top() <= nums[i]){
            s2.pop();
        }

        while(s2.empty() and !s1.empty() and s1.top() <= nums[i])
            s1.pop();

        if(s2.empty()){
            if(s1.empty())
                ans[i] = -1;
            else
                ans[i] = s1.top();
        }
        else {
            ans[i] = s2.top();
        }

        s2.push(nums[i]);
    
    }
    return ans;
}

void printVector(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}


int main(){
    vector<int> nums{1,2,3,4,3};
    vector<int> result = nextGreaterElements(nums);

    printVector(result);
}