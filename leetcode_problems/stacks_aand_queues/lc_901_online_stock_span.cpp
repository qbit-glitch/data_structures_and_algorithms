/**
 * Leetcode-901: Online Stock Span
 * Link: https://leetcode.com/problems/online-stock-span/
*/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;
    int ind;


public:
    StockSpanner() {
        ind = -1;
        while(!st.empty())
            st.pop();
    }
    
    /** Thought Process:
     * - Whenever you add a new element find the pge of that element using the stack 
    */
    int next(int price) {
        ind++;
        while(!st.empty() and st.top().first <= price)
            st.pop();
        int ans = ind - (st.empty() ? -1: st.top().second);
        st.push({price, ind});
        return ans; 
    }
};

int main(){
    StockSpanner* obj = new StockSpanner();
    int param_1 = obj->next(100);
    int param_2 = obj->next(80);
    int param_3 = obj->next(60);
    int param_4 = obj->next(70);
    int param_5 = obj->next(60);
    int param_6 = obj->next(75);
    int param_7 = obj->next(85);
    
    cout << obj->next(95) << endl;
}