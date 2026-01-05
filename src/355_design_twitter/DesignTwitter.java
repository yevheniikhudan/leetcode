import java.util.*;

public class DesignTwitter {
    // LeetCode expects a class named Twitter
    public static class Twitter {
        private static class Tweet {
            int time;
            int tweetId;

            public Tweet(int time, int tweetId) {
                this.time = time;
                this.tweetId = tweetId;
            }
        }

        private Map<Integer, Set<Integer>> followings;
        private Map<Integer, List<Tweet>> tweets;
        private int time;

        public Twitter() {
            followings = new HashMap<>();
            tweets = new HashMap<>();
            time = 0;
        }

        public void postTweet(int userId, int tweetId) {
            tweets.computeIfAbsent(userId, k -> new ArrayList<>()).add(new Tweet(time--, tweetId));
        }

        public List<Integer> getNewsFeed(int userId) {
            List<Integer> res = new ArrayList<>();
            follow(userId, userId);
            PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
            Set<Integer> followeeSet = followings.getOrDefault(userId, new HashSet<>());
            for (int followeeId : followeeSet) {
                List<Tweet> tlist = tweets.get(followeeId);
                if (tlist == null || tlist.isEmpty())
                    continue;
                int idx = tlist.size() - 1;
                Tweet t = tlist.get(idx);
                heap.offer(new int[] { t.time, t.tweetId, followeeId, idx - 1 });
            }
            while (!heap.isEmpty() && res.size() < 10) {
                int[] arr = heap.poll();
                res.add(arr[1]);
                int followeeId = arr[2], idx = arr[3];
                if (idx >= 0) {
                    Tweet t = tweets.get(followeeId).get(idx);
                    heap.offer(new int[] { t.time, t.tweetId, followeeId, idx - 1 });
                }
            }
            return res;
        }

        public void follow(int followerId, int followeeId) {
            followings.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
        }

        public void unfollow(int followerId, int followeeId) {
            if (followerId == followeeId)
                return;
            Set<Integer> set = followings.get(followerId);
            if (set != null)
                set.remove(followeeId);
        }
    }
}
