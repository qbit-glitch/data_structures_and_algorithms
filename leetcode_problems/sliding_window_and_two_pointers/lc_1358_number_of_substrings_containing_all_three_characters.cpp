/**
 * Leetcode-1358: Number of Substrings containing all three characters
 * Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
*/

#include <bits/stdc++.h>
using namespace std;

/** Problem Description: 
 * Given a string s consisting only of characters a, b and c. 
 * Return the number of substrings containing at least one occurrence 
 * of all these characters a, b and c.
*/


/** Thinking: 
 * number of substrings in which (freq(a) & freq(b) & freq(c) >= 1) each individually
 * Ans: {all substrings} - {substrings with (freq(a) or freq(b) or freq(c)) <= 0}
*/

int substringsWithFreqLessThanEqual0(string s) {
    unordered_map<char, int> mpp;
    int l=0, r=0, cnt=0;
    while(r < s.size()){
        mpp[s[r]]++;
        while(mpp['a']!=0 and mpp['b']!=0 and mpp['c']!=0)
        {    
            mpp[s[l]]--;
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt;
}

int totalNumberOfSubstrings(string &s){
    int l=0, r=0, cnt=0;
    while(r < s.size()){
        cnt+= r-l+1;
        r++;
    }
    return cnt;
}

int numberOfSubstrings(string &s){
    return totalNumberOfSubstrings(s) - substringsWithFreqLessThanEqual0(s);
}


/**
 * Find the total number of substrings in a single iteration itself
 * Use array instead of Hashmap
*/
int numberOfSubstrings_Better(string &s){
    vector<int> mpp(3,0);
    int l=0, r=0, cnt=0, subCnt = 0;
    while(r < s.size()){
        mpp[s[r]-'a']++;
        while(mpp[0]!=0 and mpp[1]!=0 and mpp[2]!=0)
        {    
            mpp[s[l]-'a']--;
            l++;
        }
        cnt += r-l+1;
        subCnt += r+1;
        r++;
    }
    return subCnt - cnt;
}


int main(){
    string s = "aaacb";
    cout << numberOfSubstrings(s) << endl;
}