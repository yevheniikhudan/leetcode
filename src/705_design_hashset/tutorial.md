# 705. Design HashSet - Tutorial

This problem is about implementing a basic hash set from scratch, without using built-in hash table libraries.

## Approach Outline
1. Use an array of buckets (lists or linked lists) to store values.
2. Use a hash function (e.g., key % bucket_count) to map keys to buckets.
3. For add, remove, and contains, operate only within the appropriate bucket.

## Key Concepts
- Hashing
- Collision handling (chaining or open addressing)
- Array of buckets

## Edge Cases
- Duplicate adds
- Removing non-existent keys
- Large key values

This problem is a good introduction to hash table internals and collision handling.
