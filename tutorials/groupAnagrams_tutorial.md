# Group Anagrams - Tutorial

## Key Insights
- Anagrams have the same characters with the same frequencies
- Use a hash map where the key represents the anagram pattern
- Group strings with the same key together

## Approaches

### Approach 1: Sorting as Key (Common)
1. For each string, sort its characters
2. Use the sorted string as the key in a hash map
3. Group strings with the same sorted key together
4. Return all groups

**Time:** O(n * k log k) where n = number of strings, k = max length of string  
**Space:** O(n * k) for the hash map

**Example:**
- "eat" → sorted: "aet" → key: "aet"
- "tea" → sorted: "aet" → key: "aet"
- "tan" → sorted: "ant" → key: "ant"

### Approach 2: Character Count as Key (Optimal)
1. For each string, count character frequencies
2. Use the count array/tuple as the key (e.g., (1,0,0,1,1,0,...))
3. Group strings with the same count key together
4. Return all groups

**Time:** O(n * k) where n = number of strings, k = max length of string  
**Space:** O(n * k) for the hash map

**Example:**
- "eat" → count: [1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0]
- "tea" → count: [1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0]

## Edge Cases
- Empty string: group as its own anagram
- Single character: each unique character is its own group
- All same characters: all in one group
- No anagrams: each string in its own group

## Which Approach to Use?
- **Sorting:** Simpler to implement, works well for most cases
- **Character Count:** Slightly faster for very long strings, but more complex
