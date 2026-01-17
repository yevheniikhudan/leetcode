# Tutorial: Reverse Words in a String III

## Understanding the Problem
Given a sentence, reverse every word in place, but keep the word order and spaces unchanged.

## Visual Example
- Input: "Let's take LeetCode contest"
- Output: "s'teL ekat edoCteeL tsetnoc"

## Approaches
### 1. Split and Reverse (Most Efficient)
- Split the string by spaces to get words.
- Reverse each word individually.
- Join the reversed words with spaces.
- Time: O(n), Space: O(n)

### 2. In-Place Character Array (If allowed)
- Convert the string to a character array.
- Reverse each word in place by identifying word boundaries.
- Time: O(n), Space: O(n) (O(1) if mutable string is allowed)

## Complexity
- Both approaches: O(n) time, O(n) space.

## Edge Cases
- Empty string: return empty string.
- Multiple spaces: preserve original spacing.

## Optimization Notes
- The split-and-reverse approach is simple and efficient for most languages.
