# Trapping Rain Water - Tutorial

## Problem Understanding

Given an elevation map represented by an array, calculate how much rainwater can be trapped between the bars.

**Key Insight**: Water at position `i` is determined by the minimum of:
- The maximum height to the **left** of position `i`
- The maximum height to the **right** of position `i`

**Water at position i** = `min(max_left, max_right) - height[i]`

(If the result is negative, no water can be trapped at that position)

## Visual Example

```
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Elevation map:
    3|       █
    2|   █   █ █ █
    1| █ █ █ █ █ █
    0|█
Index: 0 1 2 3 4 5 6 7 8 9 10 11

Water trapped (shown as ~):
    3|       █
    2|   █ ~ █ █ █
    1| █ █ █ █ █ █
    0|█
      0 1 2 3 4 5 6 7 8 9 10 11

At index 2: max_left=1, max_right=3, water = min(1,3) - 0 = 1
At index 5: max_left=2, max_right=3, water = min(2,3) - 0 = 2
```

## Approach 1: Two Pointers (Optimal)

### Strategy

Use two pointers starting from both ends, tracking the maximum heights seen so far:

1. Initialize `left = 0`, `right = n-1`
2. Track `left_max` and `right_max` (initially 0)
3. While `left < right`:
   - If `height[left] < height[right]`:
     - Water at left depends only on `left_max` (right side is guaranteed higher)
     - If `height[left] >= left_max`: update `left_max`
     - Else: add `left_max - height[left]` to total water
     - Move `left++`
   - Else:
     - Water at right depends only on `right_max` (left side is guaranteed higher)
     - If `height[right] >= right_max`: update `right_max`
     - Else: add `right_max - height[right]` to total water
     - Move `right--`

### Why This Works

The key insight is:
- When `height[left] < height[right]`, we know the water at `left` is limited by `left_max`
- We don't need to know the exact `right_max` because we already know there's a higher bar on the right
- This allows us to calculate water in a single pass

### Time & Space Complexity

- **Time**: O(n) - Single pass through the array
- **Space**: O(1) - Only using a few variables

## Approach 2: Dynamic Programming

### Strategy

Precompute the maximum heights to the left and right of each position:

1. Create `left_max` array where `left_max[i]` = max height from 0 to i
2. Create `right_max` array where `right_max[i]` = max height from i to n-1
3. For each position, water = `max(0, min(left_max[i], right_max[i]) - height[i])`

### Time & Space Complexity

- **Time**: O(n) - Three passes (left_max, right_max, calculate water)
- **Space**: O(n) - Two arrays for left_max and right_max

## Approach 3: Stack (Monotonic Stack)

### Strategy

Use a stack to find boundaries for trapped water:

1. Maintain a decreasing stack of indices
2. When we find a height greater than the top of stack:
   - Pop from stack and calculate trapped water
   - The popped element forms the bottom of the container
   - The current element and the new top of stack form the sides

### Time & Space Complexity

- **Time**: O(n) - Each element pushed and popped once
- **Space**: O(n) - Stack storage

## Comparison of Approaches

| Approach | Time | Space | Difficulty |
|----------|------|-------|------------|
| Two Pointers | O(n) | O(1) | Medium |
| Dynamic Programming | O(n) | O(n) | Easy |
| Monotonic Stack | O(n) | O(n) | Hard |

**Recommended**: Two Pointers (optimal space complexity)

## Key Insights

1. **Water level at each position**: Determined by the minimum of max heights on both sides
2. **Two pointers optimization**: Process from both ends, using the smaller side to determine water
3. **No water at edges**: First and last positions can't trap water
4. **Greedy choice**: Always process the side with the smaller height

## Common Mistakes

1. **Forgetting to check negative values**: Water can't be negative
2. **Not handling edge cases**: Arrays with length < 3 can't trap water
3. **Incorrect pointer movement**: Move the pointer with the smaller height, not the larger one
4. **Off-by-one errors**: Be careful with array bounds

## Edge Cases

1. **Empty array or single element**: Return 0
2. **Two elements**: Can't trap water, return 0
3. **Flat array** (all same height): No water trapped
4. **Strictly increasing**: No water trapped
5. **Strictly decreasing**: No water trapped
6. **Valley in middle**: Maximum water trapped

## Step-by-Step Example (Two Pointers)

```
height = [4,2,0,3,2,5]
         L           R

Initial: left=0, right=5, left_max=0, right_max=0, water=0

Step 1: height[0]=4 < height[5]=5
  height[0]=4 >= left_max=0, update left_max=4
  left=1

Step 2: height[1]=2 < height[5]=5
  height[1]=2 < left_max=4, water += 4-2 = 2
  water=2, left=2

Step 3: height[2]=0 < height[5]=5
  height[2]=0 < left_max=4, water += 4-0 = 4
  water=6, left=3

Step 4: height[3]=3 < height[5]=5
  height[3]=3 < left_max=4, water += 4-3 = 1
  water=7, left=4

Step 5: height[4]=2 < height[5]=5
  height[4]=2 < left_max=4, water += 4-2 = 2
  water=9, left=5

left >= right, stop

Total water = 9
```

## Related Concepts

- **Two Pointers**: Processing from both ends
- **Greedy Algorithm**: Making locally optimal choices
- **Monotonic Stack**: Maintaining increasing/decreasing order
- **Dynamic Programming**: Precomputing auxiliary information
