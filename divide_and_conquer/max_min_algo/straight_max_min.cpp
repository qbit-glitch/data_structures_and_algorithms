#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair<int,int> straightMaxMin(vector<int>& a){
    int max = a[0], min = a[0];
    for(int i=1; i<a.size(); i++){
        if (max < a[i])
            max = a[i];
        else if (min > a[i])
            min = a[i];
    }
    pair<int,int> max_min = make_pair(max, min);
    return max_min;
}

int main(){
    vector<int> a {10,8,12,4,7,9};
    pair<int, int> max_min =  straightMaxMin(a);
    cout << "MAX: " << max_min.first << ", MIN: " << max_min.second << endl;
}