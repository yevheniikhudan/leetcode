# Find Median from Data Stream - Tutorial

## Approach

To efficiently find the median from a data stream, use two heaps:
- **Max-heap** (for the lower half of numbers)
- **Min-heap** (for the upper half of numbers)

### Steps
1. Add each new number to the max-heap (lower half).
2. Move the largest from max-heap to min-heap (upper half).
3. If min-heap has more elements, move the smallest from min-heap back to max-heap.
4. The median is:
   - The top of max-heap if odd number of elements
   - The average of tops of both heaps if even

### Complexity
- `addNum`: O(log N)
- `findMedian`: O(1)

This approach ensures both efficient insertion and median retrieval.
