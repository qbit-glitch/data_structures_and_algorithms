/**
 * Leetcode-85: Maximal Rectangle
 * Link: https://leetcode.com/problems/maximal-rectangle/description/
*/

#include <bits/stdc++.h>
using namespace std;


/** Computing the largest area of the rectangle in a histogram : 
 * 1. We need to compute max(a[i] * (nse-pse-1))
 * 2. Optimal Solution will include computing the pse and nse in a single traversal
 * 3. We can easily compute the pse using a stack
 * 4. While  eliminating the larger element from the stack, 
 *      - the current element will become nse of the top of the stack 
 *      - the element below the top of the stack will become the pse for the top of the stack
 *      - hence we can easily use the formula in a single pass
 * 5. It may happen that the stack is not empty when we reach the end, in that case
 *      - our element will become the top of the stack
 *      - nse = size of array
 *      - pse - 2nd top of the stack
 *      - again use the same formula
*/
int largestRectangleHistogram(vector<int> &a){
    stack<int> st;

    int maxArea = 0;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() and a[st.top()] > a[i]){
            int nse = i;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1: st.top();
            maxArea = max(maxArea, a[element]*(nse-pse-1));
        }
        st.push(i);
    }

    while(!st.empty()){
        int element = st.top();
        st.pop();

        int nse = a.size();
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(maxArea, a[element]*(nse-pse-1));
    }
    return maxArea;
}

/** Thought Process:
 * 1. Assume each row is a histogram
 * 2. Then find the maxArea of rectangle in each histogram for each row
 * 3. Take the max of maxArea as Answer
*/
int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>> pSum (matrix.size(), vector<int>(matrix[0].size(), 0));
    for(int j=0; j<matrix[0].size(); j++){
        int sum = 0;
        for(int i=0; i<matrix.size(); i++){
            sum += matrix[i][j] - '0';
            if(matrix[i][j] == '0')
                sum = 0;
            pSum[i][j] = sum;
        }
    }
    int maxArea = 0;
    for(int i=0; i<matrix.size(); i++){
        maxArea = max(maxArea, largestRectangleHistogram(pSum[i]));
    }
    return maxArea;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalRectangle(matrix) << endl;
}