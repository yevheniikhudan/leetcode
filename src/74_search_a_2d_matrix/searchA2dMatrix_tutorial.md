# Search a 2D Matrix - Tutorial

## Problem Understanding

Given a 2D matrix with special properties:
1. Each row is sorted in ascending order
2. The first element of each row is greater than the last element of the previous row

This means the entire matrix can be viewed as one continuous sorted array if we "flatten" it row by row.

**Example:**
```
Matrix:
 1   3   5   7
10  11  16  20
23  30  34  60

Flattened (conceptually):
[1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60]
```

We need to search for a target in O(log(m × n)) time.

## Key Insights

### Insight 1: Virtual 1D Array
The matrix properties allow us to treat it as a sorted 1D array **without actually creating it**. We can use index mapping to convert between 2D and 1D indices.

### Insight 2: Binary Search Applies
Since the matrix represents a sorted sequence, we can use binary search on the "virtual" 1D array.

## Approach 1: Two Binary Searches (Two-Step)

### Algorithm:
1. **First binary search:** Find which row the target would be in
2. **Second binary search:** Search within that row

### Step 1: Find the Row
- Binary search on the first column to find the correct row
- The row is where `matrix[row][0] <= target <= matrix[row][n-1]`

### Step 2: Search the Row
- Binary search within that specific row

**Time Complexity:** O(log m) + O(log n) = O(log(m × n))  
**Space Complexity:** O(1)

### Code Pattern:
```
1. Binary search rows by first element
2. If row found, binary search within that row
3. Return result
```

## Approach 2: Single Binary Search (Optimal)

### The Magic: Index Mapping

**Key formulas for m×n matrix:**
- Given 1D index `i` (0 to m×n-1):
  - Row = `i // n` (integer division)
  - Col = `i % n` (modulo)

- Given 2D position `(row, col)`:
  - 1D index = `row * n + col`

### Algorithm:
1. Treat matrix as virtual 1D array with indices 0 to (m × n - 1)
2. Use standard binary search with index mapping
3. For each middle index, convert to (row, col) and access `matrix[row][col]`

### Step-by-Step:
```python
left = 0
right = m * n - 1

while left <= right:
    mid = left + (right - left) // 2
    row = mid // n
    col = mid % n
    value = matrix[row][col]
    
    if value == target:
        return True
    elif value < target:
        left = mid + 1
    else:
        right = mid - 1

return False
```

**Time Complexity:** O(log(m × n))  
**Space Complexity:** O(1)

## Visual Example

**Matrix:** `[[1,3,5,7],[10,11,16,20],[23,30,34,60]]`  
**Target:** 11  
**Dimensions:** m=3, n=4

### Virtual 1D Array Mapping:
```
Index:  0  1  2  3   4  5   6   7   8   9  10  11
Value:  1  3  5  7  10 11  16  20  23  30  34  60
Row:    0  0  0  0   1  1   1   1   2   2   2   2
Col:    0  1  2  3   0  1   2   3   0   1   2   3
```

### Search Process:

**Initial:**
```
left=0, right=11
mid = 5
row = 5 // 4 = 1
col = 5 % 4 = 1
value = matrix[1][1] = 11 ✓ Found!
```

### Another Example - Target: 16

**Step 1:**
```
left=0, right=11
mid = 5
row = 1, col = 1
value = 11 < 16
left = 6
```

**Step 2:**
```
left=6, right=11
mid = 8
row = 2, col = 0
value = 23 > 16
right = 7
```

**Step 3:**
```
left=6, right=7
mid = 6
row = 1, col = 2
value = 16 ✓ Found!
```

## Index Mapping Explained

### Why `row = mid // n`?
- Each row has `n` elements
- Index 0-3 are in row 0
- Index 4-7 are in row 1
- Index 8-11 are in row 2
- Integer division by `n` gives the row number

### Why `col = mid % n`?
- The column position repeats every `n` elements
- Index 0, 4, 8 → column 0
- Index 1, 5, 9 → column 1
- Modulo `n` gives the column within the row

### Visual Aid:
```
For n=4:
Index:   0  1  2  3  4  5  6  7  8  9 10 11
Row:     0  0  0  0  1  1  1  1  2  2  2  2  (index // 4)
Col:     0  1  2  3  0  1  2  3  0  1  2  3  (index % 4)
```

## Edge Cases

1. **Empty matrix:** Not possible per constraints (m, n ≥ 1)
2. **Single element:** Works correctly with binary search
3. **Single row:** Becomes standard binary search
4. **Single column:** Still works with binary search
5. **Target smaller than all elements:** Returns false
6. **Target larger than all elements:** Returns false
7. **Target at corners:**
   - Top-left: matrix[0][0]
   - Top-right: matrix[0][n-1]
   - Bottom-left: matrix[m-1][0]
   - Bottom-right: matrix[m-1][n-1]

## Common Mistakes

1. **Wrong index mapping:**
   - Using `row = mid // m` instead of `mid // n`
   - Confusing row and column calculations

2. **Off-by-one in right boundary:**
   - Using `right = m * n` instead of `m * n - 1`

3. **Not handling empty result:**
   - Forgetting to return false after loop

4. **Integer overflow:**
   - Using `(left + right) / 2` instead of `left + (right - left) / 2`

## Comparison: Two Approaches

| Aspect | Two Binary Searches | Single Binary Search |
|--------|-------------------|---------------------|
| **Complexity** | O(log m + log n) | O(log(m × n)) |
| **Code Length** | Longer | Shorter |
| **Readability** | More intuitive | Less intuitive initially |
| **Performance** | Slightly slower | Optimal |
| **Edge Cases** | More to handle | Fewer edge cases |

## When to Use Each Approach

**Two Binary Searches:**
- Good for understanding the problem
- Easier to explain in interviews
- More intuitive logic

**Single Binary Search:**
- Optimal solution
- Demonstrates advanced understanding
- Preferred for production code

## Key Takeaways

1. **Matrix properties matter:** The special sorting properties allow us to use binary search
2. **Index mapping is powerful:** Converting 2D to 1D and vice versa is a crucial technique
3. **Virtual arrays:** You don't need to create a 1D array; just map indices
4. **Remember the formulas:**
   - `row = index // n`
   - `col = index % n`
5. **Standard binary search applies:** Once you have the mapping, use classic binary search

This problem beautifully combines:
- Binary search fundamentals
- 2D array manipulation
- Index mapping techniques
- Optimization thinking

Master this problem, and you'll be prepared for many matrix and search problems in interviews!
