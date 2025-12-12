# 875. Koko Eating Bananas

## Problem Description

Koko loves to eat bananas. There are `n` piles of bananas, the `i-th` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

## Examples

### Example 1:
```
Input: piles = [3,6,7,11], h = 8
Output: 4
Explanation: 
If k = 4, Koko can eat:
- Hour 1: 3 bananas from pile 1 (finished)
- Hour 2: 4 bananas from pile 2 (2 left)
- Hour 3: 2 bananas from pile 2 (finished)
- Hour 4: 4 bananas from pile 3 (3 left)
- Hour 5: 3 bananas from pile 3 (finished)
- Hour 6: 4 bananas from pile 4 (7 left)
- Hour 7: 4 bananas from pile 4 (3 left)
- Hour 8: 3 bananas from pile 4 (finished)
Total: 8 hours
```

### Example 2:
```
Input: piles = [30,11,23,4,20], h = 5
Output: 30
Explanation: Koko must eat at speed 30 to finish in exactly 5 hours (one pile per hour).
```

### Example 3:
```
Input: piles = [30,11,23,4,20], h = 6
Output: 23
Explanation: At speed 23, Koko can finish in 6 hours.
```

## Constraints

- `1 <= piles.length <= 10^4`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`

## Topics

- Array
- Binary Search

## Difficulty

Medium

## Companies

Amazon, Google, Microsoft, Facebook, Apple, Bloomberg, Uber, Lyft

## Similar Problems

- Minimum Speed to Arrive on Time (Medium)
- Minimized Maximum of Products Distributed to Any Store (Medium)
- Divide Chocolate (Hard)
- Maximum Candies Allocated to K Children (Medium)

## Hints

1. If Koko can finish eating all the bananas at speed `k` within `h` hours, then she can also finish at any speed greater than `k`.
2. Use binary search to find the minimum `k`. What are the search boundaries?
3. For a given speed `k`, how do you calculate the time needed? Think about ceiling division.
