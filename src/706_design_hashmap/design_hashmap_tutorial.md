# Design HashMap - Tutorial

## Understanding the Problem
You need to implement a basic hash map from scratch, supporting put, get, and remove operations, without using built-in hash table libraries.

## Visual Example
Suppose you call:
- put(1, 1) → map: [[1,1]]
- put(2, 2) → map: [[1,1], [2,2]]
- get(1) → 1
- put(2, 1) → map: [[1,1], [2,1]]
- get(2) → 1
- remove(2) → map: [[1,1]]
- get(2) → -1

## Approaches
### 1. Separate Chaining (Array of Buckets)
- Use an array of buckets (linked lists or dynamic arrays).
- Hash function: key % N (N = number of buckets, e.g., a prime number > 1000)
- Each bucket stores (key, value) pairs.
- On collision, store multiple pairs in the same bucket.

### 2. Open Addressing (Linear/Quadratic Probing)
- Use a fixed-size array.
- On collision, probe for the next available slot.
- More complex to implement, but saves space.

## Time/Space Complexity
- Average O(1) for put/get/remove if load factor is low.
- Worst O(N) if all keys hash to the same bucket.

## Key Concepts
- Hash function
- Collision handling
- Dynamic resizing (optional for this problem)

## Edge Cases
- Overwriting existing key
- Removing non-existent key
- Large key values

## Optimization Notes
- Use a prime number for bucket size to reduce collisions (e.g., 1009)
- For this problem, resizing is not required due to constraints.

*No code in this tutorial section.*
