/**
 * Leetcode-84: Largest Rectangle in Histogram
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& a) {
    stack<int> st;
    int maxArea = 0;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() and a[st.top()] > a[i]){
            int element = st.top();
            st.pop();
            
            int nse = i;     
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, a[element] * (nse-pse-1));
            
        }
        st.push(i);
    }    

    while(!st.empty()){
        int nse = a.size();
        int element = st.top();         
        st.pop();

        int pse = st.empty()? -1: st.top();
        maxArea = max(maxArea, a[element]*(nse-pse-1));
        
    }
    return maxArea;
}

int main(){
    vector<int> a{3,2,10,11,5,10,6,3};
    cout << largestRectangleArea(a) << endl;
}