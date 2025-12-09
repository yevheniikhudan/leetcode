# Container With Most Water - Tutorial

## Problem Understanding

Given an array representing heights of vertical lines, find two lines that form a container with the maximum water capacity.

**Key Points:**
- Container width = distance between two lines (right_index - left_index)
- Container height = minimum of the two line heights (water level)
- Container area = width × height
- Goal: Maximize area

**Visual Example:**
```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
         0  1  2  3  4  5  6  7  8

If we pick lines at index 1 (height=8) and index 8 (height=7):
- Width = 8 - 1 = 7
- Height = min(8, 7) = 7
- Area = 7 × 7 = 49
```

## Approach: Two Pointers (Optimal)

### Strategy

Use two pointers starting from both ends of the array and move them towards each other:

1. **Initialize** left pointer at start (0) and right pointer at end (n-1)
2. **Calculate area** at current positions: `area = (right - left) × min(height[left], height[right])`
3. **Update maximum** area if current area is larger
4. **Move the pointer** with the smaller height inward (left++ or right--)
5. **Repeat** until pointers meet

### Why Move the Smaller Height?

This is the **key insight**:

- The area is limited by the **shorter line** (water would overflow from the shorter side)
- Moving the **taller line** inward would:
  - Definitely decrease width
  - Can't increase height (still limited by the shorter line)
  - Therefore, area can only decrease or stay same
- Moving the **shorter line** inward:
  - Decreases width (unavoidable)
  - **Might** find a taller line, potentially increasing height
  - Gives us a chance to increase area

**Greedy Choice**: Always move the pointer pointing to the shorter line, as it's our bottleneck.

### Algorithm Steps

1. Initialize left = 0, right = n - 1, max_area = 0
2. While left < right:
   - Calculate width = right - left
   - Calculate height = min(height[left], height[right])
   - Calculate area = width × height
   - Update max_area if area is larger
   - If height[left] < height[right]: move left++
   - Else: move right--
3. Return max_area

### Example Walkthrough

```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
          L                       R

Step 1: L=0, R=8
  width=8, height=min(1,7)=1, area=8×1=8
  max_area=8
  Move L (1 < 7)

Step 2: L=1, R=8
  width=7, height=min(8,7)=7, area=7×7=49
  max_area=49
  Move R (8 >= 7)

Step 3: L=1, R=7
  width=6, height=min(8,3)=3, area=6×3=18
  max_area=49
  Move R (8 >= 3)

... continue until L >= R ...

Final max_area = 49
```

### Time & Space Complexity

- **Time**: O(n) - Single pass through the array with two pointers
- **Space**: O(1) - Only using a few variables

## Why This Works (Proof Sketch)

**Claim**: We won't miss the optimal solution by moving the smaller pointer.

**Proof**: 
- Suppose the optimal pair is at indices i and j where height[i] <= height[j]
- When our pointers reach (i, k) where k > j:
  - Area at (i, k) = (k - i) × height[i]
  - Area at (i, j) = (j - i) × height[i]
  - Since k > j, we have k - i > j - i, so area at (i, k) >= area at (i, j)
- Similar argument for the other direction
- Therefore, we'll encounter the optimal solution or better during our scan

## Common Mistakes

1. **Moving the wrong pointer**: Always move the pointer with the **smaller** height
2. **Calculating height wrong**: Must use `min(height[left], height[right])`
3. **Off-by-one errors**: Make sure left < right condition is correct
4. **Using brute force**: O(n²) checking all pairs - too slow for large inputs

## Edge Cases

1. **Two elements** (minimum input): Calculate area directly
2. **All same height**: Area decreases as width decreases
3. **Increasing heights**: Start will have largest width but might not be optimal
4. **Decreasing heights**: Similar consideration

## Comparison with Brute Force

| Approach | Time | Space | Description |
|----------|------|-------|-------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Two Pointers | O(n) | O(1) | Greedy optimal |

## Key Takeaways

1. **Greedy works**: Moving the shorter pointer is always the right choice
2. **Two pointers pattern**: Start from both ends, move based on condition
3. **Area formula**: width × min(height1, height2)
4. **Optimal**: Can't do better than O(n) time
