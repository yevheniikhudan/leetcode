# 268. Missing Number — Tutorial

---

## Understanding the Problem

We have `n` numbers in the array and `n+1` possible values in range `[0, n]`. Exactly one number is missing. Find it.

Example: `[3, 0, 1]` has 3 numbers, range is `[0, 3]`, missing is `2`.

---

## Visual Example

```
Range:     [0, 1, 2, 3]
Array:     [3, 0, 1, _]
           Missing: 2
```

---

## Approaches

### 1. Sum Formula ✅ Recommended

The sum of numbers from `0` to `n` is `n * (n + 1) / 2`. Subtract the actual array sum from this to get the missing number.

**Formula:** `missing = expectedSum - actualSum`

**Time:** O(n) | **Space:** O(1)

---

### 2. XOR Bit Manipulation

XOR has a useful property: `a ^ a = 0` and `a ^ 0 = a`. 

XOR all array elements with all numbers in range `[0, n]`. Duplicates cancel out, leaving only the missing number.

**Time:** O(n) | **Space:** O(1)

---

### 3. Hash Set

Store all array elements in a set, then iterate through `[0, n]` to find the missing number.

**Time:** O(n) | **Space:** O(n)

---

### 4. Sorting

Sort the array, then find the first gap. Edge cases: missing 0 or missing n.

**Time:** O(n log n) | **Space:** O(1)

---

## Complexity Summary

| Approach             | Time      | Space   |
|----------------------|-----------|---------|
| Sum Formula          | O(n)      | O(1)    |
| XOR Bit Manipulation | O(n)      | O(1)    |
| Hash Set             | O(n)      | O(n)    |
| Sorting              | O(n log n)| O(1)    |

---

## Key Concepts & Patterns

- **Gauss's formula:** Sum of `0` to `n` is `n * (n + 1) / 2`
- **XOR properties:** Commutative, associative, `a ^ a = 0`, `a ^ 0 = a`
- **Space-time tradeoff:** Sum/XOR methods use constant space; hash set trades space for clarity

---

## Edge Cases & Common Pitfalls

| Case               | Notes                                            |
|--------------------|--------------------------------------------------|
| `n = 1, nums = [0]`| Missing is 1 (at the end)                       |
| `n = 1, nums = [1]`| Missing is 0 (at the start)                     |
| Large `n`          | Watch for integer overflow in sum formula       |
| All consecutive    | Only one number is guaranteed missing           |

---

## Optimization Notes

- **Sum formula** is simplest and fastest in practice — no loops through data structures.
- **XOR approach** is elegant and avoids overflow issues (XOR never exceeds the numbers themselves).
- For interviews, explain both sum and XOR; sum is intuitive, XOR showcases bit manipulation knowledge.
