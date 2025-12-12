# Koko Eating Bananas - Tutorial

## Problem Understanding

Koko has `n` piles of bananas and `h` hours to eat them all. She wants to find the **minimum eating speed `k`** (bananas per hour) such that she can finish all piles within `h` hours.

**Key Rules:**
1. Each hour, Koko picks one pile and eats up to `k` bananas from it
2. If a pile has fewer than `k` bananas, she eats all of them but doesn't start another pile that hour
3. She must finish all piles within `h` hours

**Goal:** Find the minimum `k` that allows finishing all piles in `h` hours.

## Key Insights

### Insight 1: Monotonic Property

If Koko can finish at speed `k`, she can also finish at any speed greater than `k`. This creates a monotonic relationship where speeds form a pattern: slower speeds fail, and once a speed works, all faster speeds also work.

This monotonic property means we can use **binary search** to find the minimum valid speed!

### Insight 2: Search Space

**Minimum possible speed:** `1` (eat at least 1 banana per hour)  
**Maximum possible speed:** `max(piles)` (eat the largest pile in 1 hour)

Why max(piles) is sufficient?
- If we eat faster than the largest pile, we still finish in the same number of hours
- Eating one pile per hour is the fastest meaningful speed

### Insight 3: Time Calculation

For a given speed `k`, the time needed for a pile of size `p` is the ceiling of `p / k`. For example, if a pile has 11 bananas and speed is 4, we need 3 hours (not 2.75).

**Ceiling division** can be computed using the formula: `(p + k - 1) / k` using integer division.

## Algorithm: Binary Search on Answer

Instead of searching for a value in an array, we search for the **minimum valid speed**.

### The Approach:

1. Initialize left boundary to 1 and right boundary to max(piles)
2. While left is less than right:
   - Calculate mid speed
   - Check if Koko can finish at mid speed within h hours
   - If yes, try a slower speed (move right to mid)
   - If no, need faster speed (move left to mid + 1)
3. Return left as the minimum valid speed

### Why `left < right` instead of `left <= right`?

We're finding the **minimum** value that satisfies the condition:
- When we find a valid speed, we don't return immediately
- We continue searching for a potentially smaller valid speed
- The loop condition ensures we converge to the minimum

### Helper Function: Can Finish?

We need a helper function that checks if Koko can finish all piles at speed `k` within `h` hours. It sums up the ceiling division of each pile size by `k` and checks if the total is within the time limit.

## Step-by-Step Example

**Input:** `piles = [3, 6, 7, 11]`, `h = 8`

### Visual Analysis:

Testing different speeds:
- **Speed 1:** 3+6+7+11 = 27 hours (too slow)
- **Speed 2:** 2+3+4+6 = 15 hours (too slow)
- **Speed 3:** 1+2+3+4 = 10 hours (too slow)
- **Speed 4:** 1+2+2+3 = 8 hours ✓ (works!)
- **Speed 5:** 1+2+2+3 = 8 hours ✓
- **Speed 11:** 1+1+1+1 = 4 hours ✓

**Answer: 4** (minimum speed that works)

### Binary Search Process:

**Iteration 1:** Start with left=1, right=11
- Mid speed = 6
- Can finish at speed 6? Yes (6 hours ≤ 8)
- Try slower: right = 6

**Iteration 2:** left=1, right=6
- Mid speed = 3
- Can finish at speed 3? No (10 hours > 8)
- Need faster: left = 4

**Iteration 3:** left=4, right=6
- Mid speed = 5
- Can finish at speed 5? Yes (8 hours ≤ 8)
- Try slower: right = 5

**Iteration 4:** left=4, right=5
- Mid speed = 4
- Can finish at speed 4? Yes (8 hours ≤ 8)
- Try slower: right = 4

Now left=4, right=4 → **Stop**  
**Answer: 4**

## Ceiling Division Explained

**Problem:** For pile `p` and speed `k`, we need `⌈p/k⌉` hours.

**Why not just `p / k`?**
- If we have 7 bananas and eat at speed 4, we get 1.75 hours
- But Koko needs 2 full hours (we round up)!
- We need the ceiling function

**Three Ways to Calculate Ceiling:**

1. **Using a math ceiling function:** Import and use the language's built-in ceiling function (may be slower)

2. **Integer division trick (fast):** Use the formula `(p + k - 1) / k` with integer division

3. **Conditional approach:** Do integer division, then add 1 if there's a remainder

**Why the formula `(p + k - 1) / k` works:**

Examples with p=7, k=4:
- (7+3)/4 = 10/4 = 2 ✓

With p=8, k=4:
- (8+3)/4 = 11/4 = 2 ✓

With p=9, k=4:
- (9+3)/4 = 12/4 = 3 ✓

The general formula for ceiling: `⌈a/b⌉ = (a + b - 1) / b`

## Edge Cases

1. **h equals number of piles:**
   - Must eat at speed of max(piles)
   - Each pile takes exactly 1 hour

2. **h much larger than number of piles:**
   - Can eat very slowly
   - Answer might be 1 or very small

3. **Single pile:**
   - Answer is `⌈pile / h⌉`
   - Or 1 if pile ≤ h

4. **All piles same size:**
   - Symmetric problem
   - Answer is `⌈pile_size / (h / n)⌉`

5. **Very large numbers:**
   - Use integer division to avoid overflow
   - Be careful with sum of hours

## Common Mistakes

1. **Wrong search boundary:**
   - ❌ Setting right boundary to sum of all piles (too large)
   - ✓ Setting right boundary to max(piles) (sufficient)

2. **Wrong loop condition:**
   - ❌ Using `while left <= right` (for finding minimum)
   - ✓ Using `while left < right`

3. **Wrong ceiling division:**
   - ❌ Using regular division which gives float
   - ✓ Using ceiling division with formula `(p + k - 1) / k`

4. **Early return:**
   - ❌ Returning immediately when a valid speed is found
   - ✓ Keep searching for smaller valid speed

5. **Integer overflow:**
   - Be careful with `(p + k - 1)` for large numbers
   - Alternative: use integer division then check remainder

## Optimization: Early Exit

If we find that even at max speed we can't finish (when h is less than the number of piles), it's impossible. However, this scenario is not expected per problem constraints.

## Time and Space Complexity

**Time Complexity:** O(n log m)
- Binary search: O(log m) where m = max(piles)
- Each iteration checks all piles: O(n)
- Total: O(n log m)

**Space Complexity:** O(1)
- Only using constant extra space
- No additional data structures

## Pattern Recognition

This is a **Binary Search on Answer** problem. Characteristics:

1. ✅ Looking for minimum/maximum value
2. ✅ Monotonic property (if k works, k+1 works)
3. ✅ Can verify a candidate in O(n)
4. ✅ Search space is bounded

Other similar problems:
- Capacity To Ship Packages Within D Days
- Split Array Largest Sum
- Minimize Max Distance to Gas Station
- Kth Smallest Element in Sorted Matrix

## Key Takeaways

1. **Binary search isn't just for sorted arrays** - It works on any monotonic function
2. **Search on answer space** - When looking for min/max with verification
3. **Ceiling division trick** - `(a + b - 1) / b` for ceiling
4. **Use `left < right`** - When finding minimum satisfying condition
5. **Verify function is key** - O(n) verification enables O(n log m) solution

This problem beautifully demonstrates how binary search can be applied beyond traditional array searching to optimization problems with monotonic properties!
