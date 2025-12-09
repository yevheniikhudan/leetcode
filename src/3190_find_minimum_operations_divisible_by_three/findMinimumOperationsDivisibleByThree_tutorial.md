# Find Minimum Operations to Make All Elements Divisible by Three - Tutorial

## Key Insights
- For each number, check if it's divisible by 3
- If not, determine the minimum operations needed (either +1 or -1)
- The remainder when dividing by 3 tells us the minimum operations needed

## Steps
1. For each number in the array:
   - Calculate `remainder = num % 3`
   - If remainder is 0: no operations needed
   - If remainder is 1: subtract 1 (1 operation)
   - If remainder is 2: add 1 (1 operation, same as subtracting 2)
2. Sum all operations

## Formula
For each number: `min(num % 3, 3 - (num % 3))`
- If `num % 3 == 0`: operations = 0
- If `num % 3 == 1`: operations = 1 (subtract 1)
- If `num % 3 == 2`: operations = 1 (add 1)

## Example
For nums = [1,2,3,4]:
- 1 % 3 = 1 → 1 operation (subtract 1 to get 0)
- 2 % 3 = 2 → 1 operation (add 1 to get 3)
- 3 % 3 = 0 → 0 operations
- 4 % 3 = 1 → 1 operation (subtract 1 to get 3)
- Total: 3 operations

## Implementation
- Time complexity: O(n)
- Space complexity: O(1)

## Edge Cases
- All elements already divisible by 3: return 0
- Single element array: check remainder
