/**
 * Code360: Fractional Knapsack
 * Link: https://www.naukri.com/code360/problems/fractional-knapsack_975286
*/

#include <bits/stdc++.h>
using namespace std;

// Pair<int, int> -> Pair<weights, values>

void printVectorOfPairs(vector<pair<int,int>> &a){
    for(auto &i: a){
        cout << i.first << "," << i.second << endl;
    }
    cout << endl;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    printVectorOfPairs(items);
    std::sort(items.begin(), items.end(), [](auto &left, auto &right) {
        return ((double)left.second / (double)left.first) > ((double)right.second / (double)(right.first));
    });
    printVectorOfPairs(items);

    int total_weights = 0;

    double total_val = 0;
    
    for(auto &i: items){
        if(total_weights + i.first <= w){
            total_val += (double)i.second;
            total_weights += i.first;
            // cout << i.second << endl;
        }
        else{
            // cout << ((double)i.second / (double)i.first) * ((double)w - total_weights) << endl;
            total_val += ((double)i.second / (double)i.first) * ((double)w - total_weights);
            break;
        }
    }
    return total_val;
}

int main(){
    // vector<pair<int, int>> items = {{50,40}, {40,50}, {90,25}, {120,100}, {10,30}, {200,45}};

    vector<pair<int, int>> items = {{20,12}, {24,35}, {36,41}, {40,25}, {42,32}};

    cout << maximumValue(items, items.size(), 100) << endl;
}