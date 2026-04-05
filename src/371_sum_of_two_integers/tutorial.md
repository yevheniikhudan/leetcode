# 371. Sum of Two Integers — Tutorial

---

## Understanding the Problem

We need to add two integers using only bit manipulation operations, **without using `+` or `-` operators**.

The key insight is that addition can be decomposed into:
1. **XOR** (`^`) - addition without carry
2. **AND** (`&`) and bit shift (`<<`) - carry generation

---

## Visual Example

Adding `1 + 2` using bit operations:

```
  a = 1   (binary: 001)
  b = 2   (binary: 010)
  
Step 1: XOR (sum without carry)
  001 ^ 010 = 011 (which is 3, but this assumes no carry interaction)
  
Step 2: AND + SHIFT (carry)
  (001 & 010) << 1 = 010 << 1 = 100 (which is 4, the carry contribution)
  
Step 3: Repeat until no carry
  011 + 100 → XOR = 111 (7... wait, this is wrong)
```

Actually, let me correct this:

```
a = 1 (binary: 001)
b = 2 (binary: 010)

Iteration 1:
  XOR: 001 ^ 010 = 011 (sum without carry) → a = 011
  AND << 1: (001 & 010) << 1 = 000 << 1 = 000 (no carry) → b = 000
  b is 0, so we're done. Result: 011 = 3 ✓
```

---

## Approaches

### 1. Bit Manipulation Loop ✅ Recommended

Repeat until there's no carry:

1. `sum = a ^ b` (XOR gives sum without carry)
2. `carry = (a & b) << 1` (AND + shift gives carry)
3. Update: `a = sum`, `b = carry`
4. Loop while `b != 0`

**Time:** O(log(max(a, b))) | **Space:** O(1)

---

### 2. Recursive Bit Manipulation

Same logic but using recursion instead of a loop:

```
def getSum(a, b):
    if b == 0:
        return a
    return getSum(a ^ b, (a & b) << 1)
```

**Time:** O(log(max(a, b))) | **Space:** O(log(max(a, b))) (call stack)

---

### 3. Language Built-in (Cheating)

Use language features designed for addition (not allowed in interview):

```python
return a + b  # This defeats the purpose!
```

Not valid for this problem.

---

## Complexity Summary

| Approach                | Time                 | Space   |
|-------------------------|----------------------|---------|
| Bit Manipulation Loop   | O(log(max(a, b)))    | O(1)    |
| Recursive Bit Manip     | O(log(max(a, b)))    | O(log(max(a, b))) |

---

## Key Concepts & Patterns

- **XOR (`^`):** Addition without considering carry (`0 ^ 0 = 0`, `0 ^ 1 = 1`, `1 ^ 1 = 0`)
- **AND (`&`) + shift (`<< 1`):** Computes carry (`1 & 1 = 1`, then shift left to position carry correctly)
- **Loop until no carry:** Once `b` becomes 0, all carries are resolved

---

## Edge Cases & Common Pitfalls

| Case                | Notes                                              |
|---------------------|----------------------------------------------------|
| `a = 0, b = 0`      | Result is 0 (no carry ever generated)              |
| `a = -1, b = 1`     | Result is 0 (negatives use 2's complement)        |
| `a = -5, b = 3`     | Negative numbers work seamlessly with bit ops      |
| Language limits     | Different languages handle negative ints differently|
| Infinite loop risk  | Ensure `b` becomes 0 in finite iterations         |

---

## Optimization Notes

- The loop runs in **O(log n)** time because each iteration shifts the carry left, effectively doubling its effect.
- **Python caveat:** Python has arbitrary precision integers. To handle this, mask to 32-bit for LeetCode constraints.
- Recursive approach is elegant but uses stack space; iterative is preferred in practice.
