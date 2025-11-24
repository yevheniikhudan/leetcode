# 271 Encode and Decode Strings

**Difficulty**: Medium

## Problem Description

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement `encode` and `decode` methods.

## Examples

### Example 1:
```
Input: ["Hello","World"]
Output: ["Hello","World"]
Explanation:
One possible encode method is: "Hello" + "World" = "HelloWorld"
But this doesn't work because we cannot determine where one word ends and another begins.
We need a delimiter strategy.
```

### Example 2:
```
Input: [""]
Output: [""]
```

### Example 3:
```
Input: []
Output: []
```

### Example 4:
```
Input: ["abc","def","ghi"]
Output: ["abc","def","ghi"]
```

## Constraints

- `0 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` contains any possible characters out of `256` valid ASCII characters.

## Notes

- The string may contain any possible characters out of 256 valid ASCII characters. Your algorithm should be generalized enough to work on any possible characters.
- Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
- Do not rely on any library method such as `eval` or serialize methods. You should implement your own encode/decode algorithm.
- The encoded string should be able to handle edge cases like empty strings, strings with special characters, etc.

## Follow-up

Could you write a generalized algorithm to work on any possible characters?
