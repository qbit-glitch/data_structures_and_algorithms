/**
 * GFG: Odd Or Even
 * Link: https://www.geeksforgeeks.org/problems/odd-or-even3618/1
*/

#include <bits/stdc++.h>
using namespace std;


bool isEven(int n) {
    // code here
    string binary = bitset<32>(n).to_string();
    cout << binary << endl;
    if(binary[binary.size()-1] == '0')
        return true;
    else
        return false;    
}

int main(){
    int n = 31;
    cout << isEven(n) << endl;

}