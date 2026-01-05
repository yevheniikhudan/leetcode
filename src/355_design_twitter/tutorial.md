# Design Twitter - Tutorial

## Understanding the Problem
You need to design a Twitter-like system with the following features:
- Post a tweet
- Follow/unfollow users
- Retrieve the 10 most recent tweets in a user's news feed (from self and followed users)

## Approaches
### 1. Brute Force
- Store all tweets in a list with userId and timestamp.
- For news feed, filter tweets by user and followed users, sort by time, and return the top 10.
- Not efficient for large data.

### 2. HashMap + Heap (Optimal)
- Use a HashMap to store each user's tweets (as a list of (timestamp, tweetId)).
- Use a HashMap to store each user's followees (as a set).
- For news feed, use a max-heap to merge the most recent tweets from the user and their followees.
- Always return the 10 most recent tweets.

## Time/Space Complexity
- Post: O(1)
- Follow/Unfollow: O(1)
- GetNewsFeed: O(N log k), where N is the number of users followed (including self), k is the number of tweets per user (up to 10)

## Key Concepts
- HashMap for user data
- Heap for merging sorted tweet streams
- Timestamp for ordering

## Edge Cases
- User follows/unfollows self
- No tweets
- Multiple users with no followees

*No code in this tutorial section.*
