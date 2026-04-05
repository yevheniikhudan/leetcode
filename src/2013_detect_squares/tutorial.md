# Detect Squares — Tutorial

Difficulty: Medium

This tutorial explains conceptual approaches to solving LeetCode 2013 "Detect Squares". No code is included — only explanations, strategies, and trade-offs.

## Problem recap

You are given a stream of points in 2D space. For each new point added, you must be able to:
1. Count how many axis-aligned squares have this new point as one of their corners and all four corners are in the stream.

An axis-aligned square has sides parallel to the x and y axes, with equal side length and all angles 90 degrees.

Example:
- If you have points (0,0), (1,0), (0,1), (1,1), they form a square.
- New point (2,0) doesn't complete any new squares with existing points (no matching corner at (2,1)).

## Key insight

For a given point to be a corner of an axis-aligned square, you need three other points that form the remaining corners:
- If the new point is (x, y), the opposite diagonal corner must be (x+d, y+d) or (x-d, y+d) or (x+d, y-d) or (x-d, y-d) for some distance d > 0.
- Once you choose one opposite corner at (x+d, y+d), the other two corners are determined: (x+d, y) and (x, y+d).
- Check if all three other corners exist in the set of previously added points.

## Approaches

1. Hash map / set for fast lookup (recommended)
   - Maintain a frequency map or set of all points seen so far.
   - When a new point (x, y) is added:
     - For each previously seen point (px, py), compute the "vector" from (px, py) to (x, y).
     - Check if this vector forms one side of a square (the vector length is the side length).
     - If the vector is (dx, dy) with |dx| = |dy| (a valid side for axis-aligned square), check if the other two corners exist.
     - Count how many valid squares include (x, y) as a corner.
   - Time: O(n) per query (iterate through all points), Space: O(n) for the map.

2. Brute-force with list (too slow for large streams)
   - Store all points in a list.
   - For each new point, check all O(n²) pairs of previous points to see if they could form a square with the new point.
   - Time: O(n²) per query, Space: O(n).

3. Precomputed squares (not practical for streaming)
   - Precompute all possible squares (not applicable here since the stream is dynamic).

## Conceptual walkthrough

Given new point (x, y) and previously stored points:

1. For each point (px, py) already in the map:
   - Calculate dx = x - px, dy = y - py
   - If |dx| = |dy| = 0, skip (same point).
   - If |dx| = |dy| > 0, this could be one side of a square.
   - The other two corners must be at:
     - (px + dy, py + dx) — perpendicular direction
     - (x + dy, y + dx) — same perpendicular shift
   - Check if both of these points exist in the map.
   - If yes, increment the count.

2. Add the new point to the map (and increment its frequency if duplicates are possible).

## Edge cases
- Duplicate points: if the same point is added multiple times, it might be a corner of the same square counted multiple times (handle based on problem variant).
- Single point or fewer than 4 points: no squares can be formed.
- Points not forming axis-aligned squares: correctly exclude them.
- Very large number of points: ensure the data structure scales; hash map lookup is O(1) average case.

## Complexity analysis
- Time: O(n) per query (where n = number of points added so far).
- Space: O(n) for storing all points in a map/set.

## Key concepts
- Axis-aligned squares: sides parallel to coordinate axes, so sides have length (d, 0), (0, d), (-d, 0), (0, -d) or similar.
- Perpendicular vector: if one side of the square has vector (dx, dy), the adjacent perpendicular side has vector (-dy, dx) or (dy, -dx).
- Frequency map: if points can repeat, use a frequency map to handle counts.

## Common pitfalls
- Confusing the perpendicular direction: the perpendicular to (dx, dy) is (-dy, dx), not (dy, dx).
- Not checking for |dx| = |dy| (axis-aligned constraint).
- Using set when you need frequency counts (if duplicates matter).
- Off-by-one errors or forgetting to count all valid squares.
- Not handling the case where a point appears multiple times in the stream.

## Recommended approach
Hash map to store point frequencies. For each new point, iterate through previously added points and use vector math to identify valid squares. This balances simplicity and efficiency for the streaming context.

(End of tutorial)