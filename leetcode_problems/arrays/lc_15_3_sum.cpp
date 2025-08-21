/**
 * Leetcode-15: 3 Sum Problem
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum_Optimal(vector<int> &a){
    vector<vector<int>> ls;
    int n = a.size();
    sort(a.begin(), a.end());
    for(int i=0; i<n-1; i++){
        if (i >0 and a[i] == a[i-1]) continue;

        int j=i+1, k=n-1;
        while(j < k){
            int sum = a[i]+a[j]+a[k];
            if(sum >0)
                k--;
            else if(sum < 0)
                j++;
            else{
                ls.push_back({a[i],a[j],a[k]});
                j++; k--;
                while(j < k and a[j] == a[j-1]) j++;
                while(j<k and a[k] == a[k+1])   k--;
            }
        }        
    }
    
    return ls;
}

vector<vector<int>> threeSum_Better(vector<int> &a){
    set<vector<int>> st;
    int n=a.size();
    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int third = -(a[i] + a[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {a[i], a[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

void printV(vector<vector<int>> &ls){
    for(auto &i: ls){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<int> a{-2,-2,-2,-1,-1,-1,-1,0,0,0,2,2,2,2};
    auto ans = threeSum_Optimal(a);
    printV(ans);
}