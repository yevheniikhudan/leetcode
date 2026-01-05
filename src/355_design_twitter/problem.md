# 355. Design Twitter

**Difficulty:** Medium

## Topics
- Hash Table
- Heap (Priority Queue)
- Design

## Problem Description
Design a simplified version of Twitter where users can post tweets, follow/unfollow other users, and retrieve the 10 most recent tweet ids in the user's news feed.

Implement the `Twitter` class:
- `Twitter()` Initializes your twitter object.
- `void postTweet(int userId, int tweetId)` Composes a new tweet.
- `List<Integer> getNewsFeed(int userId)` Retrieves the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
- `void follow(int followerId, int followeeId)` The user with id `followerId` started following the user with id `followeeId`.
- `void unfollow(int followerId, int followeeId)` The user with id `followerId` stopped following the user with id `followeeId`.

### Example:
```
Input
["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]
Output
[null,null,[5],null,null,[6,5],null,[5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed returns [5].
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed returns [6, 5].
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed returns [5].
```

## Constraints
- 1 <= userId, followerId, followeeId <= 500
- 0 <= tweetId <= 10^4
- All the tweets have unique ids.
- At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and unfollow.

## Related Problems
- 380. Insert Delete GetRandom O(1)
- 705. Design HashSet
