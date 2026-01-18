# 210. Course Schedule II

[LeetCode link](https://leetcode.com/problems/course-schedule-ii/description/)

Given the total number of courses and a list of prerequisite pairs, return the order in which you should take the courses to finish all courses. If it is impossible, return an empty list.

- **Input:**
    - `numCourses` (int): Total number of courses.
    - `prerequisites` (List[List[int]]): Each pair `[a, b]` means to take course `a` you must first take course `b`.
- **Output:**
    - A list of course indices in the order you should take them, or an empty list if impossible.

**Example 1:**

Input: numCourses = 2, prerequisites = [[1,0]]

Output: [0,1]

**Example 2:**

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]

Output: [0,2,1,3] or [0,1,2,3]

**Constraints:**
- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= 5000
- prerequisites[i].length == 2
- 0 <= ai, bi < numCourses
- All the pairs are unique.
