# Car Fleet - Tutorial

## Problem Understanding

The Car Fleet problem involves cars traveling on a one-lane road toward a common destination. The key rules are:
1. Cars cannot pass each other
2. When a faster car catches up to a slower car, they form a fleet and travel together at the slower speed
3. We need to count how many distinct fleets reach the destination

## Key Insights

### 1. Time to Reach Destination

For each car, we can calculate how long it takes to reach the destination:
- **Time = (target - position) / speed**

This is the crucial metric because:
- A car with a longer time to reach the destination will never catch up to cars ahead of it
- A car with a shorter time will catch up to slower cars ahead

### 2. Process from Closest to Farthest

We should process cars starting from those **closest to the target** and moving backward:
- Cars closer to the target arrive first
- Cars behind can only catch up if they arrive at the same time or earlier
- If a car behind has a longer arrival time, it forms a new fleet

### 3. Stack-Based Approach

We can use a monotonic decreasing stack of arrival times:
- Process cars from closest to target to farthest
- For each car, calculate its time to reach the destination
- If the current car's time is greater than the car ahead (top of stack), it cannot catch up → new fleet
- If the current car's time is less than or equal to the car ahead, it catches up → same fleet (don't add to stack)
- The size of the stack at the end is the number of fleets

## Algorithm Strategy

### Step 1: Pair and Sort
Combine position and speed into pairs, then sort by position in **descending order** (closest to target first).

### Step 2: Calculate Times
For each car (from closest to farthest):
- Calculate time to reach destination
- Compare with the previous car's time

### Step 3: Count Fleets
- If current car takes longer than the previous car → it's a new fleet
- If current car takes same time or less → it catches up (part of previous fleet)

## Example Walkthrough

**Input:** target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

**Step 1: Sort by position (descending)**
```
Position: 10  8  5  3  0
Speed:     2  4  1  3  1
Time:      1  1  7  3  12
```

**Step 2: Process from position 10 to 0**
- Position 10: time = 1.0 → First fleet (stack: [1.0])
- Position 8: time = 1.0 → Catches up to position 10 (stack: [1.0])
- Position 5: time = 7.0 > 1.0 → New fleet (stack: [1.0, 7.0])
- Position 3: time = 3.0 < 7.0 → Catches up to position 5 (stack: [1.0, 7.0])
- Position 0: time = 12.0 > 7.0 → New fleet (stack: [1.0, 7.0, 12.0])

**Result:** 3 fleets

## Edge Cases to Consider

1. **Single car**: Always forms 1 fleet
2. **All cars at same speed**: Number of fleets equals number of unique times to destination
3. **All cars arrive at different times**: Process based on arrival times
4. **Cars that meet exactly at destination**: Still counted as one fleet

## Complexity Analysis

- **Time Complexity**: O(n log n) due to sorting
- **Space Complexity**: O(n) for storing pairs and stack

## Alternative Approach

Instead of using a stack, you can:
1. Sort cars by position (descending)
2. Track the maximum time seen so far
3. Count fleets: increment counter when current time > maximum time
4. Update maximum time

This approach is more space-efficient (O(1) extra space after sorting) and achieves the same result.
