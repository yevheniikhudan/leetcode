# Smallest Integer Divisible by K - Tutorial

## Problem Understanding

We need to find the length of the smallest number consisting only of 1's that is divisible by `k`.

Examples:
- `k = 1`: `n = 1` (length 1)
- `k = 3`: `n = 111` (length 3, because 111 % 3 == 0)
- `k = 7`: `n = 111111` (length 6)
- `k = 2`: No such number exists (return -1)

## Key Insights

1. **Cannot directly compute**: Numbers like `111...1` with many digits won't fit in standard integer types.

2. **Pattern of numbers**: 
   - Length 1: `1`
   - Length 2: `11 = 1 * 10 + 1`
   - Length 3: `111 = 11 * 10 + 1`
   - Length n: `previous * 10 + 1`

3. **Use modular arithmetic**: Instead of tracking the full number, we only need to track the remainder when divided by `k`.
   - If `remainder = 0`, we found our answer
   - Otherwise, the next number is `(remainder * 10 + 1) % k`

4. **Detect impossibility**: 
   - If `k` is divisible by 2 or 5, no solution exists (numbers made of 1's are always odd and don't end in 0 or 5)
   - If we see the same remainder twice, we're in a cycle and will never reach 0

5. **Pigeonhole principle**: There are only `k` possible remainders (0 to k-1). If we don't find 0 within `k` iterations, we never will.

## Mathematical Proof

**Why even numbers and multiples of 5 never work:**
- A number made only of 1's is always odd (ends in 1)
- An odd number can never be divisible by 2
- A number divisible by 5 must end in 0 or 5
- Since our number always ends in 1, it can never be divisible by 5

**Why we need at most k iterations:**
- When computing `n % k`, the remainder is in range [0, k-1]
- By the pigeonhole principle, if we check k+1 remainders, at least two must be the same
- If two remainders are the same, we're in a cycle and will never reach 0

## Approach: Modular Arithmetic with Cycle Detection

**Algorithm**:
1. Handle edge cases:
   - If `k % 2 == 0` or `k % 5 == 0`, return -1
2. Initialize `remainder = 0` and `length = 0`
3. Loop up to `k` times:
   - Compute `remainder = (remainder * 10 + 1) % k`
   - Increment `length`
   - If `remainder == 0`, return `length`
4. If we exit the loop without finding 0, return -1

**Time Complexity**: O(k) - we iterate at most k times

**Space Complexity**: O(1) - we only use a few variables

## Alternative Approach: Using a Set

We can explicitly track seen remainders using a hash set:

1. Use a set to store remainders we've seen
2. Start with `remainder = 1 % k`, `length = 1`
3. While `remainder != 0`:
   - If remainder is in the set, return -1 (cycle detected)
   - Add remainder to the set
   - Compute next: `remainder = (remainder * 10 + 1) % k`
   - Increment length
4. Return length

**Time Complexity**: O(k)
**Space Complexity**: O(k) - for the set

## Edge Cases to Consider

1. **k = 1**: Always returns 1 (since 1 % 1 == 0)
2. **k is even**: Always returns -1
3. **k is divisible by 5**: Always returns -1
4. **k is prime (not 2 or 5)**: Will always have a solution
5. **Large k**: Make sure to use modular arithmetic to avoid overflow

## Common Mistakes

1. **Trying to build the actual number**: Numbers can be very large (exceeding 64-bit integers)
2. **Not detecting cycles**: Without cycle detection, the algorithm might loop forever
3. **Not handling k = 1 separately**: This is a trivial case
4. **Forgetting the edge case check**: Always check for multiples of 2 and 5 first

## Example Walkthrough

**Example: k = 3**

| Iteration | remainder calculation | remainder | length |
|-----------|----------------------|-----------|--------|
| 1 | (0 * 10 + 1) % 3 | 1 | 1 |
| 2 | (1 * 10 + 1) % 3 | 2 | 2 |
| 3 | (2 * 10 + 1) % 3 | 0 | 3 |

Answer: 3 (the number is 111)

**Example: k = 7**

| Iteration | remainder calculation | remainder | length |
|-----------|----------------------|-----------|--------|
| 1 | (0 * 10 + 1) % 7 | 1 | 1 |
| 2 | (1 * 10 + 1) % 7 | 4 | 2 |
| 3 | (4 * 10 + 1) % 7 | 6 | 3 |
| 4 | (6 * 10 + 1) % 7 | 5 | 4 |
| 5 | (5 * 10 + 1) % 7 | 2 | 5 |
| 6 | (2 * 10 + 1) % 7 | 0 | 6 |

Answer: 6 (the number is 111111)

## Optimization Tips

1. **Early termination**: Check for k % 2 and k % 5 before starting the loop
2. **Use modular arithmetic**: Never compute the actual large numbers
3. **Limit iterations**: Loop at most k times (pigeonhole principle)
