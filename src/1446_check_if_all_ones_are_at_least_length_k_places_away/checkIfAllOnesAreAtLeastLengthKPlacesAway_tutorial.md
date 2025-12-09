# Check If All 1's Are at Least Length K Places Away - Tutorial

## Key Insights
- Track the index of the previous `1`.
- For each new `1`, check if the gap from the previous `1` is at least `k`.
- If not, return `false`. Otherwise, continue.

## Steps
1. Initialize `prev` to -k-1 (so the first `1` always passes).
2. Iterate through `nums`:
   - If `nums[i] == 1`:
     - If `i - prev <= k`, return `false`.
     - Update `prev = i`.
3. Return `true` if no violations found.

## Implementation
- Time complexity: O(n)
- Space complexity: O(1)

## Edge Cases
- Only one `1`: always true
- k = 0: always true
