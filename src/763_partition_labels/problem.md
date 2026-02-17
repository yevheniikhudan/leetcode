# 763 Partition Labels

Difficulty: Medium

Tags: greedy, two pointers, string

Problem

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Formally, a partition is valid if no letter appears in more than one partition. Return a list of the sizes of the partitions.

Example:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation: The partitions are "ababcbaca", "defegde", "hijhklij".

Constraints:
- 1 <= S.length <= 500
- S consists of lowercase English letters.

Related Problems:
- 763 Partition Labels (this problem)
- 2402 Meeting Rooms III (similar interval merging concept)
