# Counting Bits Tutorial

## Understanding the Problem

The problem asks us to calculate the number of set bits (1s) in the binary representation of each integer from `0` to `n` and return these counts in an array. For instance, if `n = 2`:
- `0` in binary is `0`, so 0 set bits.
- `1` in binary is `1`, so 1 set bit.
- `2` in binary is `10`, so 1 set bit.
The output would be `[0, 1, 1]`.

The core challenge is efficiently determining the bit count for each number without simply iterating through its binary representation for every single number, especially given `n` can be up to `10^5`.

## Visual Examples and Diagrams

Let's look at `n = 5`:

| Number (i) | Binary Representation | Number of 1s |
|------------|-----------------------|--------------|
| 0          | `0`                   | 0            |
| 1          | `1`                   | 1            |
| 2          | `10`                  | 1            |
| 3          | `11`                  | 2            |
| 4          | `100`                 | 1            |
| 5          | `101`                 | 2            |

The target output is `[0, 1, 1, 2, 1, 2]`.

Notice patterns in the binary representations as numbers increase. For example, `4` (`100`) has one `1`. `5` (`101`) is `4 + 1`. The number of `1`s in `5` is `1` (from `4`) + `1` (from the last bit of `5`). This suggests a dynamic programming approach.

## Multiple Approaches

### 1. Brute Force (Naive Approach)

**Strategy:** For each number `i` from `0` to `n`, convert it to its binary representation and count the `1`s. This can be done by repeatedly checking the last bit (`i & 1`) and right-shifting (`i >>= 1`) until `i` becomes `0`.

**Time Complexity:** For each number `i`, counting its bits takes `O(log i)` time. Since we do this for `n+1` numbers, the total time complexity would be `O(n log n)`.
**Space Complexity:** `O(1)` for the bit counting, `O(n)` for storing the result array.

### 2. Dynamic Programming (Least Significant Bit)

**Strategy:** We can observe a relationship between `dp[i]` (number of 1s in `i`) and previous values.
For any number `i`, if `i` is even, `i = 2 * x`. The binary representation of `i` is simply the binary representation of `x` shifted left by one bit, with a `0` appended. This means `dp[i] = dp[x]`. For example, `dp[4] = dp[2]` (`100` vs `10`).
If `i` is odd, `i = 2 * x + 1`. The binary representation of `i` is the binary representation of `x` shifted left by one bit, with a `1` appended. This means `dp[i] = dp[x] + 1`. For example, `dp[5] = dp[2] + 1` (`101` vs `10`).
Combining these, `dp[i] = dp[i / 2] + (i % 2)`.

**Time Complexity:** `O(n)` since we iterate from `0` to `n` once, and each calculation `dp[i / 2]` is an `O(1)` lookup.
**Space Complexity:** `O(n)` for the `dp` array.

### 3. Dynamic Programming (Most Significant Bit)

**Strategy:** This approach uses the idea that `dp[i]` can be found by `dp[i - offset] + 1`, where `offset` is the largest power of 2 less than or equal to `i`.
Let's look at numbers and their counts:
- `0`: 0
- `1`: 1 (offset = 1) `dp[1] = dp[1-1] + 1 = dp[0] + 1 = 1`
- `2`: 1 (offset = 2) `dp[2] = dp[2-2] + 1 = dp[0] + 1 = 1`
- `3`: 2 (offset = 2) `dp[3] = dp[3-2] + 1 = dp[1] + 1 = 2`
- `4`: 1 (offset = 4) `dp[4] = dp[4-4] + 1 = dp[0] + 1 = 1`
- `5`: 2 (offset = 4) `dp[5] = dp[5-4] + 1 = dp[1] + 1 = 2`
- `6`: 2 (offset = 4) `dp[6] = dp[6-4] + 1 = dp[2] + 1 = 2`
- `7`: 3 (offset = 4) `dp[7] = dp[7-4] + 1 = dp[3] + 1 = 3`
- `8`: 1 (offset = 8) `dp[8] = dp[8-8] + 1 = dp[0] + 1 = 1`

The `offset` changes whenever we reach a new power of 2.
This means `dp[i]` is `1` plus the count of `1`s in `i` with its most significant bit removed. Removing the most significant bit is equivalent to `i - 2^k` where `2^k` is the largest power of 2 less than or equal to `i`.

**Time Complexity:** `O(n)`.
**Space Complexity:** `O(n)`.

### 4. Dynamic Programming (Brian Kernighan's Algorithm Optimization)

**Strategy:** Brian Kernighan's algorithm for counting set bits efficiently uses the property that `n & (n - 1)` removes the lowest set bit from `n`. We can apply a similar idea to dynamic programming.
`dp[i] = dp[i & (i - 1)] + 1`.
Let's trace it:
- `dp[0] = 0`
- `dp[1] = dp[1 & 0] + 1 = dp[0] + 1 = 1`
- `dp[2] = dp[2 & 1] + 1 = dp[0] + 1 = 1`
- `dp[3] = dp[3 & 2] + 1 = dp[2] + 1 = 2`
- `dp[4] = dp[4 & 3] + 1 = dp[0] + 1 = 1`
- `dp[5] = dp[5 & 4] + 1 = dp[4] + 1 = 2`

This is elegant and efficient.

**Time Complexity:** `O(n)`. Each `dp[i]` calculation takes amortized `O(1)` time due to `i & (i - 1)`.
**Space Complexity:** `O(n)`.

## Key Concepts and Patterns

*   **Bit Manipulation:** Understanding bitwise operations (`&`, `|`, `^`, `~`, `<<`, `>>`) is crucial.
*   **Dynamic Programming:** Breaking down the problem into subproblems and storing results to avoid redundant calculations. The count of bits for a number `i` can often be derived from the count of bits for a smaller number.
*   **Powers of Two:** Numbers that are powers of two (`1, 2, 4, 8, ...`) have exactly one set bit. This often serves as a base case or a pivot for DP relations.

## Edge Cases and Common Pitfalls

*   **`n = 0`:** The problem specifies `0 <= n`, so `n = 0` is a valid input. The array should start with `ans[0] = 0`.
*   **Integer Overflow:** The problem specifies `uint32_t` for C++ in similar problems, and `int` up to `10^5` in general, which fits standard integer types. However, if `n` were much larger, one would need to consider data types that can handle larger numbers.
*   **Off-by-one errors:** The result array should have length `n + 1` to accommodate counts for numbers `0` through `n`.

## Optimization Notes

The most efficient approaches are the dynamic programming solutions (`O(n)` time, `O(n)` space). Among them, the Brian Kernighan-inspired DP (`dp[i] = dp[i & (i - 1)] + 1`) is particularly concise and often performs well due to the nature of the `i & (i - 1)` operation.