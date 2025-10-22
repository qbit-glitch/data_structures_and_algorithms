/**
 * Leetcode-496: Next Greater Element
 * Link: https://leetcode.com/problems/next-greater-element-i/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mpp;
    stack<int> st;
    for(int i=nums2.size()-1; i>=0; i--){
        while(!st.empty() and st.top() <= nums2[i])
            st.pop();
        if(st.empty())
            mpp[nums2[i]] = -1;
        else
            mpp[nums2[i]] = st.top();

        st.push(nums2[i]);
    }    

    vector<int> ans;
    for(auto &i: nums1){
        ans.push_back(mpp[i]);
    }
    return ans;
}

void printVector(vector<int> &a){
    for(auto &i: a){
        cout << i << " " ;
    }
    cout << endl;
}

int main(){
    vector<int> nums1 {4,1,2};
    vector<int> nums2 {1,3,4,2};

    vector<int> result = nextGreaterElement(nums1, nums2);
    printVector(result);
}