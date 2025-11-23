# Contains Duplicate - Tutorial

## Key Insights
- Use a hash set to track seen elements
- If an element is already in the set, we found a duplicate
- If we finish the loop without finding duplicates, all elements are unique

## Approaches

### Approach 1: Hash Set (Optimal)
1. Create an empty set
2. For each element in the array:
   - If element is in the set, return true
   - Otherwise, add element to the set
3. Return false if no duplicates found

**Time:** O(n)  
**Space:** O(n)

### Approach 2: Sorting
1. Sort the array
2. Check adjacent elements for duplicates
3. Return true if any adjacent pair is equal

**Time:** O(n log n)  
**Space:** O(1) or O(n) depending on sort implementation

### Approach 3: Brute Force (Not recommended)
Compare every pair of elements.

**Time:** O(n²)  
**Space:** O(1)

## Example
For nums = [1,2,3,1]:
- Add 1 to set: {1}
- Add 2 to set: {1,2}
- Add 3 to set: {1,2,3}
- See 1 again, it's in set → return true

For nums = [1,2,3,4]:
- Add all to set: {1,2,3,4}
- No duplicates → return false

## Implementation
The hash set approach is optimal for this problem.

## Edge Cases
- Single element: always false
- Two elements: check if equal
- All duplicates: return true immediately after second element
