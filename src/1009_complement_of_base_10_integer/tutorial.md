# Tutorial: Complement of Base 10 Integer

## Understanding the Problem
You are given a non-negative integer and must flip every bit in its binary representation.

The important detail is that you only flip the bits that are part of the number's actual representation. You do not flip leading zeroes outside that width.

Examples:
- `5` is `101`, so the complement is `010`, which is `2`
- `7` is `111`, so the complement is `000`, which is `0`
- `0` is a special case because its binary representation is just `0`, so its complement is `1`

## Visual Intuition
For `n = 10`:

Binary form:
`1010`

Flip every bit in that width:
`0101`

Convert back to decimal:
`5`

## Approach 1 (Most Efficient): Bit Mask and XOR
### Strategy
1. Determine how many bits are used by `n`.
2. Build a mask of the same width containing all `1`s.
3. XOR the number with that mask.

If `n = 10` (`1010`), the mask is `1111`.

Then:
- original: `1010`
- mask: `1111`
- result: `0101`

### Why It Works
XOR with `1` flips a bit:
- `0 ^ 1 = 1`
- `1 ^ 1 = 0`

Using an all-ones mask of the correct width flips exactly the bits that belong to the number.

### Complexity
- Time: `O(log n)`
- Space: `O(1)`

## Approach 2: Bit-by-Bit Construction
### Strategy
1. Read the binary representation from right to left.
2. For each bit, append the opposite bit into the answer.
3. Shift the input and continue until all bits are processed.

### Why Use It
This approach makes the complement construction explicit and is useful when practicing bit operations.

### Complexity
- Time: `O(log n)`
- Space: `O(1)`

## Approach 3: String Conversion (Less Efficient Conceptually)
### Strategy
Convert the number to a binary string, flip each character, then convert back.

### Tradeoff
This is easy to understand, but it adds unnecessary conversion overhead compared with direct bit manipulation.

## Key Concepts and Patterns
- Bit manipulation
- Binary width awareness
- XOR with a mask
- Handling edge cases like `0`

## Edge Cases
- `n = 0` should return `1`
- Powers of two create complements with all lower bits set
- Numbers with all bits set, like `7 = 111`, produce `0`

## Common Pitfalls
- Forgetting that `0` needs special handling
- Flipping more bits than the number actually uses
- Building the mask with the wrong width

## Optimization Notes
The mask-plus-XOR method is the cleanest solution for this problem. It keeps the logic short, runs in constant extra space, and matches the intended bit-manipulation pattern directly.