/**
 * Leetcode-8: String to Integer
*/

#include <bits/stdc++.h>
using namespace std;

long long int myAtoi(string s){
    bool positiveNumber = true;
    bool numberStarted = false;
    long long number=0;
    int signCount = 0;
    bool parsingStarted = false;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' ' and parsingStarted == false){
            continue;
        }
        else {
            parsingStarted = true;
            if((s[i] == '-' or s[i] == '+') and (numberStarted == false))
            {   
                signCount++;
                if(signCount > 1)
                    break;
                if(s[i] == '-')
                    positiveNumber = !positiveNumber;
                continue;
            }
            else if(s[i]-'0' >= 0  and s[i]-'0' < 10)
            {
                numberStarted = true;
                if(number > (INT32_MAX-(s[i]-'0'))/10)
                {    
                    if(positiveNumber)
                        return INT32_MAX;
                    else
                        return INT32_MIN;
                }
                number = (10 * number + (s[i] - '0'));
            }
            else
                break;
        }
    }
    return (positiveNumber ? 1 : -1) * number;
}

int main(){
    string s = "    +0 142";
    cout << int(' ')  << "," << int('0') << endl;
    cout << myAtoi(s) << endl;
}