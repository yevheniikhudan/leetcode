# Tutorial: Hand of Straights

## Understanding the Problem

We must partition the multiset of cards into groups of size `groupSize`, each group consisting of consecutive integers. A greedy approach works by always building a group starting from the smallest available card.

## Approaches

### 1. Greedy with Ordered Counts (Recommended)
- Use a sorted map (TreeMap in Java, ordered dict or Counter+sorted keys in Python) counting occurrences of each card value.
- Iterate keys in ascending order. For each key `k` with count `cnt`, try to create `cnt` groups starting from `k` by decreasing counts of `k, k+1, ..., k+groupSize-1` by `cnt` each. If any required card is missing or has insufficient count, return false.

### 2. Sorting and queue
- Sort the hand. Use a queue to track the end values of ongoing groups, or use frequency map along with sorted unique values.

## Complexity
- Sorting: O(n log n) or using TreeMap operations.
- Each number processed once, total O(n log n).

## Edge Cases
- If `hand.length % groupSize != 0`: return false immediately.
- Large gaps or missing consecutive values cause failure.

## Implementation Notes
- Use 64-bit counts if necessary, but here counts fit in int.
- For Python, `collections.Counter` + sorted keys works. For Java, use `TreeMap<Integer,Integer>`.
- Decrement counts carefully and remove zero counts to speed iteration.
