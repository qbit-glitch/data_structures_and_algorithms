/**
 * Leetcode-139: Word Break
 * Link: https://leetcode.com/problems/word-break/description/
*/

#include <bits/stdc++.h>
using namespace std;

void printVectorOfStrings(vector<string> &s){
    for(auto &i: s)
        cout << i << " ";
    cout << endl;
}


bool isPresentInWordDict(string &ds, vector<string> &wordDict){
    int low = 0, high = wordDict.size()-1;

    while(low <= high){
        int mid = (low + high)/2;

        if(wordDict[mid] == ds)
            return true;
        else if(wordDict[mid].compare(ds) > 0)
            high = mid-1;
        else
            low = mid+1;
    }
    return false;
}


bool func(int ind, string ds, string s, vector<string> &wordDict){
    if(ind == s.size()){
        return true;
    }

    for(int i=ind; i<s.size(); i++){
        
        string s1 = s.substr(ind, i-ind+1);
        // cout << i << "," << s1 << endl;
        if(isPresentInWordDict(s1, wordDict)){
            if(func(i+1, ds+s1, s, wordDict))
                return true;
        }
    }
    return false;
}


bool wordBreak(string s, vector<string>& wordDict) {
    string ds="";
    sort(wordDict.begin(), wordDict.end());
    return func(0, ds, s, wordDict);        
}



int main(){
    vector<string> wordDict{"apple","pen"};
    string s = "applepenapple";
    // sort(wordDict.begin(), wordDict.end());
    // cout << isPresentInWordDict(search, wordDict) << endl;

    cout << wordBreak(s, wordDict) << endl;

}

