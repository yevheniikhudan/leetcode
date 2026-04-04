# 50. Pow(x, n) — Tutorial

---

## Understanding the Problem

We need to compute `x^n` efficiently. The naive approach of multiplying `x` by itself `n` times runs in O(n) time, which is too slow for large `n` (up to 2³¹ - 1).

Key observations:
- `n` can be **negative** → result is `1 / x^|n|`
- `n` can be **zero** → result is always `1`
- `n` can be **INT_MIN** → `-n` overflows a 32-bit integer, must use 64-bit

---

## Visual Example

Computing `2^10` with fast exponentiation:

```
2^10
├── 2^5 * 2^5
│   ├── 2^2 * 2^2 * 2
│   │   ├── 2^1 * 2^1
│   │   │   └── 2
```

Instead of 10 multiplications, we only need ~4. Each step **halves** the exponent.

---

## Approaches

### 1. Fast Power — Recursive (Divide & Conquer) ✅ Recommended

Split the problem in half at each step:
- If `n` is even: `x^n = x^(n/2) * x^(n/2)`
- If `n` is odd: `x^n = x^(n/2) * x^(n/2) * x`
- If `n` is negative: compute `x^|n|` then take reciprocal

Each recursive call reduces `n` by half, giving a logarithmic depth.

**Time:** O(log n) | **Space:** O(log n) (call stack)

---

### 2. Fast Power — Iterative (Bit Manipulation)

Instead of recursion, iterate over the **bits** of `n`:
- If the current bit is `1`, multiply the result by the current base
- Square the base at every step
- Continue until all bits are processed

This avoids recursion stack overhead.

**Time:** O(log n) | **Space:** O(1)

---

### 3. Brute Force

Multiply `x` by itself `|n|` times in a loop.

**Time:** O(n) | **Space:** O(1)

Not acceptable for large `n`.

---

## Complexity Summary

| Approach             | Time      | Space     |
|----------------------|-----------|-----------|
| Brute Force          | O(n)      | O(1)      |
| Recursive Fast Power | O(log n)  | O(log n)  |
| Iterative Fast Power | O(log n)  | O(1)      |

---

## Key Concepts & Patterns

- **Binary Exponentiation (Exponentiation by Squaring):** Core algorithmic pattern for fast power computation.
- **Negative exponents:** Convert to positive and invert the base or result.
- **Integer overflow:** `n = -2³¹` cannot be negated as a 32-bit int. Use `long` or `long long`.

---

## Edge Cases & Common Pitfalls

| Case                   | Notes                                      |
|------------------------|--------------------------------------------|
| `n = 0`                | Always returns `1.0`                       |
| `n < 0`                | Must negate `n`; watch out for INT_MIN     |
| `x = 1.0` or `x = -1.0` | Result is trivially `±1`               |
| `n = INT_MIN` (-2³¹)   | Use `long`/`long long` when negating       |
| `x = 0.0, n > 0`       | Returns `0.0`                              |

---

## Optimization Notes

- The iterative approach is preferable in practice to avoid stack overhead.
- Both recursive and iterative versions are O(log n) — choose based on style preference.
- The pattern generalizes to **modular exponentiation** (used in cryptography).
