/**
 * Leetcode-424: Longest Repeating character replacement 
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/
*/

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int l=0, r=0, maxLen = 0, maxFreq = 0;
    vector<int> charHash(26,0);
    while(r < s.size()){
        charHash[s[r]-'A']++;
        maxFreq = max(maxFreq, charHash[s[r]-'A']);

        while((r-l+1)-maxFreq > k){
            charHash[s[l]-'A']--;
            maxFreq = 0;
            for(int i=0; i<26;i++){
                maxFreq = max(maxFreq, charHash[i]);
            }
            l++;
        }
        if((r-l+1) - maxFreq <= k)
            maxLen = max(maxLen, r-l+1);
        r++;
    }    
    return maxLen;
}

/**
 * No need to shrink the length below maxLen, 
 * we just need to make sure that the length doesn't increase.
 * So, increase the maxFreq, so that len-maxFreq <= k. 
 * Therefore no need to update the maxFreq, when the l is decreased by 1
*/
int characterReplacement_Optimal(string s, int k) {
    int l=0, r=0, maxLen = 0, maxFreq = 0;
    vector<int> charHash(26,0);
    while(r < s.size()){
        charHash[s[r]-'A']++;
        maxFreq = max(maxFreq, charHash[s[r]-'A']);

        if((r-l+1)-maxFreq > k){
            charHash[s[l]-'A']--;
            l++;
        }
        if((r-l+1) - maxFreq <= k)
            maxLen = max(maxLen, r-l+1);
        r++;
    }    
    return maxLen;
}

int main(){
    string s="AAABCD";
    int k=  2;
    cout << characterReplacement(s,k) << endl;
}