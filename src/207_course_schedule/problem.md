# 207. Course Schedule

[LeetCode link](https://leetcode.com/problems/course-schedule/description/)

Given the total number of courses and a list of prerequisite pairs, determine if it is possible to finish all courses.

- **Input:**
    - `numCourses` (int): Total number of courses.
    - `prerequisites` (List[List[int]]): Each pair `[a, b]` means to take course `a` you must first take course `b`.
- **Output:**
    - `True` if it is possible to finish all courses, otherwise `False`.

**Example 1:**

Input: numCourses = 2, prerequisites = [[1,0]]

Output: true

Explanation: Take course 0 first, then course 1.

**Example 2:**

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]

Output: false

Explanation: There is a cycle (0 <-> 1), so it is impossible.

**Constraints:**
- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= 5000
- prerequisites[i].length == 2
- 0 <= ai, bi < numCourses
- All the pairs are unique.
