# 190. Reverse Bits — Tutorial

---

## Understanding the Problem

We need to reverse the binary representation of a 32-bit unsigned integer.

Example: `43261596` in binary is `00000010100101000001111010011100`. Reversing all 32 bits gives `00111001011110000101010100000010`, which is `964176192` in decimal.

---

## Visual Example

```
Original:  00000010100101000001111010011100
Reversed:  00111001011110000101010100000010
           ↑                              ↑
        (position 0)                 (position 31)
```

The bit at position 0 goes to position 31, position 1 goes to position 30, and so on.

---

## Approaches

### 1. Bit by Bit Processing ✅ Recommended

Extract bits from the right side of the input and build the result from left to right:

1. Initialize `result = 0`
2. Loop 32 times:
   - Extract the rightmost bit of `n`: `bit = n & 1`
   - Shift `result` left by 1: `result <<= 1`
   - Add the extracted bit to `result`: `result |= bit`
   - Shift `n` right by 1: `n >>= 1`
3. Return `result`

**Time:** O(1) (always 32 iterations) | **Space:** O(1)

---

### 2. Byte Swap (Java Built-in)

For languages with built-in utilities, use `Integer.reverse()` (Java):

```java
return Integer.reverse(n);
```

Not learning-focused, but valid for production.

**Time:** O(1) | **Space:** O(1)

---

### 3. String Conversion

Convert to binary string, reverse it, convert back:

```python
binary = bin(n)[2:].zfill(32)  # Remove '0b', pad to 32 bits
reversed_binary = binary[::-1]
return int(reversed_binary, 2)
```

Simple but less efficient due to string operations.

**Time:** O(1) (fixed 32 bits) | **Space:** O(1) (fixed size)

---

## Complexity Summary

| Approach             | Time    | Space   |
|----------------------|---------|---------|
| Bit by Bit           | O(1)    | O(1)    |
| Built-in Reverse     | O(1)    | O(1)    |
| String Conversion    | O(1)    | O(1)    |

---

## Key Concepts & Patterns

- **Bit extraction:** `n & 1` gets the rightmost bit
- **Bit shifting:** `<<` shifts left, `>>` shifts right
- **Building result:** Use `|=` to set bits in result
- **32-bit constraint:** Always iterate exactly 32 times or use unsigned type

---

## Edge Cases & Common Pitfalls

| Case               | Notes                                              |
|--------------------|-----------------------------------------------------|
| `n = 0`            | All zeros → reversed is all zeros                  |
| `n = 2^31 - 1`     | Max positive (31 ones) → 32 ones reversed         |
| `n = 2^31`         | Single bit at position 31 → flips to position 0   |
| Sign bit confusion | In Java, treat input/output as signed 32-bit ints |

---

## Optimization Notes

- The bit-by-bit approach is the standard interview solution — clear, correct, and efficient.
- No optimization needed; the problem is already O(1) fixed time.
- Language-specific built-ins (like `Integer.reverse()`) are fine but learn the bit manipulation approach first.
