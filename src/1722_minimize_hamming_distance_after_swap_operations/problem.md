# Minimize Hamming Distance After Swap Operations

**Problem Number:** 1722  
**Difficulty:** Medium  

## Topics/Tags
- Union-Find (Disjoint Set Union)
- Graph Connectivity
- Greedy Algorithm
- Array

## Problem Description

You are given two arrays `source` and `target`, both of length `n`. You are also given an array `allowedSwaps` where `allowedSwaps[i] = [a_i, b_i]` indicates that you can swap the elements at indices `a_i` and `b_i` in the `source` array. You can perform an unlimited number of swaps.

The Hamming distance between two arrays of the same length is the number of positions at which the corresponding elements are different.

**Your Task:** Return the minimum Hamming distance between `source` and `target` after making any number of swaps.

## Key Insight

If you can swap indices `i` and `j`, and you can also swap indices `j` and `k`, then transitively you can swap indices `i` and `k` (by doing the swaps in sequence). This means:
- All indices connected through allowed swaps form a **connected component**
- Within a connected component, you can arrange elements in **any order**
- To minimize Hamming distance, match as many target values as possible within each component

## Examples

**Example 1:**
```
Input: 
  source = [1,2,3,4,5]
  target = [1,5,4,2,3]
  allowedSwaps = [[0,4],[4,2],[1,3]]

Output: 0

Explanation:
- We can swap source[0] and source[4]: source = [5,2,3,4,1]
- We can swap source[1] and source[3]: source = [5,4,3,2,1]
- We can swap source[3] and source[2]: source = [5,4,2,3,1]
- We can swap source[0] and source[4]: source = [1,4,2,3,5]
- We can swap source[1] and source[2]: source = [1,2,4,3,5]
- We can swap source[2] and source[3]: source = [1,2,3,4,5]
Now source equals target with Hamming distance 0.
```

**Example 2:**
```
Input: 
  source = [1,2,3,4,5]
  target = [1,3,2,4,5]
  allowedSwaps = [[1,4],[1,3],[4,2]]

Output: 1

Explanation:
Connected component 1: indices {1, 3, 4, 2}
- source values at these indices: {2, 4, 5, 3}
- target values at these indices: {3, 4, 2, 5}
- We can match: 4 at index 3 (already there), and rearrange others
- Position 1: source has 2, target has 3 → cannot match (2 and 3 are both in the component but after optimal arrangement, one won't match)
- Position 0: source[0]=1, target[0]=1 → matches
- Minimum hamming distance = 1
```

**Example 3:**
```
Input: 
  source = [5,1,2,4,3]
  target = [1,5,4,2,3]
  allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]

Output: 0

Explanation:
All indices form a single connected component.
We can rearrange source to match target completely.
```

## Constraints

- `n == source.length == target.length`
- `1 <= n <= 10^5`
- `1 <= source[i], target[i] <= 10^5`
- `0 <= allowedSwaps.length <= 10^5`
- `allowedSwaps[i].length == 2`
- `0 <= allowedSwaps[i][0], allowedSwaps[i][1] < n`
- `allowedSwaps[i][0] != allowedSwaps[i][1]`

## Related Problems

- 1202. Smallest String With Swaps
- 947. Most Stones Removed with Same Row or Column
- 200. Number of Islands