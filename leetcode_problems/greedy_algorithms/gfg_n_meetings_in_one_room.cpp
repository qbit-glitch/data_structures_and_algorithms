/**
 * GFG: N meetings in one room
 * Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the 
 * start time of meeting i and end[i] is the finish time of meeting i.
 * Return the maximum number of meetings that can be accommodated in a single meeting room, 
 * when only one meeting can be held in the meeting room at a particular time. 
 * Note: The start time of one chosen meeting can't be equal to the end time of the other 
 * chosen meeting.
 * 
 * 
 * 
 * start[] = [10, 12, 20], end[] = [20, 25, 30]
 * interval[] = [10,13,10]
*/

class Meetings{
    
    int start;
    int end;
    int position;

    public:
    Meetings(int s1, int e1, int p1){
        start = s1;
        end = e1;
        position = p1;
    }
 
    int get_end(){
        return end;
    }

    int get_start(){
        return start;
    }

    int get_position(){
        return position;
    }
};

void printMeetings(vector<Meetings> &a){
    for(auto &i: a){
        cout << i.get_start() << "," << i.get_end() << "," << i.get_position() << endl;;
    }
    cout << endl;
}


/** Solution Overview : 
 * 1. Store the values in a separate data structure : start, end, position
 * 2. sort the values w.r.t. `end` values as we want to be greedy coz 
 *      we want to finish meetings which are faster => lesser end times
 * 3. if(meetings[i].start > prev_end_time) -> count the meeting for maxNumber of meetings
*/

int maxMeetings(vector<int>& start, vector<int>& end) {
    vector<Meetings> m;
    for(int i=0; i<start.size(); i++){
        m.push_back(Meetings(start[i], end[i], i));
    }

    // Sort the meetings data structure based on the end_time of meetings
    sort(m.begin(), m.end(), [](auto &left, auto &right){
        return left.get_end() < right.get_end();
    });

    int prev_end = -1, cnt = 0;
    for(Meetings &i: m){
        if(i.get_start() > prev_end){
            cnt++;
            prev_end = i.get_end();
        }
    }

    return cnt;
}


int main(){
    vector<int> start {0,3,1,5,5,8};
    vector<int> end {5,4,2,9,7,9};

    cout << maxMeetings(start, end) << endl; 
}
