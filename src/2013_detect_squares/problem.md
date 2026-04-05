# 2013. Detect Squares

Difficulty: Medium

## Problem

You are given a stream of points on the X-Y plane. Design an object that supports adding new points into a data structure and finding the number of axis-aligned squares that can be formed by any 4 points that have been added so far.

An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular to the axes.

Implement the DetectSquares class:
- `DetectSquares()` Initializes the object with an empty data structure.
- `void add(int[] point)` Adds a new point to the data structure. Duplicate points are allowed.
- `int count(int[] point)` Given a point, returns the number of squares that have the given point as one of their corners.

Note that a point can only be used once in each square.

## Examples

Example 1:
```
Input
["DetectSquares", "add", "add", "add", "add", "add", "count", "count", "add", "count"]
[[], [[4,6]], [[9,6]], [[4,2]], [[9,2]], [[5,4]], [[5,4]], [[0,0]], [[5,1]], [[5,4]]]

Output
[null, null, null, null, null, null, 1, 0, null, 2]

Explanation
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([4, 6]);
detectSquares.add([9, 6]);
detectSquares.add([4, 2]);
detectSquares.add([9, 2]);
detectSquares.add([5, 4]);
detectSquares.count([5, 4]); // return 1, the square [9,6],[4,6],[4,2],[9,2]
detectSquares.count([0, 0]); // return 0
detectSquares.add([5, 1]);
detectSquares.count([5, 4]); // return 2
```

## Constraints

- 1 <= point.length == 2 <= 50
- 0 <= point[i] <= 100
- At most 5000 calls will be made to add and count combined.

## Tags

Hash Table, Design, Geometry

## Related Problems

- 149. Max Points on a Line
- 587. Erect the Fence
- 223. Rectangle Area