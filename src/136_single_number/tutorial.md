# Single Number — Tutorial

Difficulty: Easy

This tutorial explains approaches and reasoning for LeetCode 136 "Single Number". It intentionally contains no code — only concepts, strategies, and analysis.

## Problem recap
You are given a non-empty array of integers in which every element appears exactly twice except for one element that appears once. Find and return the single element. The goal is to achieve linear runtime and constant extra space.

## Key insight
The XOR operator (exclusive OR) provides a simple and elegant solution:
- `a XOR a = 0`
- `a XOR 0 = a`
- XOR is associative and commutative  
Therefore, XOR-ing all numbers in the array cancels out every pair, leaving the unique element. This gives an O(n) time and O(1) space solution.

## Approaches (conceptual)

### 1) XOR scan (recommended)
- Iterate through the array and maintain a running XOR of all elements.
- Because paired elements cancel (x ^ x = 0), the result after processing the whole array is the unpaired element.
- Properties used: associativity, commutativity, and involutive behavior of XOR.
- Time: O(n). Space: O(1).

When to use:
- Always use this approach if constraints allow integer XOR operations (native integer types). It is optimal in time and space and is most idiomatic for this problem.

### 2) Hash set / frequency map
- Insert numbers into a set; if a number is already present, remove it; at the end the set contains the single element.
- Or build a frequency map and scan for count == 1.
- Time: O(n). Space: O(n).

When to use:
- When you need a more general counting approach (e.g., when numbers may appear arbitrary times or when you want to extend to variants), or if XOR semantics are unfamiliar.

### 3) Sorting
- Sort the array and scan adjacent elements to find the unpaired value.
- Time: O(n log n). Space: O(1) or O(n) depending on sorting algorithm and whether in-place sort is allowed.

When to use:
- Only when simplicity is favored over optimality, or if modifying input is allowed and n is small.

## Bitwise explanation & proof for XOR approach
- Represent each number as bits. XOR on each bit position is effectively addition modulo 2.
- Because every paired number contributes twice to each bit position, those contributions sum to 0 (mod 2). The single element's bits remain.
- The algebraic properties of XOR (x ^ x = 0 and x ^ 0 = x) guarantee correctness regardless of element order.

## Complexity
- XOR method: Time O(n), Space O(1).
- Hash set / frequency map: Time O(n), Space O(n).
- Sorting: Time O(n log n), Space O(1)–O(n).

## Edge cases & considerations
- Single-element array: return that element.
- Negative numbers: XOR works for signed integers at the bit level; handle language-specific integer widths carefully (use native integer type).
- Integer overflow: XOR does not overflow in the arithmetic sense; it operates bitwise on fixed-width integers — no special handling required beyond using the appropriate type.
- Very large arrays: XOR scales linearly; ensure iteration uses efficient primitives.
- Input guarantees: problem statement assures exactly one unpaired element; if input may violate this, use a frequency map or validation checks.

## Variants and related problems
- Single Number II (137): every element appears three times except one — solve via bit-count trick or bitwise count modulo 3.
- Single Number III (260): two elements appear once and others twice — solve using XOR partitioning.
- Problems involving bit manipulation often generalize to counting per-bit contributions and reducing modulo k for different multiplicities.

## Testing suggestions
Include tests covering:
- Small arrays (length 1).
- Typical arrays with many pairs and one unique.
- Arrays containing negative numbers and zeros.
- Very large arrays to check performance.
- Randomized tests comparing XOR approach vs frequency map for correctness.

When you implement tests in the repo, follow the project's output format: `actual | expected | PASS/FAIL`.

## Common pitfalls
- Using XOR incorrectly by resetting or not aggregating across the whole array.
- Mistaking XOR for addition — remember XOR is bitwise modulo 2 per bit.
- Using a data type too small to hold numbers (language-specific). Use the appropriate integer type.

## Summary
- The XOR scan is the simplest, most efficient solution (O(n) time, O(1) space).
- Frequency maps and sorting are valid alternatives when constraints differ or when clarity is preferred over strict optimality.
- For related variants, generalize the bitwise counting technique.

(End of tutorial)