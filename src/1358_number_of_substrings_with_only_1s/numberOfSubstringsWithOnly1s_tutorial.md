# Number of Substrings With Only 1s - Tutorial

## Key Insights
- Every contiguous block of k '1's contributes k * (k + 1) / 2 substrings.
- Iterate through the string, count the length of each block of consecutive '1's, and sum up their contributions.

## Steps
1. Initialize a counter for the current block of '1's.
2. For each character:
   - If '1', increment the counter.
   - If '0', add the block's contribution to the result and reset the counter.
3. After the loop, add the last block's contribution.

## Example
For s = "0110111":
- Blocks: [1], [2], [3]
- Contributions: 1, 3, 6
- Total: 1 + 3 + 6 = 10 (check for overlapping substrings in the actual implementation).

## Implementation
- Use a loop to count blocks and sum their contributions.
- Time complexity: O(n)
- Space complexity: O(1)

## Edge Cases
- All zeros: return 0
- All ones: return n * (n + 1) / 2
