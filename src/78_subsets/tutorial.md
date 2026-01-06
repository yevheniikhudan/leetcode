# Subsets - Tutorial

## Understanding the Problem

Given an array of unique integers, we need to find all possible subsets (the power set). A subset is any combination of elements from the array, including the empty set and the full array itself.

For example, `[1,2,3]` has 8 subsets: `[]`, `[1]`, `[2]`, `[3]`, `[1,2]`, `[1,3]`, `[2,3]`, `[1,2,3]`.

The number of subsets for an array of size `n` is `2^n` because each element has 2 choices: include it or exclude it.

## Approaches

### Approach 1: Backtracking (Recursive)

**Strategy:**
- Build subsets incrementally by making decisions at each step
- For each element, make two recursive calls: one including the element, one excluding it
- Base case: when we've processed all elements, add the current subset to results

**Key Concepts:**
- Decision tree: at each position, branch into "include" or "exclude"
- Depth-first search through all possible combinations
- Backtrack by removing the last added element before exploring other branches

**Time Complexity:** O(n * 2^n) - 2^n subsets, each taking O(n) to copy
**Space Complexity:** O(n) - recursion stack depth

### Approach 2: Iterative (Building Up)

**Strategy:**
- Start with an empty subset
- For each element in the array, take all existing subsets and create new subsets by adding the current element
- Example: `[]` → `[], [1]` → `[], [1], [2], [1,2]` → ...

**Key Concepts:**
- Begin with result containing only empty subset
- For each number, duplicate existing subsets and append the number
- Naturally generates all subsets without recursion

**Time Complexity:** O(n * 2^n)
**Space Complexity:** O(1) - excluding output space

### Approach 3: Bit Manipulation

**Strategy:**
- Use binary representation to generate subsets
- For n elements, iterate from 0 to 2^n - 1
- Each number's binary representation determines which elements to include
- Example: for `[1,2,3]`, the number 5 (binary 101) represents subset `[1,3]`

**Key Concepts:**
- Map each subset to a unique binary number
- Bit i being set means include element i
- Systematic enumeration of all 2^n possibilities

**Time Complexity:** O(n * 2^n)
**Space Complexity:** O(1) - excluding output space

## Edge Cases

- Single element array: returns `[[], [element]]`
- Empty array (though constraints say minimum 1 element)
- Negative numbers: handled same as positive

## Common Pitfalls

- Forgetting to include the empty subset
- Creating duplicate subsets (not an issue with unique elements)
- Not properly copying subsets before adding to result
