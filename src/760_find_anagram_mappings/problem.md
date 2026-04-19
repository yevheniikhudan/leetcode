# Problem 760: Find Anagram Mappings

**Difficulty:** Easy

**Topics:** Hash Map, Array

---

## Problem Description

You are given two integer arrays `nums1` and `nums2` where `nums2` is an anagram of `nums1`.

An **anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Return an index mapping array `mapping` of size `nums1.length` where `mapping[i] = j` means the value `nums1[i]` is at index `j` in `nums2`.

All elements in `nums1` and `nums2` are **unique**.

---

## Examples

### Example 1:
- **Input:** `nums1 = [12,28,46,32,50]`, `nums2 = [50,12,32,46,28]`
- **Output:** `[1,4,3,2,0]`
- **Explanation:**
  - `nums1[0] = 12` is at index 1 in `nums2`
  - `nums1[1] = 28` is at index 4 in `nums2`
  - `nums1[2] = 46` is at index 3 in `nums2`
  - `nums1[3] = 32` is at index 2 in `nums2`
  - `nums1[4] = 50` is at index 0 in `nums2`

### Example 2:
- **Input:** `nums1 = [84,46]`, `nums2 = [84,46]`
- **Output:** `[0,1]`
- **Explanation:**
  - `nums1[0] = 84` is at index 0 in `nums2`
  - `nums1[1] = 46` is at index 1 in `nums2`

### Example 3:
- **Input:** `nums1 = [1,2,3]`, `nums2 = [3,1,2]`
- **Output:** `[1,2,0]`
- **Explanation:**
  - `nums1[0] = 1` is at index 1 in `nums2`
  - `nums1[1] = 2` is at index 2 in `nums2`
  - `nums1[2] = 3` is at index 0 in `nums2`

### Example 4:
- **Input:** `nums1 = [5]`, `nums2 = [5]`
- **Output:** `[0]`

### Example 5:
- **Input:** `nums1 = [2,1]`, `nums2 = [1,2]`
- **Output:** `[1,0]`

---

## Constraints

- `1 <= nums1.length <= 100`
- `nums1` and `nums2` consist of integers in the range `[1, 100]`
- `nums2` is an anagram of `nums1`
- All elements in `nums1` and `nums2` are **unique**

---

## Related Problems

- [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/) - Similar mapping concept
- [Valid Anagram](https://leetcode.com/problems/valid-anagram/) - Anagram validation
- [Group Anagrams](https://leetcode.com/problems/group-anagrams/) - Grouping anagrams
- [Mapping Index to Value](https://leetcode.com/problems/relative-ranks/) - Index mapping variations