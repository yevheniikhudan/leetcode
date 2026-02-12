# Tutorial: Gas Station

## Understanding the Problem

We need to find a starting index on a circular route such that we can travel the entire circuit once without the gas tank going negative. The key observation for a greedy solution is:

- If the total gas is less than total cost, it's impossible to complete the circuit.
- If starting from station `i` leads to running out of gas at station `j`, then any station between `i` and `j` cannot be a valid starting point. We can skip them and set the next candidate start to `j + 1`.

## Approach (Greedy)
- Compute total_tank = sum(gas) - sum(cost). If total_tank < 0: return -1.
- Iterate stations with current_tank starting at 0 and start = 0.
  - current_tank += gas[i] - cost[i]
  - If current_tank < 0: start = i + 1; current_tank = 0
- After loop, return start (total_tank >= 0 ensures validity).

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Multiple zeros, large values, etc. The algorithm handles them.
- Unique solution guaranteed by problem statement.
