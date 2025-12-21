"""
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists.
  Otherwise, add the key-value pair to the cache. If the number of keys exceeds
  the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Difficulty: Medium
"""
class Node:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:
    def __init__(self, capacity: int):
        """
        Initialize the LRU cache with positive size capacity.

        Args:
            capacity: Maximum number of items the cache can hold
        """
        self.capacity = capacity
        self.left = Node(0, 0)
        self.right = Node(0, 0)
        self.cache = {}
        self.left.next, self.right.prev = self.right, self.left

    def get(self, key: int) -> int:
        """
        Return the value of the key if the key exists, otherwise return -1.

        Args:
            key: The key to look up

        Returns:
            The value associated with the key, or -1 if not found

        Time Complexity: O(1)
        """
        if key not in self.cache:
            return -1
        
        if key in self.cache:
            self.remove(self.cache[key])
            self.add(self.cache[key])
        
        return self.cache[key].val
        

    def put(self, key: int, value: int) -> None:
        """
        Update the value of the key if the key exists. Otherwise, add the key-value
        pair to the cache. If the number of keys exceeds the capacity from this
        operation, evict the least recently used key.

        Args:
            key: The key to add or update
            value: The value to associate with the key

        Time Complexity: O(1)
        """
        if key in self.cache:
            self.remove(self.cache[key])
            
        node = Node(key, value)
        self.add(node)
        self.cache[key] = node
        
        if len(self.cache) > self.capacity:
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]
            
        
    def add(self, node: Node) -> None:
        prev = self.right.prev
        nxt =  self.right
        prev.next = nxt.prev = node
        node.next, node.prev = nxt, prev
        
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev


def test_lru_cache():
    # Test case 1: Example from problem
    print("Test 1: Basic operations")
    cache = LRUCache(2)

    cache.put(1, 1)
    print(f"After put(1,1)")

    cache.put(2, 2)
    print(f"After put(2,2)")

    result1 = cache.get(1)
    print(f"get(1) = {result1} (expected: 1)")

    cache.put(3, 3)  # evicts key 2
    print(f"After put(3,3) - should evict key 2")

    result2 = cache.get(2)
    print(f"get(2) = {result2} (expected: -1)")

    cache.put(4, 4)  # evicts key 1
    print(f"After put(4,4) - should evict key 1")

    result3 = cache.get(1)
    print(f"get(1) = {result3} (expected: -1)")

    result4 = cache.get(3)
    print(f"get(3) = {result4} (expected: 3)")

    result5 = cache.get(4)
    print(f"get(4) = {result5} (expected: 4)")

    print()

    # Test case 2: Update existing key
    print("Test 2: Update existing key")
    cache2 = LRUCache(2)
    cache2.put(1, 1)
    cache2.put(2, 2)
    cache2.put(1, 10)  # update key 1
    result6 = cache2.get(1)
    print(f"get(1) = {result6} (expected: 10)")

    print()

    # Test case 3: Capacity 1
    print("Test 3: Capacity 1")
    cache3 = LRUCache(1)
    cache3.put(1, 1)
    result7 = cache3.get(1)
    print(f"get(1) = {result7} (expected: 1)")

    cache3.put(2, 2)  # evicts key 1
    result8 = cache3.get(1)
    print(f"get(1) = {result8} (expected: -1)")

    result9 = cache3.get(2)
    print(f"get(2) = {result9} (expected: 2)")


if __name__ == "__main__":
    test_lru_cache()
