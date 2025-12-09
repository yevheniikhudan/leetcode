# Keep Multiplying Found Values by Two - Tutorial

## Key Insights
- Use a set for O(1) lookup to check if a value exists in `nums`.
- Keep doubling `original` while it exists in the set.
- Stop when `original` is not found.

## Steps
1. Convert `nums` to a set for fast lookup.
2. While `original` exists in the set:
   - Multiply `original` by 2.
3. Return the final value of `original`.

## Example
For nums = [5,3,6,1,12], original = 3:
- 3 exists → original = 6
- 6 exists → original = 12
- 12 exists → original = 24
- 24 not found → return 24

## Implementation
- Time complexity: O(n + k) where k is the number of iterations (at most log of max value)
- Space complexity: O(n) for the set

## Edge Cases
- `original` not in `nums`: return `original` immediately
- Single element array: check once and return
