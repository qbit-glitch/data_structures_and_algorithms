/**
 * GFG: Minimize Max Distance to Gas Station
 * Problem Link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
*/

#include <bits/stdc++.h>
using namespace std;

/** Most Optimal Solution using Binary Search reducing the space complexity */

int numberOfGasStationsRequired(vector<int> &stations, double dist){
    int cnt = 0;
    for(int i=1; i<stations.size(); i++){
        int numInBet = (stations[i]-stations[i-1])/dist;
        if(numInBet * dist == (stations[i] - stations[i-1])/dist)
            numInBet--;
        cnt += numInBet;
    }
    return cnt;
}


double minMaxDist(vector<int> &stations, int k){
    double low=0, high=0;
    
    for(int i=0; i<stations.size()-1; i++){
        high = max(high, (double)(stations[i+1] - stations[i]));
    }
    double threshold = 1e-6;
    while(high - low > threshold){
        double mid = (low+high)/2.0;
        int cnt  = numberOfGasStationsRequired(stations, mid);
        if(cnt > k)
            low = mid;
        else 
            high = mid;
    }
    return high;
}



/** Writing the Better Solution using Prority Queue DS */

double minMaxDistance_Better(vector<int> &stations, int k){
    if(stations.size() == 1)
            return 0.0;

    int n = stations.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<double, int>> pq;

    for(int i=0; i<n-1; i++){
        pq.push({stations[i+1]-stations[i], i});
    }

    for(int i=1; i <= k; i++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        double initialDiff = stations[secInd+1] - stations[secInd];
        double newSecLen = initialDiff/ (double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}



int main(){
    vector<int> stations{13};
    int k=1;
    cout << minMaxDistance_Better(stations, k) << endl;
}