# Daily Temperatures - Tutorial

## Problem Understanding

For each day, we need to find how many days until a warmer temperature occurs. If no warmer day exists in the future, the answer is 0.

**Example:** `temperatures = [73, 74, 75, 71, 69, 72, 76, 73]`

```
Day 0 (73°): Next warmer is day 1 (74°) → wait 1 day
Day 1 (74°): Next warmer is day 2 (75°) → wait 1 day
Day 2 (75°): Next warmer is day 6 (76°) → wait 4 days
Day 3 (71°): Next warmer is day 5 (72°) → wait 2 days
Day 4 (69°): Next warmer is day 5 (72°) → wait 1 day
Day 5 (72°): Next warmer is day 6 (76°) → wait 1 day
Day 6 (76°): No warmer day → 0
Day 7 (73°): No warmer day → 0

Answer: [1, 1, 4, 2, 1, 1, 0, 0]
```

## Approach 1: Brute Force (Not Optimal)

**Idea:** For each day, scan forward to find the next warmer day.

```
for i in range(n):
    for j in range(i+1, n):
        if temperatures[j] > temperatures[i]:
            answer[i] = j - i
            break
```

**Time Complexity:** O(n²) - Too slow for large inputs  
**Space Complexity:** O(1) excluding output array

**Why it's inefficient:** We repeatedly scan the same elements, wasting computation.

## Approach 2: Monotonic Stack (Optimal)

**Key Insight:** This is a classic "next greater element" problem, perfect for a **monotonic decreasing stack**.

### What is a Monotonic Stack?

A monotonic stack maintains elements in a specific order (increasing or decreasing). For this problem, we use a **decreasing monotonic stack** that stores **indices** of temperatures.

**Stack Property:** Temperatures at indices in the stack are in **decreasing order** from bottom to top.

### Why This Works:

When we encounter a new temperature:
- If it's **warmer** than the temperature at the top of the stack, we've found the "next warmer day" for that stack element
- We can **pop** that element and record the answer
- We keep popping until the stack top has a temperature ≥ current temperature
- Then we **push** the current index onto the stack

### Algorithm:

1. **Initialize:**
   - Result array filled with 0s
   - Empty stack (stores indices)

2. **Iterate through each day (index i):**
   - **While stack is not empty AND current temp > temp at stack top:**
     - Pop index from stack
     - Calculate days waited: `i - popped_index`
     - Store in result
   - **Push current index to stack**

3. **Return result**

### Example Walkthrough: `[73, 74, 75, 71, 69, 72, 76, 73]`

```
i=0, temp=73:
  Stack: []
  Action: Push 0
  Stack: [0] (temps: [73])
  Result: [0,0,0,0,0,0,0,0]

i=1, temp=74:
  temp(74) > temp at stack top(73)
  Pop 0, record: result[0] = 1 - 0 = 1
  Push 1
  Stack: [1] (temps: [74])
  Result: [1,0,0,0,0,0,0,0]

i=2, temp=75:
  temp(75) > temp at stack top(74)
  Pop 1, record: result[1] = 2 - 1 = 1
  Push 2
  Stack: [2] (temps: [75])
  Result: [1,1,0,0,0,0,0,0]

i=3, temp=71:
  temp(71) < temp at stack top(75)
  Push 3
  Stack: [2, 3] (temps: [75, 71])
  Result: [1,1,0,0,0,0,0,0]

i=4, temp=69:
  temp(69) < temp at stack top(71)
  Push 4
  Stack: [2, 3, 4] (temps: [75, 71, 69])
  Result: [1,1,0,0,0,0,0,0]

i=5, temp=72:
  temp(72) > temp at stack top(69)
  Pop 4, record: result[4] = 5 - 4 = 1
  temp(72) > temp at stack top(71)
  Pop 3, record: result[3] = 5 - 3 = 2
  temp(72) < temp at stack top(75)
  Push 5
  Stack: [2, 5] (temps: [75, 72])
  Result: [1,1,0,2,1,0,0,0]

i=6, temp=76:
  temp(76) > temp at stack top(72)
  Pop 5, record: result[5] = 6 - 5 = 1
  temp(76) > temp at stack top(75)
  Pop 2, record: result[2] = 6 - 2 = 4
  Push 6
  Stack: [6] (temps: [76])
  Result: [1,1,4,2,1,1,0,0]

i=7, temp=73:
  temp(73) < temp at stack top(76)
  Push 7
  Stack: [6, 7] (temps: [76, 73])
  Result: [1,1,4,2,1,1,0,0]

Final: Indices 6 and 7 remain in stack → they have no warmer day → already 0
```

### Why Monotonic Decreasing?

We maintain **decreasing temperatures** in the stack because:
- Any temperature that's smaller than a previous one might find its "next warmer" later
- When we find a warmer temperature, it resolves **all** smaller temperatures in the stack
- This ensures we process each element exactly once

### Stack Invariant:

At any point during iteration:
- Temperatures at stack indices are in **decreasing order** (bottom to top)
- All indices in the stack are **waiting** for their next warmer day
- All popped indices have **found** their next warmer day

## Time and Space Complexity

**Monotonic Stack Approach:**
- **Time Complexity:** O(n)
  - Each index is pushed exactly once
  - Each index is popped at most once
  - Total operations: O(n)
  
- **Space Complexity:** O(n)
  - Stack can hold up to n indices in worst case
  - Example: `[100, 90, 80, 70, 60]` → all indices stay in stack

## Edge Cases to Consider

1. **All increasing temperatures:** `[30, 40, 50, 60]`
   - Each day's answer is 1 (next day is warmer)
   - Last day is 0

2. **All decreasing temperatures:** `[100, 90, 80, 70]`
   - All answers are 0 (no future warmer day)

3. **Single temperature:** `[75]`
   - Answer is `[0]`

4. **All same temperatures:** `[70, 70, 70, 70]`
   - All answers are 0 (never warmer, only equal)

5. **Spike pattern:** `[30, 100, 30, 100]`
   - `[1, 0, 1, 0]`

## Common Mistakes

1. **Storing temperatures instead of indices**
   - Need indices to calculate the difference (days waited)

2. **Wrong stack order (increasing instead of decreasing)**
   - Won't correctly identify next warmer element

3. **Forgetting to initialize result with 0s**
   - Indices that remain in stack should default to 0

4. **Not checking stack.empty() before accessing top**
   - Can cause errors on empty stack

5. **Wrong comparison direction**
   - Should be `current > stack_top`, not `current >= stack_top`
   - Equal temperatures don't count as "warmer"

## Optimization Notes

- **Early termination:** If all remaining days are colder than current, we can skip them (implicit in stack)
- **Single pass:** We only need one iteration through the array
- **Constant time operations:** Stack push/pop are O(1)

## Pattern Recognition

This problem follows the **"Next Greater Element"** pattern. You can recognize this pattern when:
- You need to find the next element that satisfies a condition (greater, smaller, etc.)
- The condition involves comparing elements
- You need to find this for all elements in an array
- A monotonic stack can efficiently solve it

**Other problems using this pattern:**
- Next Greater Element I/II
- Online Stock Span
- Largest Rectangle in Histogram
- Trapping Rain Water

## Visual Intuition

Think of the stack as a "waiting list" of temperatures that haven't found their warmer day yet. When a warmer day arrives, it "resolves" all colder temperatures waiting in the stack.

```
Temperatures: [73, 74, 75, 71, 69, 72, 76, 73]

Stack visualization at each step:
[73]
[74] → 73 resolved (1 day)
[75] → 74 resolved (1 day)
[75, 71]
[75, 71, 69]
[75, 72] → 71, 69 resolved (2, 1 days)
[76] → 75, 72 resolved (4, 1 days)
[76, 73]

Final stack [76, 73] → no warmer days found (0, 0)
```
