# Time Based Key-Value Store - Tutorial

## Problem Understanding

Design a data structure that:
1. Stores **multiple values** for the same key at **different timestamps**
2. Retrieves the value at a specific timestamp (or the closest earlier one)

**Key Requirements:**
- Store: `set(key, value, timestamp)`
- Retrieve: `get(key, timestamp)` → return value with largest timestamp ≤ query
- Timestamps are **strictly increasing** for each key
- If no valid value exists, return empty string

**Example Timeline for key "foo":**
```
Time:  1         2    3         4         5
Value: "bar"     -    -         "bar2"    -

get("foo", 1) → "bar"   (exact match)
get("foo", 3) → "bar"   (latest before 3)
get("foo", 4) → "bar2"  (exact match)
get("foo", 5) → "bar2"  (latest before 5)
```

## Key Insights

### Insight 1: Hash Map + List Structure

Store data as: `Map<String, List<Pair<Integer, String>>>`
- **Key** → maps to a list of (timestamp, value) pairs
- **List** is naturally sorted (timestamps are strictly increasing)

### Insight 2: Binary Search on Timestamps

Since timestamps are sorted, `get` operation becomes:
- Find the **rightmost** timestamp ≤ query timestamp
- This is a classic binary search problem!

### Insight 3: Two Operations with Different Complexities

**Set Operation:** O(1)
- Just append to the list for that key
- No sorting needed (already increasing)

**Get Operation:** O(log n)
- Binary search through timestamps for that key
- n = number of timestamps for that key

## Data Structure Design

### Storage Structure:

For each key, maintain a list of (timestamp, value) pairs:
- Key: string
- Value: list of pairs sorted by timestamp

**Example:**
```
map = {
    "foo": [(1, "bar"), (4, "bar2"), (7, "bar3")],
    "baz": [(2, "val1"), (5, "val2")]
}
```

### Why This Works:

1. **Hash Map** provides O(1) key lookup
2. **List** stores all historical values
3. **Sorted by timestamp** enables binary search
4. **Strictly increasing** timestamps guarantee no sorting needed

## Algorithm: Get Operation

**Goal:** Find largest timestamp ≤ query timestamp

**Binary Search Approach:**

1. Look up key in hash map
2. If key doesn't exist, return ""
3. Binary search on the timestamp list:
   - Looking for rightmost timestamp ≤ query
   - If found, return corresponding value
   - If no valid timestamp, return ""

**Binary Search Pattern:**
- Find the **largest element ≤ target**
- Keep track of the best valid answer
- When timestamp ≤ query, it's valid → save and search right for better
- When timestamp > query, search left

## Step-by-Step Example

**Operations:**
```
set("foo", "bar", 1)
set("foo", "bar2", 4)
get("foo", 3)
get("foo", 4)
get("foo", 5)
```

### After set operations:
```
map = {
    "foo": [(1, "bar"), (4, "bar2")]
}
```

### Get("foo", 3):

**Binary Search on [(1, "bar"), (4, "bar2")]**

Initial: left=0, right=1
- mid=0, timestamp=1
- 1 ≤ 3? Yes → valid answer "bar"
- Search right: left=1

Next: left=1, right=1
- mid=1, timestamp=4
- 4 ≤ 3? No → invalid
- Search left: right=0

Stop: left=1, right=0 (left > right)
**Answer: "bar"** (last valid)

### Get("foo", 4):

Binary Search:
- mid=0, timestamp=1 ≤ 4 → valid "bar", search right
- mid=1, timestamp=4 ≤ 4 → valid "bar2", search right
- Stop

**Answer: "bar2"**

### Get("foo", 5):

Binary Search:
- mid=0, timestamp=1 ≤ 5 → valid "bar", search right
- mid=1, timestamp=4 ≤ 5 → valid "bar2", search right
- Stop

**Answer: "bar2"**

## Implementation Approaches

### Approach 1: Linear Search (Simple but Slow)

For get operation:
1. Look up key
2. Iterate backwards through list
3. Return first timestamp ≤ query

**Time:** O(n) for get
**Good for:** Small number of timestamps per key

### Approach 2: Binary Search (Optimal)

For get operation:
1. Look up key
2. Binary search for largest timestamp ≤ query
3. Return corresponding value

**Time:** O(log n) for get
**Good for:** Large number of timestamps per key

## Edge Cases

1. **Key doesn't exist:**
   - get("unknown", 1) → ""

2. **Query timestamp before all stored timestamps:**
   - Stored: [(5, "a"), (10, "b")]
   - get(key, 3) → ""

3. **Query timestamp after all stored timestamps:**
   - Stored: [(5, "a"), (10, "b")]
   - get(key, 15) → "b" (latest value)

4. **Exact timestamp match:**
   - Stored: [(5, "a")]
   - get(key, 5) → "a"

5. **Multiple values, query between timestamps:**
   - Stored: [(1, "a"), (5, "b"), (10, "c")]
   - get(key, 7) → "b"

6. **Single timestamp:**
   - Stored: [(5, "a")]
   - get(key, 5) → "a"
   - get(key, 6) → "a"
   - get(key, 4) → ""

## Common Mistakes

1. **Using wrong binary search pattern:**
   - ❌ Looking for exact match only
   - ✓ Looking for largest ≤ target

2. **Not handling empty result:**
   - ❌ Returning null or throwing exception
   - ✓ Returning empty string ""

3. **Trying to sort timestamps:**
   - ❌ Sorting on every get
   - ✓ Using the fact that timestamps are already increasing

4. **Not using binary search:**
   - ❌ Linear search: O(n)
   - ✓ Binary search: O(log n)

5. **Wrong boundary conditions:**
   - ❌ Missing the case when all timestamps > query
   - ✓ Properly initializing result to ""

## Time and Space Complexity

**Set Operation:**
- Time: O(1) - just append to list
- Space: O(1) per operation

**Get Operation:**
- Time: O(log n) - binary search, where n = timestamps for that key
- Space: O(1) - no extra space

**Overall Space:**
- O(m * n) where m = number of unique keys, n = timestamps per key

## Pattern Recognition

This problem combines multiple patterns:

1. **Hash Map** - for O(1) key lookup
2. **Binary Search** - for O(log n) timestamp lookup
3. **Design** - creating an efficient data structure
4. **Time-based queries** - finding value at specific time

**Similar Problems:**
- Design HashMap
- LRU Cache
- Stock Price Fluctuation
- Snapshot Array

## Key Takeaways

1. **Leverage constraints** - strictly increasing timestamps mean no sorting needed
2. **Combine data structures** - hash map + sorted list is powerful
3. **Binary search on time** - common pattern for time-based queries
4. **Set is O(1), Get is O(log n)** - good trade-off for this use case
5. **Find largest ≤ target** - important binary search variant

This problem beautifully demonstrates how to design an efficient data structure by combining multiple techniques: hash maps for fast lookup and binary search for efficient querying of sorted data!
