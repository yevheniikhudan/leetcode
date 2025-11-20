# Set Intersection Size At Least Two - Tutorial

## Key Insights
- This is a greedy problem that requires careful interval management.
- Sort intervals by end point (and by start point descending if ends are equal).
- Greedily choose the largest two elements from each interval that haven't been covered yet.

## Steps
1. Sort intervals by `end` (ascending), then by `start` (descending).
2. Maintain the last two elements added to the result set.
3. For each interval:
   - If both last elements are in the interval, skip.
   - If one last element is in the interval, add the largest possible element.
   - If no last elements are in the interval, add the two largest elements.

## Example
For intervals = [[1,3],[3,7],[8,9]]:
- After sorting: [[1,3],[3,7],[8,9]]
- Process [1,3]: add 2, 3
- Process [3,7]: 3 is covered, add 4
- Process [8,9]: add 8, 9
- Result: [2, 3, 4, 8, 9], size = 5

## Implementation
- Time complexity: O(n log n) for sorting
- Space complexity: O(1) excluding output

## Edge Cases
- Single interval: return 2
- Overlapping intervals: careful tracking of covered elements
