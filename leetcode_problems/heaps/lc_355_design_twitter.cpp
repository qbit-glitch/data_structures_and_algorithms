/** Leetcode-355: Design Twitter
 * Link: https://leetcode.com/problems/design-twitter/description/
*/

#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void printVector(vector<int> &a){
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
}

/* This code is correct but contains TLE

class Twitter {
public:

    unordered_map<int, unordered_map<int, int>> follows;
    vector<pair<int,int>> posts;

public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int count = 0;

        for(int i = posts.size()-1; i>=0 && count <10; i--){
            if( posts[i].first == userId || follows[userId][posts[i].first] ){
                feed.push_back(posts[i].second);
                count++;
            }
        }
        // printVector(feed);
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 0;
    }
}; 
*/


class Twitter {
public:
    int timer = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer, tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;     // stores the tweets in maxHeap for each post based on the user and the people who the user follows based on timer of their post

        for(pair<int, int> &i: tweets[userId]){
            pq.push(i);
        }

        for(int i: follows[userId]){
            for(auto &j: tweets[i]){
                pq.push(j);
            }
        }

        int count = 0;
        vector<int> recentPosts;
        while(!pq.empty()){
            recentPosts.push_back(pq.top().second);
            pq.pop();
            count++;

            if(count == 10)
                break;
        }
        return recentPosts;

    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};


int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1,5);

    vector<int> newsFeed;
    newsFeed = obj->getNewsFeed(1);
    printVector(newsFeed);

    obj->follow(1,2);
    obj->postTweet(2,6);
    newsFeed = obj->getNewsFeed(1);
    printVector(newsFeed);

    obj->unfollow(1,2);

    newsFeed = obj->getNewsFeed(1);
    printVector(newsFeed);
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
*/


/* Some Jargon thinking (NOT CORRECT) :
    - We have to map the users with their tweetIDs
    - Also we have to map the followers and their followee
    - Now to get the most recent tweet when the user is posting we have to 
        maintain a separate counter for each user's post along with the tweetID.
    - One more thing, since a user can follow multiple new followees,
        so each user will be shown the recents post from the recent followers 
        as well even when the postRecencyCount for each followee is 1
    - total how many hashmaps I have to maintain ?
        - userID, pair<tweetID, postRecencyCount>
        - followerID, vector<followeeID>
        - 
*/


