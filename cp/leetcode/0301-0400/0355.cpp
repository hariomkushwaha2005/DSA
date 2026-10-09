#include <bits/stdc++.h>
using namespace std;

class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int time;

public:
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto& it : tweets[userId]) {
            pq.push(it);
            if (pq.size() > 10)
                pq.pop();
        }
        for (auto& it : follows[userId]) {
            for (auto& i : tweets[it]) {
                pq.push(i);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        int x = pq.size() > 10 ? 10 : pq.size();
        vector<int> v(x);
        while (!pq.empty()) {
            x--;
            v[x] = pq.top().second;
            pq.pop();
        }
        return v;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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