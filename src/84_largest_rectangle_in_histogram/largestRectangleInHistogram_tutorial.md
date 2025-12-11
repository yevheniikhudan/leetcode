# Largest Rectangle in Histogram - Tutorial

## Problem Understanding

Given a histogram represented as an array of bar heights, we need to find the largest rectangle that can be formed within the histogram. Each bar has width 1, and we can only form rectangles using consecutive bars.

## Approaches

### Approach 1: Brute Force (Not Recommended)

For each bar, we could try to extend left and right as far as possible while maintaining the minimum height. This would take O(n²) time.

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

This approach is too slow for the given constraints (n up to 10⁵).

### Approach 2: Divide and Conquer

Similar to finding maximum subarray, we can use divide and conquer. Find the minimum height bar, which divides the histogram into left and right parts. The maximum rectangle either:
1. Lies entirely in the left part
2. Lies entirely in the right part
3. Crosses the minimum bar (width * min_height)

**Time Complexity:** O(n log n) average, O(n²) worst case  
**Space Complexity:** O(log n) for recursion

### Approach 3: Monotonic Stack (Optimal)

The key insight is that for each bar, we need to know:
- How far left can we extend while maintaining at least this bar's height?
- How far right can we extend while maintaining at least this bar's height?

We can use a **monotonic increasing stack** to efficiently find these boundaries.

## Algorithm (Monotonic Stack)

### Key Concepts:

1. **Monotonic Increasing Stack**: We maintain a stack where bar heights are in increasing order.

2. **When to Pop**: When we encounter a bar shorter than the stack top, we know the stack top cannot extend further right.

3. **Area Calculation**: When popping a bar from the stack:
   - Height = height of the popped bar
   - Width = current_index - left_boundary - 1
   - Left boundary = index of the new stack top (or -1 if stack is empty)

### Steps:

1. Create a stack to store indices (not heights!)
2. Iterate through each bar:
   - While current bar is shorter than stack top:
     - Pop the stack top (this is our rectangle height)
     - Calculate width using popped index and current boundaries
     - Update maximum area
   - Push current index onto stack
3. After iteration, process remaining bars in stack (they can extend to the end)

### Why It Works:

- The stack maintains bars that can potentially be extended to the right
- When we pop a bar, we know its right boundary (current position)
- The stack top after popping gives us the left boundary
- This ensures we don't miss any possible rectangles

## Visual Example

For heights = [2, 1, 5, 6, 2, 3]:

```
    6
  5 □
  □ □       
2 □ □ 2 3
□ 1 □ □ □
□ □ □ □ □
0 1 2 3 4 5
```

The algorithm processes:
1. Push 0 (height 2)
2. Pop 0, push 1 (height 1 is shorter)
   - Rectangle at index 0: height=2, width=1, area=2
3. Push 2 (height 5)
4. Push 3 (height 6)
5. Pop 3, push 4 (height 2 is shorter)
   - Rectangle at index 3: height=6, width=1, area=6
6. Pop 2 (height 5 > 2)
   - Rectangle at index 2: height=5, width=2, area=10 ← Maximum!
7. Push 5 (height 3)
8. Process remaining stack

## Edge Cases

1. **Empty array**: Not possible per constraints
2. **Single bar**: Area is the bar's height
3. **Increasing heights**: Process all at the end
4. **Decreasing heights**: Process immediately as we go
5. **All same height**: Rectangle spans entire width
6. **Heights with zeros**: Zero height means no rectangle at that position

## Common Pitfalls

1. Storing heights instead of indices in the stack
2. Forgetting to process remaining elements after the loop
3. Incorrect width calculation (off-by-one errors)
4. Not handling empty stack case when calculating left boundary

## Time and Space Complexity

**Time Complexity:** O(n)
- Each bar is pushed and popped at most once
- Total operations: 2n = O(n)

**Space Complexity:** O(n)
- Stack can contain at most n elements (in case of increasing heights)

## Key Takeaways

1. Monotonic stack is perfect for "next/previous greater/smaller element" problems
2. Store indices, not values, when you need to calculate widths
3. The stack maintains potential rectangle heights in increasing order
4. When popping, we've found the right boundary for that height
5. The new stack top (after popping) gives us the left boundary
