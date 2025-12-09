# 20. Valid Parentheses

**Difficulty:** Easy

## Problem Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## Examples

### Example 1:
```
Input: s = "()"
Output: true
```

### Example 2:
```
Input: s = "()[]{}"
Output: true
```

### Example 3:
```
Input: s = "(]"
Output: false
```

### Example 4:
```
Input: s = "([])"
Output: true
```

### Example 5:
```
Input: s = "([)]"
Output: false
```

## Constraints

- `1 <= s.length <= 10^4`
- `s` consists of parentheses only `'()[]{}'`.

## Topics

- String
- Stack

## Hints

1. Use a stack of characters.
2. When you encounter an opening bracket, push it to the top of the stack.
3. When you encounter a closing bracket, check if the top of the stack was the opening for it. If yes, pop it from the stack. Otherwise, return false.

## Companies

Amazon, Google, Microsoft, Facebook, Bloomberg

## Similar Problems

- Generate Parentheses (Medium)
- Longest Valid Parentheses (Hard)
- Remove Invalid Parentheses (Hard)
- Check If Word Is Valid After Substitutions (Medium)
