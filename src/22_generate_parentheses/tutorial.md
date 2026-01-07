# Tutorial: Generate Parentheses (LeetCode 22)

## Key Concepts
- Backtracking for combinatorial generation
- Validity constraints for parentheses: number of '(' must not exceed n, number of ')' must not exceed number of '('
- Pruning invalid branches early

## Approach Outline
- Use backtracking to build strings by adding '(' or ')' at each step
- Only add '(' if count is less than n
- Only add ')' if count is less than number of '('
- When the string reaches length 2*n, add to result

(No code in this tutorial per workspace conventions)
