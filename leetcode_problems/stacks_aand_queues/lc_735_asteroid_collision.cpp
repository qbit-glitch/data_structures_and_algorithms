/**
 * Leetcode-735: Asteroid Collision
 * Link: https://leetcode.com/problems/asteroid-collision/description/
*/

#include <bits/stdc++.h>
using namespace std;

/** Thought process : 
 * NOTE: Entire question is based on handling edge cases when 
 *      removing elements from the stack based on a[i] and the top of stack.
 * 1. if positive -> push into stack
 * 2. if negative :
 *      a. pop until abs(a[i]) > st.top()
 *      b. if(st.top() < 0) => negative elements => no pop required 
 *          -> just push into stack
 *      c. if(st.top() > abs(a[i])) => don't do anything to stack 
 *          and continue to next iteration
 *      d. if(st.top() == abs(a[i])) => negative = positive -> both will explode 
 *          => pop and continue
*/
vector<int> asteroidCollision(vector<int>& a) {
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        if(a[i] > 0)
            st.push(a[i]);
        else{
            if(!st.empty() and st.top() < 0)
                st.push(a[i]);
            else {
                while((!st.empty()) and (st.top() > 0) and (st.top() < abs(a[i])))
                    st.pop();
                if(!st.empty() and st.top() < 0)
                    st.push(a[i]);
                else if(!st.empty() and st.top() > abs(a[i]))
                    continue;
                else if(!st.empty() and st.top() == abs(a[i])){
                    st.pop();
                    continue;
                }
                else    st.push(a[i]);  
            }
        }
    }
    cout << st.size() << endl;
    
    vector<int> ans(st.size(), 0);
    for(int i=st.size()-1; i >= 0; i--){
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

void printVector(vector<int> &a){
    for(auto &i: a)
        cout <<  i << " ";
    cout << endl;
}


int main(){
    vector<int> a{-3,5,-6,7,-7,4};
    vector<int> result = asteroidCollision(a);
    printVector(result);
}