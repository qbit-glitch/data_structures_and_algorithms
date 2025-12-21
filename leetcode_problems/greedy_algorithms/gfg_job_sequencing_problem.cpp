/**
 * GFG: Job Sequencing Problem
 * Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

void printVector(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}



/** Algo:
 * 1. Create a vector of structs of fields {id, deadline, profit}
 * 2. Sort the vector of struct in decreasing order of profits
 * 3. Get the maximum deadline among the deadline array
 * 4. Initialize a hasharray with all elements as -1 with lenght = deadline.size()+1
 *      so that we can index the deadlines.
 * 5. Loop through each jobs in the newly sorted vector
 *      i. for j = jobs[i].deadline   -> j>0
 *            if(hasharray[j] == -1)    -> no job is scheduled at that location
 *                  cnt++ | maxProfit += jobs[i].profit | hasharray[j] = jobs[i].id
 *                  break
 * 6. Return {cnt, maxProfit}  
*/

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit){
    vector<Job> jobs;
    for(int i=0; i<deadline.size(); i++){
        jobs.push_back({i, deadline[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b){
        return a.profit > b.profit;
    });

    vector<int> hashArray (deadline.size()+1, -1);

    int maxDeadline = 0, cnt = 0, cntProfit = 0;
    for(int i: deadline){
        maxDeadline = max(maxDeadline, i);
    }

    for(int i=0; i<jobs.size(); i++){
        printVector(hashArray);
        for(int j = jobs[i].deadline; j>0; j--){
            if(hashArray[j] == -1) {
                cnt++;
                cntProfit += jobs[i].profit;
                hashArray[j] = jobs[i].id;
                break;
            }
        }
    }
    return {cnt, cntProfit};
}   

int main(){
    vector<int> deadline{4,1,1,1};
    vector<int> profit{20,10,40,30};
    vector<int> result = jobSequencing(deadline, profit);
    cout << result[0] << " " << result[1] << endl;
}