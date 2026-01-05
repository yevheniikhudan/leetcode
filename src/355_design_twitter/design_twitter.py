from collections import defaultdict
from typing import List
import heapq


class Twitter:
    def __init__(self):
        self.followings = defaultdict(set)
        self.tweets = defaultdict(list)
        self.count = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append([self.count, tweetId])
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        res = []
        heap = []

        if userId not in self.followings[userId]:
            self.follow(userId, userId)

        for followeeId in self.followings[userId]:
            if followeeId not in self.tweets:
                continue

            index = len(self.tweets[followeeId]) - 1
            count, tweetId = self.tweets[followeeId][index]
            heap.append([count, tweetId, followeeId, index - 1])

        heapq.heapify(heap)

        while heap and len(res) < 10:
            _, tweetId, followeeId, index = heapq.heappop(heap)
            res.append(tweetId)
            if index >= 0:
                count, tweetId = self.tweets[followeeId][index]
                heapq.heappush(heap, [count, tweetId, followeeId, index - 1])

        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followings[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId == followerId:
            return

        if followeeId in self.followings[followerId]:
            self.followings[followerId].remove(followeeId)


# Test scaffolding
if __name__ == "__main__":
    ops = [
        "Twitter",
        "postTweet",
        "getNewsFeed",
        "follow",
        "postTweet",
        "getNewsFeed",
        "unfollow",
        "getNewsFeed",
    ]
    args = [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
    expected = [None, None, [5], None, None, [6, 5], None, [5]]
    obj = None
    for op, arg, exp in zip(ops, args, expected):
        if op == "Twitter":
            obj = Twitter()
            actual = None
        else:
            actual = getattr(obj, op)(*arg)
        print(f"{actual} | {exp}")
