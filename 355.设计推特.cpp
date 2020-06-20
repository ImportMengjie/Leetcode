/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// @lc code=start
int gloab_time = 0;
class Twitter {
private:
    unordered_map<int, vector<pair<int,int>>> user_tweet;
    unordered_map<int,unordered_set<int>> friends;

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b){ return a.first < b.first; }
    };
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!user_tweet.count(userId)) user_tweet[userId]=vector<pair<int,int>>();
        user_tweet[userId].insert(user_tweet[userId].begin(), {gloab_time++,tweetId});
        if(user_tweet[userId].size()>10) user_tweet[userId].pop_back();
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(!user_tweet.count(userId)) user_tweet[userId]=vector<pair<int,int>>();
        if(!friends.count(userId)) friends[userId]=unordered_set<int>();
        friends[userId].insert(userId);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> range;
        for(auto& uid:friends[userId])
            if(user_tweet.count(uid))
                for(auto& tweet:user_tweet[uid])
                    range.push(tweet);
        vector<int> ret;
        for(int i=0;i<10&&range.size();i++){
            ret.push_back(range.top().second);
            range.pop();
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(!friends.count(followerId)) friends[followerId]=unordered_set<int>();
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(friends.count(followerId)&&friends[followerId].count(followeeId))
            friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

