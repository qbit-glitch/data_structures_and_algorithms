/**
 * Leetcode-455: Assign Cookies
 * Link: https://leetcode.com/problems/assign-cookies/description/
*/

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s){
    int n = g.size(), m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int g_pointer = 0, s_pointer = 0;
    while(s_pointer < m) {
        if(g[g_pointer] <= s[s_pointer])
            g_pointer++;
        s_pointer++;
    }
    return g_pointer;
}

int main(){
    vector<int> greed {1,5,3,3,4};
    vector<int> size {4,2,1,2,1,3};
    cout << findContentChildren(greed, size) << endl;
}