#include <bits/stdc++.h>
#include <iostream>

using namespace std;

pair<bool, int> majorityElementWithinRange(const vector<int>& a, int low, int high, int maxElementInRange){
    vector<int> count(maxElementInRange, 0);

    for(const auto i: a){
        count[i]++;
    }

    for(int i = 0; i< count.size(); i++){
        if(count[i] >= (high-low+1)/2)
            return make_pair(true, i);
    }
    return make_pair(false, -1);
}

int main(){
    vector<int> a{2,2,4,4,4,4,4,4,8,8,8,9,3,10};
    pair<bool, int> result = majorityElementWithinRange(a, 0, a.size()-1, 10);
    cout << result.first << " " << result.second << endl;
}