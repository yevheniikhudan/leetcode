# Valid Sudoku - Tutorial

## Problem Understanding

Check if a partially filled 9x9 Sudoku board is valid according to three rules:
1. No duplicate digits in any row
2. No duplicate digits in any column
3. No duplicate digits in any 3x3 sub-box

Empty cells are represented by '.', and only need to validate filled cells.

## Key Insights

1. **Hash Sets for Tracking**: Use sets to track seen digits in rows, columns, and sub-boxes.
2. **Sub-box Index Calculation**: For position (i, j), the sub-box index is `(i // 3, j // 3)`.
3. **Single Pass**: Can validate all three rules in one iteration through the board.
4. **Early Exit**: Return false immediately when a duplicate is found.

## Approach

### Method 1: Hash Sets (Optimal)

Use three collections of sets:
- `rows[i]`: Set of digits seen in row i
- `cols[j]`: Set of digits seen in column j
- `boxes[box_index]`: Set of digits seen in each 3x3 box

**Algorithm**:
1. Initialize 9 sets for rows, 9 for columns, 9 for boxes
2. Iterate through each cell (i, j):
   - Skip if cell is '.'
   - Calculate box index: `box_idx = (i // 3) * 3 + (j // 3)`
   - Check if digit is in rows[i], cols[j], or boxes[box_idx]
   - If yes, return False
   - Otherwise, add digit to all three sets
3. Return True if no duplicates found

**Time Complexity**: O(81) = O(1) since board is always 9x9
**Space Complexity**: O(81) = O(1) for the sets

### Method 2: String Encoding

Use a single set with encoded strings to track seen values:
- `"digit in row i"`
- `"digit in col j"`
- `"digit in box (i//3, j//3)"`

**Example**:
For cell (0, 0) with value '5':
- Add: `"5 in row 0"`, `"5 in col 0"`, `"5 in box 0-0"`

## Example Walkthrough

```
Board:
["5","3",".",".","7",".",".",".","."]
["6",".",".","1","9","5",".",".","."]
[".","9","8",".",".",".",".","6","."]
...
```

- (0,0) = '5': Add to row[0], col[0], box[0,0]
- (0,1) = '3': Add to row[0], col[1], box[0,0]
- (0,2) = '.': Skip
- (1,0) = '6': Add to row[1], col[0], box[0,0]
- Continue...

If we encounter '5' again in row 0, col 0, or box (0,0), return False.

## Edge Cases

1. **Empty board**: All cells are '.', should return True
2. **Single row/col/box violation**: Return False immediately
3. **Multiple violations**: Only need to catch the first one
4. **Valid but unsolvable**: Still return True (we only check validity)

## Common Mistakes

1. **Wrong box index calculation**: Must use `(i // 3) * 3 + (j // 3)` or similar
2. **Not skipping '.'**: Must ignore empty cells
3. **Checking solvability**: Problem only asks for validity, not solvability
4. **Using wrong data structure**: Sets are ideal for duplicate detection

## Optimization Tips

1. **Use sets, not lists**: O(1) lookup vs O(n)
2. **Early exit**: Return False as soon as duplicate is found
3. **Pre-allocate structures**: Initialize all sets at the start
4. **String encoding**: Can use single set with encoded keys for cleaner code

## Sub-box Index Formulas

For cell at (row, col):
- **Formula 1**: `box_index = (row // 3) * 3 + (col // 3)`
- **Formula 2**: `box_row = row // 3, box_col = col // 3`

Examples:
- (0,0) → box 0
- (0,5) → box 1
- (4,4) → box 4
- (8,8) → box 8
