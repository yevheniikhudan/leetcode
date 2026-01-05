#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
    struct Tweet {
        int time;
        int tweetId;
        Tweet(int t, int id) : time(t), tweetId(id) {}
    };
    unordered_map<int, unordered_set<int>> followings;
    unordered_map<int, vector<Tweet>> tweets;
    int time;

   public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId) { tweets[userId].emplace_back(time--, tweetId); }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        follow(userId, userId);
        using T = tuple<int, int, int, int>;  // time, tweetId, followeeId, idx
        auto cmp = [](const T& a, const T& b) { return get<0>(a) > get<0>(b); };
        priority_queue<T, vector<T>, decltype(cmp)> heap(cmp);
        for (int followeeId : followings[userId]) {
            auto& tvec = tweets[followeeId];
            if (tvec.empty()) continue;
            int idx = tvec.size() - 1;
            Tweet& t = tvec[idx];
            heap.emplace(t.time, t.tweetId, followeeId, idx - 1);
        }
        while (!heap.empty() && res.size() < 10) {
            auto [t, tweetId, followeeId, idx] = heap.top();
            heap.pop();
            res.push_back(tweetId);
            if (idx >= 0) {
                Tweet& next = tweets[followeeId][idx];
                heap.emplace(next.time, next.tweetId, followeeId, idx - 1);
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) { followings[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followings[followerId].erase(followeeId);
    }
};
