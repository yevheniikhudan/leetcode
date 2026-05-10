# Palindrome Permutation Tutorial

## Understanding the Problem

You do not need to build the palindrome. You only need to decide whether the characters in `s` can be rearranged into one.

A palindrome reads the same forward and backward, so most characters must be paired symmetrically.

## Key Observations

- A character with an even count can be split evenly between the left and right sides.
- A character with an odd count can only appear in the middle.
- Therefore, at most one character may have an odd frequency.
- Since the input contains only lowercase English letters, a fixed-size frequency structure is enough.

## Solving Checklist

- Count or track the parity of each character.
- Count how many characters have odd frequency.
- Return whether the odd-frequency count is at most one.
- Consider both even-length and odd-length strings.

## Edge Cases

- A one-character string is always valid.
- A string where all characters are distinct is valid only when its length is `1`.
- Already-palindromic strings should return `true`.
- The answer depends on character counts, not original order.

## Complexity Targets

Aim for linear time in the length of `s` and constant extra space because there are only 26 lowercase letters.
