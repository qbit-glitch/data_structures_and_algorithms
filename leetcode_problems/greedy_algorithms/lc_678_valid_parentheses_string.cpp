/**
 * Leetcode-678: Valid Parentheses
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
*/

#include <bits/stdc++.h>
using namespace std;


// Brute Force Solution using Recursion and trying out all possible combinations

bool fn_recursive(string s, int ind, int cnt) {
    if(cnt < 0)     return false;
    if (ind == s.size())    return (cnt == 0);

    if(s[ind] == '(')
        return fn_recursive(s, ind+1, cnt+1);
    else if(s[ind] == ')')
        return fn_recursive(s, ind+1, cnt-1);
    else
        return (fn_recursive(s, ind+1, cnt+1) or fn_recursive(s, ind+1, cnt-1) or fn_recursive(s, ind+1, cnt));
}

bool checkValidString(string s){
    int i=0, cnt=0;
    return fn_recursive(s, i, cnt);
}


// Optimal Solution
bool checkValidString_optimal(string s){
    int min = 0, max = 0;
    for(char &c: s){
        if(c == '('){
            min += 1;
            max += 1;
        } else if (c == ')'){
            min -= 1; max -= 1;
        } else {
            min -= 1;
            max += 1;
        }
        if(min < 0)     min = 0;
        if(max < 0)     return false;
    }
    return true;
}




int main(){
    string s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    cout << checkValidString_optimal(s) << endl;
}