# 705. Design HashSet

[LeetCode Link](https://leetcode.com/problems/design-hashset/description/)

Design a HashSet without using any built-in hash table libraries.

Implement `MyHashSet` class:
- `MyHashSet()` Initializes the object.
- `void add(key)` Inserts the value `key` into the HashSet.
- `void remove(key)` Removes the value `key` from the HashSet. If `key` does not exist, do nothing.
- `boolean contains(key)` Returns true if this set contains the specified key.

**Example:**
Input: ["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]
[[ ],[1],[2],[1],[3],[2],[2],[2],[2]]
Output: [null,null,null,true,false,null,true,null,false]

**Constraints:**
- 0 <= key <= 10^6
- At most 10^4 calls will be made to add, remove, and contains.
