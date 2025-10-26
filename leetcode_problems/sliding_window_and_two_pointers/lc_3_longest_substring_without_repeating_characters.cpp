/**
 * Leetcode-3: Longest Substring without repeating characters
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * 1. l=0,r=0, mpp
 * 2. move r by 1 and increase mpp[s[r]] by 1
 * 3. if at any point we encounter two same characters in the window 
 *      -> shrink the window size by decreasing l until mpp[s[r]] == 1
 * 4. maxLen = max(maxLen, r-l+1) 
*/
int lengthOfLongestSubstring(string s) {
    if(s.size()==0 or s.size()==1)
        return s.size();

    unordered_map<char, int> mpp;
    int l=0, r=0;
    int maxLen = 0;

    while(r != s.size()){
        mpp[s[r]]++;
        while(r != l and mpp[s[r]] >= 2){
            mpp[s[l]]--;
            l++;
        }
        int len = r-l+1;
        maxLen = max(maxLen, len);
        r++;
    }
    return maxLen;
}

int main(){
    string s = "aabcadabcd";
    cout << lengthOfLongestSubstring(s) << endl;
}