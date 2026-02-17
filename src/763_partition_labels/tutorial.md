Understanding the problem

Given a string S of lowercase letters, partition it into as many contiguous parts as possible such that each letter appears in at most one part. Return the list of sizes of these parts.

In other words, once you cut the string into parts, no letter that appears in one part may appear again in another part. The goal is to maximize the number of parts (equivalently, make the parts as small as possible while maintaining the constraint).

Visual example

S = "ababcbacadefegdehijhklij"

- If you look at the last occurrence of each letter, you can see when a partition must at least extend to include all occurrences of letters seen so far.
- Starting from the left, track the farthest index where any letter seen so far appears. When the current index reaches that farthest index, you can close a partition there.

Illustration (indices):
- a: last at 8
- b: last at 5
- c: last at 7
- ...
Starting at index 0, you see letters whose last occurrences push the partition end forward; when the running end equals the current index, you form a partition.

Key idea (greedy):

A correct greedy strategy is:
- Precompute the last index of each character in the string.
- Iterate through the string maintaining a current partition "end" that is the maximum last index of all characters seen in the current partition.
- When the current index reaches "end", you can finalize a partition and start a new one.

This works because whenever you see a character, all of its remaining occurrences are located at or before its last index — so you must include up to that last index in the current partition. Extending the partition to the maximum of last indices of seen letters guarantees that no letter will later appear outside the partition.

Multiple approaches (from most efficient)

1) Greedy using last occurrence map (optimal)
- Precompute last occurrence index for each character (O(1) per character type, e.g., 26 letters).
- Single pass through S maintaining a running end = max(end, last_index[char]). When i == end, cut a partition of size (end - start + 1) and move start = i+1.
- Time complexity: O(n) where n = len(S).
- Space complexity: O(1) extra (array/map of size at most 26) plus output list.

2) Interval-merging viewpoint
- Consider each letter as defining an interval [first_index, last_index]. The problem becomes partitioning the line into disjoint merged intervals where intervals that overlap must be merged.
- Build intervals for letters that appear, sort by start (or use 26 fixed buckets and then scan in order), then merge overlapping intervals. The merged interval sizes are the answer.
- Time complexity: O(n + k log k) where k ≤ 26 (number of distinct letters); effectively O(n).
- Space complexity: O(k) for intervals (k ≤ 26).

3) Brute-force / checking feasibility (not recommended)
- Try all cut positions greedily or via checking sets for each segment whether letters reappear later; this is inefficient and unnecessary given the simple greedy method.

Time and space complexity summary

- Optimal greedy: Time O(n), Space O(1) extra (alphabet-sized map) + O(p) output, where p is number of partitions.
- Interval merging: Time O(n + k log k) with k ≤ 26, Space O(k).

Key concepts and patterns

- Greedy: At any point, you must extend the current partition at least to the last occurrence of any letter included in it. Choosing the maximum of those last occurrences is the locally optimal choice that leads to a globally optimal partitioning.
- Interval merging: Letters define intervals; the answer is the list of merged disjoint intervals.
- Use of character last-occurrence maps: Precomputing last indices allows single-pass solutions.

Edge cases and pitfalls

- Single-character string: S="a" -> [1].
- All characters distinct: each character can be its own partition -> [1,1,1,...].
- All characters identical: single partition of full length -> [n].
- Repeated characters spread across the string: must ensure partitions extend to include their last occurrences.
- Non-lowercase input: problem states lowercase only; if not guaranteed, handle or normalize input appropriately.

Optimization notes

- Alphabet bound: Because S uses lowercase English letters only, the last-occurrence structure is fixed-size (26), making the space usage constant.
- No need to store first occurrences when using the greedy-by-last-index method; only last indices and running pointers are required.
- When implementing with intervals, avoid unnecessary sorting if you iterate letters in alphabet order (constant overhead) or process while scanning the string.

Common implementation checklist

- Compute last index for each letter.
- Iterate and update running end = max(end, last_index[char]).
- When i == end, append partition length and move start.
- Return the list of partition lengths.

Further reading

- Greedy algorithms for interval partitioning and merging
- Related problems: merging intervals, minimizing number of subsegments with constraints
