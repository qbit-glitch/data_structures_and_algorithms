/**
 * Code360: Next Smaller Element
 * Link: https://www.naukri.com/code360/problems/next-smaller-element_1112581
*/

#include <bits/stdc++.h>
using namespace std;

/** Thought Process:
 * 1. Store the elements on the right side on the stack during back-traversal
 * 2. if arr[i] <= st.top()     -> not a next smaller element => pop from stack
 * 3. If stack becomes empty    -> no next smaller element present
 * 4. else                      -> next smaller element = st.top()
*/
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack <int> st;
    vector<int> ans(n, 0);

    for(int i=n-1; i>=0; i--){
        while(!st.empty() and st.top() >= arr[i])
            st.pop();
        
        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        
        st.push(arr[i]);
    }
    return ans;
}

void printVector(vector<int> &a){
    for(int &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> a{2,1,4,3};
    vector<int> result = nextSmallerElement(a, a.size());

    printVector(result);
}