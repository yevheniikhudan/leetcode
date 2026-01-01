# 1046. Last Stone Weight

**Difficulty:** Easy

## Problem
You are given an array of integers `stones` where `stones[i]` is the weight of the i-th stone.

We repeatedly smash the two heaviest stones together. If they are equal, both are destroyed. If they are not equal, the smaller is destroyed and the larger's new weight is the difference. This continues until there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

**Example:**
```
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
Smash 7 and 8 => 1, stones = [2,4,1,1,1]
Smash 2 and 4 => 2, stones = [2,1,1,1]
Smash 1 and 2 => 1, stones = [1,1,1]
Smash 1 and 1 => 0, stones = [1]
```

**Constraints:**
- 1 <= stones.length <= 30
- 1 <= stones[i] <= 1000
