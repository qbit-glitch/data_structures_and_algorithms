/**
 * GFG: Minimum Platforms
 * Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;


int minPlatform_Brute(vector<int>& arr, vector<int>& dep) {
    // code here
    int maxCnt = 0;
    for(int i=0; i<arr.size(); i++){
        int cnt = 1;
        for(int j=i+1; j<arr.size(); j++){
            if((arr[j] < arr[i] and dep[j] > arr[i]) or (arr[j] > arr[i] and arr[j] < dep[i]))
                cnt++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}


/**
 * 1. Sort both the arrival and departure arrays independently
 *    - Maintain one pointer to each array separately.
 * 2. If the arrival time <= departure time -> cnt++
 * 3. else -> cnt--
*/
int minPlatform(vector<int> &arr, vector<int> &dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i=0, j=0, cnt=0, maxCnt = 0;
    while(i < arr.size()){
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}


int main(){
    vector<int> arr {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep {920, 1200, 1130, 1150, 1900, 2000};

    cout << minPlatform_Brute(arr, dep) << endl;
    cout << minPlatform(arr, dep) << endl;
}
