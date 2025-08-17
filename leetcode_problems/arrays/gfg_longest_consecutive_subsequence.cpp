/**
 * GFG: Longest Consecutive Subsequence
 * Link: https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
*/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i <<  " ";
    cout << endl;
}


int longestConsecutiveSubsequence_Optimal(vector<int> &a){
    int n = a.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(auto &i: a)
        st.insert(i);

    for(int i=0; i<a.size(); i++){
        if(st.find(a[i]-1) == st.end()){
            int cnt = 1;
            int x = a[i];

            while(st.find(x+1) != st.end()){
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


int longestConsecutiveSubsequence_Better(vector<int> &a){
    int n = a.size();
    if(n == 0) return 0;

    sort(a.begin(), a.end());

    int lastSmaller = INT_MIN, countConsecutives = 0, longest = 1;
    for(int i = 0; i < a.size(); i++){
        if(a[i]-1 == lastSmaller){
            countConsecutives++;
            lastSmaller = a[i];
        }
        else if(a[i] == lastSmaller)
            continue;
        else if(a[i]-1 != lastSmaller){
            countConsecutives = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, countConsecutives);
    }
    return longest;
}


int main(){
    vector<int> a{102,4,100,1,101,3,2,1,1};
    cout << longestConsecutiveSubsequence_Optimal(a) << endl;
    cout << longestConsecutiveSubsequence_Better(a) << endl;
}