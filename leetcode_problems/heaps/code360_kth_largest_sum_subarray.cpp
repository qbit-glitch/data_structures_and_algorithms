/** Code360: Kth Largest Sum Subarray
 * Link: https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398
*/


#include <vector>
#include <queue>
#include <iostream>
using namespace std;


void printHeap(priority_queue<int, vector<int>, greater<int>> ans){
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}


/* Algo :
    - Find all the subarray sums using nested looping
    - while calculating the sums, don't store the sum in a new vector, instead apply the logic of finding the kth largest element from an array at that point itself
*/
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> ans;
    int n = arr.size();
    for(int i=0; i < n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];

            if(ans.size() < k){
                ans.push(sum);
            }
            else {
                if(ans.top() < sum){
                    ans.pop();
                    ans.push(sum);
                }
            }
        }
        
    }
    return ans.top();
}

int main(){
    vector<int> a{4,1};
    cout << getKthLargest(a, 2) << endl;
}

