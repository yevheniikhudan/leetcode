# Tutorial: Count of Matches in Tournament

## Understanding the Problem
Simulate a tournament with n teams. Each round, matches reduce teams until 1 winner. Count total matches played.

## Key Concepts
- **Simulation:** Loop until 1 team left, adding matches per round.
- **Math Insight:** Each match eliminates 1 team; total matches = n - 1.

## Approaches

### 1. Simulation (Straightforward)
- While teams > 1, if even, matches = teams/2, teams = teams/2; else matches = (teams-1)/2, teams = (teams-1)/2 +1.
- Accumulate matches.

**Time Complexity:** O(log n)  
**Space Complexity:** O(1)

### 2. Mathematical (Optimal)
- Total matches = n - 1, since each match reduces teams by 1.

**Time Complexity:** O(1)  
**Space Complexity:** O(1)

## Visual Example
For n=7:
- Round 1: 7 teams, odd, matches=3, advance=4
- Round 2: 4 teams, even, matches=2, advance=2
- Round 3: 2 teams, even, matches=1, advance=1
- Total: 6 = 7-1

## Edge Cases
- n=1: 0 matches
- n=2: 1 match
- Large n: Still O(1) with math

## Common Pitfalls
- Off-by-one in odd case.
- Forgetting to accumulate.

## Optimization Notes
- Use math for instant answer.
