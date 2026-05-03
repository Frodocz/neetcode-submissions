class Twitter {
public:
    int time = 0;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].emplace_back(time++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followMap[userId].insert(userId);
        priority_queue<vector<int>> maxHeap; // final result of 10 feeds, greater time -> more recent
        const auto& following = followMap[userId];
        for (auto f : following)
        {
            if (auto it = tweetMap.find(f); it != tweetMap.end())
            {
                auto &tweets = it->second;
                if (tweets.empty()) // unlikely
                    continue;
                int idx = tweets.size() - 1;
                const auto &[time, tweetId] = tweets[idx];
                maxHeap.push({time, tweetId, f, idx});
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto t = maxHeap.top();
            maxHeap.pop();
            res.push_back(t[1]);
            int followeeId = t[2], idx = t[3] - 1;
            if (idx >= 0)
            {
                const auto&[time, tweetId] = tweetMap[followeeId][idx];
                maxHeap.push({time, tweetId, followeeId, idx});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};