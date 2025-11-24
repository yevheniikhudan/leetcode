# Binary Prefix Divisible By 5 - Tutorial

## Key Insights
- Build the binary number incrementally by processing bits from left to right
- Use the formula: `current = (previous * 2) + current_bit`
- We only need to track divisibility by 5, not the actual number
- Use modulo operation to prevent overflow for large numbers

## Algorithm Steps

### 1. Initialize
- Start with `current = 0`
- Create result array to store boolean answers

### 2. Process Each Bit
For each bit in the array:
- Update current value: `current = (current * 2) + nums[i]`
- Check if divisible by 5: `current % 5 == 0`
- Add result to answer array

### 3. Optimization - Use Modulo
To prevent overflow, we only care about remainder:
- `current = ((current * 2) + nums[i]) % 5`
- This keeps numbers small while preserving divisibility information

## Example Walkthrough

For nums = [0,1,1]:

**Step-by-step:**
- i=0: current = 0, binary="0", decimal=0, divisible by 5? **true** (0 % 5 == 0)
- i=1: current = 0*2+1=1, binary="01", decimal=1, divisible by 5? **false** (1 % 5 != 0)
- i=2: current = 1*2+1=3, binary="011", decimal=3, divisible by 5? **false** (3 % 5 != 0)

Result: [true, false, false]

For nums = [1,1,1]:

**Step-by-step:**
- i=0: current = 1, binary="1", decimal=1, divisible by 5? **false** (1 % 5 != 0)
- i=1: current = 1*2+1=3, binary="11", decimal=3, divisible by 5? **false** (3 % 5 != 0)
- i=2: current = 3*2+1=7, binary="111", decimal=7, divisible by 5? **false** (7 % 5 != 0)

Result: [false, false, false]

## Mathematical Insight

**Binary to Decimal Conversion:**
- "0" = 0
- "01" = 0*2 + 1 = 1
- "011" = 1*2 + 1 = 3
- "0110" = 3*2 + 0 = 6
- "01101" = 6*2 + 1 = 13

**Why Modulo Works:**
- (a * b) mod n = ((a mod n) * b) mod n
- We only need to track current % 5, not the full number
- This prevents integer overflow for large arrays

## Time and Space Complexity
- **Time:** O(n) - single pass through the array
- **Space:** O(n) - for the result array (O(1) if we don't count output)

## Edge Cases
- Single element [0]: return [true]
- Single element [1]: return [false]
- All zeros: all true
- Very long array: modulo prevents overflow
