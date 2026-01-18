# Tutorial: Surrounded Regions

## Understanding the Problem
Given a board of 'X' and 'O', flip all 'O's that are completely surrounded by 'X' to 'X'. Border-connected 'O's are not flipped.

## Visual Example
- See problem statement for a sample grid and output.

## Approaches
### 1. Reverse Flood Fill from Borders (Most Efficient)
- Start DFS/BFS from all border 'O's and mark them as safe.
- After marking, flip all unmarked 'O's to 'X', and revert safe marks to 'O'.
- Time: O(m*n), Space: O(m*n)

### 2. Brute Force DFS for Each 'O'
- For each 'O', check if it is surrounded by 'X' using DFS.
- Time: O((m*n)^2), Space: O(m*n)

## Complexity
- Reverse flood fill: O(m*n) time and space.
- Brute force: O((m*n)^2) time, O(m*n) space.

## Edge Cases
- No 'O's on the board.
- All 'O's are on the border.

## Optimization Notes
- The reverse flood fill approach is optimal and preferred for this problem.
