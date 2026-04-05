# Number of 1 Bits — Tutorial

Difficulty: Easy

This tutorial explains conceptual approaches and trade-offs for counting the number of `1` bits (the Hamming weight) in a 32-bit integer. This file contains no code — only ideas, patterns, and guidance.

---

## Problem recap

Given a 32-bit integer (interpretation as unsigned for bit counting), return the number of bits set to `1` in its binary representation. On languages without an unsigned type, treat the input as a 32-bit two's-complement value and count bits across the 32-bit representation.

Examples (conceptual):
- 00000000000000000000000000001011 → 3
- 00000000000000000000000010000000 → 1
- 11111111111111111111111111111101 → 31

Goal: linear or better in the number of set bits, using constant extra space where possible.

---

## Key ideas

- Bit-level operations (AND, shifts, masks, XOR) manipulate individual bits directly and are the natural tools for this task.
- Many efficient algorithms exploit the cancellation of the least-significant `1` bit (n & (n-1)) or precomputed small-table lookups to trade time for space.
- There are both simple, intuitive methods (scan each bit) and highly optimized O(1) bit-parallel counting methods (population count / parallel summation).

---

## Approaches (conceptual, ordered by typical preference)

1. XOR/Mask scanning (simple)
- Iterate through 32 bit positions: use a mask that shifts across positions and test whether the masked bit is set.
- Simple and predictable: O(32) = O(1) time per value, constant space.
- Good when clarity matters and performance is not critical beyond constant-time per value.

2. Brian Kernighan’s method (n & (n-1))
- Repeatedly clear the least-significant `1` bit: each step does `n = n & (n - 1)` and increments a counter.
- Loop runs exactly as many times as there are `1` bits → O(k) where k is number of set bits.
- Very efficient when values are sparse (few `1` bits), still constant extra space.

3. Table / lookup method
- Precompute population counts for small chunks (e.g., all 16-bit patterns or 8-bit patterns).
- Split the 32-bit value into chunks, sum table lookups.
- Time becomes number of chunks (e.g., 4 lookups for 8-bit table) — very fast in practice.
- Uses small extra memory for the table; great for repeated calls.

4. Hardware / builtin instructions
- Many platforms provide a hardware population-count instruction (POPCNT) or library intrinsic.
- When available, use the builtin for best performance; it typically executes in a few cycles.

5. Parallel (SWAR / bit-parallel) algorithms
- Use a sequence of bitwise masks and shifts to sum groups of bits in parallel (e.g., pairwise sum, then 2-bit groups, then 4-bit groups...).
- Achieves O(log w) operations (w = word size) and avoids loops per set bit. Useful when implementing in languages/environments without a builtin popcount and where micro-optimizations matter.

---

## Complexity

- Mask scanning: O(1) time (32 iterations), O(1) space.
- Kernighan’s method: O(k) time where k = number of '1' bits, O(1) space.
- Lookup table: O(1) time (a few lookups), O(1) space plus table memory.
- Hardware popcount: O(1) time, constant and typically fastest in practice.

All practical approaches use constant extra space.

---

## Edge cases and language considerations

- Signed vs unsigned representation:
  - In languages lacking an unsigned 32-bit type, interpret the input as its raw 32-bit two's-complement bit pattern. Ensure any shifting or masking preserves the 32-bit view (avoid sign-extending arithmetic shifts).
- Negative numbers:
  - Negative inputs have many `1` bits in two's-complement; methods that iterate by clearing least-significant `1` bit still work correctly.
- Very large number of calls:
  - For hot loops or bulk processing, prefer the hardware/popcount or table approach.
- Performance on constrained devices:
  - Kernighan's method excels when typical inputs have few set bits (sparse).

---

## Testing suggestions

Include tests that cover:
- Minimal and maximal values: 0 (expect 0), all-ones (expect 32).
- Typical small values: 1, 3, 11, 128.
- Negative values when interpreted as 32-bit two's complement.
- Randomized values: compare multiple algorithm implementations (e.g., table vs Kernighan vs builtin) to validate correctness.
- Edge and pathological cases: many repeated calls, to benchmark performance differences.

Test output should follow the repository's format: `actual | expected | PASS/FAIL`.

---

## Common pitfalls

- Using language shifts that sign-extend for negative values (use unsigned shifts or masks to preserve logical bit positions).
- Relying on default integer widths without considering platform differences; explicitly reason in terms of 32-bit patterns.
- Forgetting to account for duplicate or repeated calls where a table or builtin may amortize cost better.
- Implementing a loop testing all bits when the input distribution favors sparse set bits — Kernighan’s method would be faster.

---

## Variants & related problems

- Counting bits for all numbers in a range (e.g., 0..n): can be optimized using DP or prefix methods.
- Single Number / bitwise combination problems: use bit-level properties to reconstruct values from combined patterns.
- Popcount for arbitrary-length bitstrings: apply chunking and table or streaming methods.

---

## Optimization notes

- If portability and simplicity are primary goals, implement Kernighan’s method or a 32-iteration mask scan.
- If performance is critical and a platform intrinsic exists, use the builtin/popcount instruction.
- For repeated, high-throughput workloads, a small lookup table (8- or 16-bit) provides a fast, deterministic method on all platforms.

---

Summary: Counting `1` bits is a canonical bit-manipulation task with multiple valid solutions. Choose the approach based on expected input sparsity, available hardware support, and the need for portability vs raw speed.