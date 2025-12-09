# Count Number of Homogenous Substrings - Tutorial

## Key Insights
- For a block of k identical characters, the number of homogenous substrings is k * (k + 1) // 2.
- Iterate through the string, count the length of each block, and sum their contributions.

## Steps
1. Initialize a counter for the current block.
2. For each character:
   - If same as previous, increment the counter.
   - If different, add the block's contribution to the result and reset the counter.
3. After the loop, add the last block's contribution.
4. Return the result modulo `10^9 + 7`.

## Example
For s = "abbcccaa":
- Blocks: [1], [2], [3], [2]
- Contributions: 1, 3, 6, 3
- Total: 1 + 3 + 6 + 3 = 13

## Implementation
- Time complexity: O(n)
- Space complexity: O(1)

## Edge Cases
- All different characters: return n
- All same characters: return n * (n + 1) // 2
