# Top K Frequent Elements - Tutorial

## Key Insights
- Count frequency of each element using a hash map
- Find the k elements with highest frequencies
- Multiple approaches with different time complexities

## Approaches

### Approach 1: Hash Map + Sorting
1. Count frequencies using a hash map
2. Sort elements by frequency (descending)
3. Return the first k elements

**Time:** O(n log n) - dominated by sorting  
**Space:** O(n) for the hash map

### Approach 2: Hash Map + Heap (Min Heap)
1. Count frequencies using a hash map
2. Use a min heap of size k
3. For each element, if heap size < k, add it
4. Otherwise, if current frequency > min frequency in heap, replace
5. Return all elements in the heap

**Time:** O(n log k) - better than sorting for small k  
**Space:** O(n) for hash map + O(k) for heap

### Approach 3: Bucket Sort (Optimal)
1. Count frequencies using a hash map
2. Create buckets where bucket[i] contains elements with frequency i
3. Iterate from highest frequency to lowest, collecting k elements

**Time:** O(n) - meets the follow-up requirement  
**Space:** O(n) for hash map and buckets

**Example:**
For nums = [1,1,1,2,2,3], k = 2:
- Frequencies: {1:3, 2:2, 3:1}
- Buckets: [[], [3], [2], [1], [], [], []]
- From highest to lowest: 1 (freq 3), 2 (freq 2)
- Result: [1, 2]

### Approach 4: Quickselect
1. Count frequencies using a hash map
2. Use quickselect to find the k-th most frequent element
3. Return all elements with frequency >= k-th frequency

**Time:** O(n) average, O(n²) worst case  
**Space:** O(n) for hash map

## Which Approach to Use?
- **Bucket Sort:** Best overall (O(n) time, simple to implement)
- **Min Heap:** Good for small k values
- **Sorting:** Simplest to code, acceptable for most cases
- **Quickselect:** Advanced, not usually needed

## Edge Cases
- All elements have same frequency: return any k elements
- k equals number of unique elements: return all elements
- Single element: return that element
