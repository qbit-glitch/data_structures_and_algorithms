#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool canWePlaceCows(vector<int> &stalls, int dist, int k){
    int last = stalls[0], countCows = 1;
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i] - last >= dist){
            countCows++;
            last = stalls[i];
        }
        if(countCows >= k)
            return true;
    }
    return false;
}



int aggressiveCows(vector<int> &stalls, int k) {
    // code here
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n-1] - stalls[0];
    int ans=0;
    while(low <= high){
        int mid = (low + high)/2;
        if(canWePlaceCows(stalls, mid, k) == true){
            ans = mid;
            low = mid+1;
            
        }
        else 
            high = mid-1;

        // cout << ans <<  " " << low << " " << high  << " " << mid << endl;
    }
    return high;
}

int main(){
    vector<int> stalls {0,3,4,7,10,9};
    cout << aggressiveCows(stalls, 4)<< endl;
}



// #include <bits/stdc++.h>
// using namespace std;

// bool canWePlace(vector<int> &stalls, int dist, int cows) {
//     int n = stalls.size(); //size of array
//     int cntCows = 1; //no. of cows placed
//     int last = stalls[0]; //position of last placed cow.
//     for (int i = 1; i < n; i++) {
//         if (stalls[i] - last >= dist) {
//             cntCows++; //place next cow.
//             last = stalls[i]; //update the last location.
//         }
//         if (cntCows >= cows) return true;
//     }
//     return false;
// }
// int aggressiveCows(vector<int> &stalls, int k) {
//     int n = stalls.size(); //size of array
//     //sort the stalls[]:
//     sort(stalls.begin(), stalls.end());

//     int low = 1, high = stalls[n - 1] - stalls[0];
//     //apply binary search:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (canWePlace(stalls, mid, k) == true) {
//             low = mid + 1;
//         }
//         else high = mid - 1;
//     }
//     return high;
// }

// int main()
// {
//     vector<int> stalls = {0, 3, 4, 7, 10, 9};
//     int k = 4;
//     int ans = aggressiveCows(stalls, k);
//     cout << "The maximum possible minimum distance is: " << ans << "\n";
//     return 0;
// }