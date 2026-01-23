# Tutorial: Calculate Money in LeetCode Bank

## Understanding the Problem
Hercy saves money daily: $1 Monday, +$1 each day. Mondays increase by $1 weekly. Sum after n days.

## Key Concepts
- **Weekly Pattern:** Week 1: 1,2,3,4,5,6,7; Week 2: 2,3,4,5,6,7,8; etc.
- **Math Formula:** Use arithmetic series for full weeks + partial.

## Approaches

### 1. Simulation (Simple)
- Loop n days, track current amount, day of week, week number.
- Accumulate total.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

### 2. Mathematical (Optimal)
- Full weeks: sum = weeks * (sum of week amounts)
- Partial week: sum remaining days.
- Formula: total = (weeks * (start + end) * 7 / 2) + partial sum.

**Time Complexity:** O(1)  
**Space Complexity:** O(1)

## Visual Example
For n=10:
- Week 1: 1 to 7, sum=28
- Week 2: 2,3,4, sum=9
- Total: 37

## Edge Cases
- n=1: 1
- n=7: 28
- n=8: 28+2=30

## Common Pitfalls
- Off-by-one in week calculations.
- Forgetting Monday increment.

## Optimization Notes
- Math is faster for large n, but simulation is fine since n<=1000.
