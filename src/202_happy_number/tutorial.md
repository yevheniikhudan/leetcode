# Happy Number — Tutorial

Difficulty: Easy

This tutorial explains the "Happy Number" problem conceptually, outlines multiple approaches (without code), discusses complexity and trade-offs, and highlights edge cases and common pitfalls.

---

## Problem recap (in plain words)

Start with a positive integer `n`. Repeatedly replace the number by the sum of the squares of its digits. If this process eventually reaches `1`, the original number is called "happy". If the process falls into a repeating loop that never includes `1`, the number is not happy.

Example transformation for `19`:
- 19 → 1² + 9² = 82
- 82 → 8² + 2² = 68
- 68 → 6² + 8² = 100
- 100 → 1² + 0² + 0² = 1 → happy

---

## Key observation

Each step computes a deterministic function f(x) = sum of squares of digits(x). Because f(x) maps integers to integers and the values produced are bounded (see note below), repeated application of f must either:
- reach 1 and stay there, or
- fall into a cycle that does not contain 1.

This reduces the problem to cycle detection on the sequence x, f(x), f(f(x)), ...

Note about bounds: For a base-10 integer with `d` digits, the maximum value of f(x) is `d * 9^2 = 81d`. For 32-bit signed integers (<= ~2e9) `d <= 10`, so f(x) ≤ 810. That means sequences quickly fall into the range [0, 810] and then cycle within a small finite set. In practice the number of distinct values before repetition is small.

---

## Approaches (conceptual, code-free)

### 1) Using a Set / Hash table (detect repeated value)
- Maintain a set of values seen so far.
- At each step compute the next number using the digit-square-sum function.
- If the next value is `1`, return true (happy).
- If the next value is already in the set, a cycle has been detected → return false (not happy).
- Otherwise add the value to the set and continue.

Trade-offs:
- Very simple and robust.
- Time: proportional to number of unique values encountered before termination.
- Space: O(k) where k is number of distinct values seen; k is bounded and typically small.

When to use:
- When simplicity is preferred and extra space is acceptable.

---

### 2) Floyd’s cycle-finding algorithm (Tortoise and Hare)
- Use two iterators: slow advances by one application of f, fast advances by two applications.
- If at any point one of them reaches `1`, the original number is happy.
- If slow == fast (they meet) and the meeting point is not 1, a cycle exists and the original number is not happy.

Trade-offs:
- O(1) extra space, because no set is stored.
- Same or slightly faster time behavior in practice.
- Slightly more conceptual/algorithmic than the set approach.

When to use:
- When space constraints matter or to demonstrate knowledge of cycle detection techniques.

---

### 3) Precomputed table / memoization
- Precompute the fate (happy or not) for the entire bounded range of possible sums (e.g., 0..810).
- For each query, repeatedly transform until the value is in the table, then return the stored fate.
- Or populate memoization lazily: whenever you determine a chain’s result, store it for all elements of the chain.

Trade-offs:
- Space/time tradeoff: precomputation uses more memory but makes per-query time O(1) after precomputation.
- Useful when checking many numbers repeatedly.

---

## Complexity analysis

Let d = number of digits in the current number (≈ log10(n)). Each transform requires O(d) work to compute sum of squared digits.

- Time:
  - Number of steps until termination is bounded and small in practice because values quickly fall below a small constant (≤ 810 for 32-bit inputs).
  - Set approach: O(k * d) where k is number of distinct values seen.
  - Floyd approach: O(k * d) as well, but with smaller constant factors and O(1) extra space.
- Space:
  - Set approach: O(k).
  - Floyd: O(1).
- Practically both are extremely fast for allowed input sizes.

---

## Correctness intuition

- Because the transform is deterministic and maps to a finite set, the sequence must eventually repeat.
- If the repeating value is 1, the sequence terminates happily.
- Otherwise it lands in a cycle that excludes 1, so the number is not happy.

Floyd’s algorithm correctly detects cycles (meeting implies a cycle), and checking for `1` detects the accepting state.

---

## Edge cases and input considerations

- n = 1 → immediately happy.
- n = 0 → by the transform 0 → 0 (a loop not containing 1) → not happy (however LeetCode constraints often give n >= 1).
- Very large n: digits count rises, but the sum-of-squares decreases quickly; values fall into the bounded small range after a few steps.
- Negative numbers: problem usually considers positive integers only; handle negatives defensively if necessary (e.g., treat as invalid or operate on absolute value, per problem spec).
- Repeated calls: consider memoization or caching if you need to evaluate many numbers.

---

## Common pitfalls

- Forgetting to check `1` before inserting into the seen set — check for success as soon as it occurs.
- Using recursion without bounding depth (iterative loops are simple and safe).
- Mistakenly assuming monotonic decrease: the value can increase sometimes (e.g., 19 → 82), but the bounded argument ensures eventual shrink.
- Implementing Floyd incorrectly by not advancing `fast` twice per iteration.

---

## Tests and examples to validate an implementation

Include a mix of small, edge, and random values:

- 1 → true
- 7 → true (common known happy number)
- 19 → true (worked example)
- 2 → false
- 3, 4, 20, 116 → false (various non-happy examples)
- Large values, e.g., 1999999999 → should terminate quickly and be classified correctly

For stress testing or benchmarking:
- Check numbers from 1..1000 and verify results against a reference (set-based) method.
- Test repeated runs to validate caching/memoization does not introduce errors.

---

## Optimization notes / variants

- Because the state space after the first transform is small, you can limit memoization to a small lookup table (size ~810) for constant-time queries afterwards.
- The sum-of-squares function can be optimized by extracting digits with integer arithmetic (mod/div).
- For languages where integer-digit conversion is cheap, string-based digit iteration is acceptable and clearer.
- If implementing in a multi-request server, cache results across requests to speed up common queries.

---

## Summary / Recommended approach

- For clarity and quick implementation: use the set/hash-table approach.
- For optimal space usage and an elegant algorithmic solution: use Floyd’s cycle detection.
- For repeated bulk queries: combine memoization/precomputation with either method.

This problem is an approachable mix of digit manipulation and cycle detection techniques — good for practicing small deterministic state-machine reasoning and basic algorithmic patterns.