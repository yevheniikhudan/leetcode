"""
981. Time Based Key-Value Store

Design a time-based key-value data structure that can store multiple values for
the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:
- TimeMap() Initializes the object of the data structure.
- void set(String key, String value, int timestamp) Stores the key with value at timestamp.
- String get(String key, int timestamp) Returns a value such that set was called previously,
  with timestamp_prev <= timestamp. If there are multiple such values, it returns the value
  associated with the largest timestamp_prev. If there are no values, it returns "".
"""

from collections import defaultdict
from typing import List, Tuple


class TimeMap:
    """
    Time-based key-value store using hash map and binary search.
    
    Time Complexity:
    - set: O(1) - append to list
    - get: O(log n) - binary search on timestamps, n = number of timestamps for key
    
    Space Complexity: O(m * n) where m = unique keys, n = average timestamps per key
    """

    def __init__(self):
        """Initialize the data structure."""
        self.store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        """
        Store key-value pair with timestamp.
        
        Args:
            key: The key to store
            value: The value to store
            timestamp: The timestamp (strictly increasing for each key)
        """
        if key not in self.store:
            self.store[key] = []
        self.store[key].append([timestamp, value])
    def get(self, key: str, timestamp: int) -> str:
        """
        Get value at timestamp (or closest earlier timestamp).
        
        Args:
            key: The key to look up
            timestamp: The query timestamp
            
        Returns:
            Value with largest timestamp <= query timestamp, or "" if none exists
        """
        if key not in self.store:
            return ""

        values = self.store[key]
        left, right = 0, len(values) - 1
        result = ""
        
        while (left <= right):
            mid = left + (right - left) // 2
            
            t, v = values[mid]
            if t == timestamp:
                return v
            
            if t <= timestamp:
                result = v
                left = mid + 1
            else:
                right = mid - 1
                
        return result


def test_time_map():
    # Test case 1: Example from problem
    print("Test 1: Example from problem")
    timeMap = TimeMap()
    timeMap.set("foo", "bar", 1)
    print(f"get('foo', 1): {timeMap.get('foo', 1)} (expected: 'bar')")
    print(f"get('foo', 3): {timeMap.get('foo', 3)} (expected: 'bar')")
    timeMap.set("foo", "bar2", 4)
    print(f"get('foo', 4): {timeMap.get('foo', 4)} (expected: 'bar2')")
    print(f"get('foo', 5): {timeMap.get('foo', 5)} (expected: 'bar2')")

    # Test case 2: Key doesn't exist
    print("\nTest 2: Key doesn't exist")
    timeMap2 = TimeMap()
    print(f"get('unknown', 1): '{timeMap2.get('unknown', 1)}' (expected: '')")

    # Test case 3: Query before all timestamps
    print("\nTest 3: Query before all timestamps")
    timeMap3 = TimeMap()
    timeMap3.set("key", "val1", 5)
    timeMap3.set("key", "val2", 10)
    print(f"get('key', 3): '{timeMap3.get('key', 3)}' (expected: '')")

    # Test case 4: Query after all timestamps
    print("\nTest 4: Query after all timestamps")
    timeMap4 = TimeMap()
    timeMap4.set("key", "val1", 5)
    timeMap4.set("key", "val2", 10)
    print(f"get('key', 15): {timeMap4.get('key', 15)} (expected: 'val2')")

    # Test case 5: Query between timestamps
    print("\nTest 5: Query between timestamps")
    timeMap5 = TimeMap()
    timeMap5.set("key", "val1", 1)
    timeMap5.set("key", "val2", 5)
    timeMap5.set("key", "val3", 10)
    print(f"get('key', 7): {timeMap5.get('key', 7)} (expected: 'val2')")
    print(f"get('key', 2): {timeMap5.get('key', 2)} (expected: 'val1')")

    # Test case 6: Multiple keys
    print("\nTest 6: Multiple keys")
    timeMap6 = TimeMap()
    timeMap6.set("key1", "val1", 1)
    timeMap6.set("key2", "val2", 2)
    timeMap6.set("key1", "val3", 3)
    print(f"get('key1', 3): {timeMap6.get('key1', 3)} (expected: 'val3')")
    print(f"get('key2', 3): {timeMap6.get('key2', 3)} (expected: 'val2')")

    # Test case 7: Single timestamp
    print("\nTest 7: Single timestamp")
    timeMap7 = TimeMap()
    timeMap7.set("key", "val", 5)
    print(f"get('key', 5): {timeMap7.get('key', 5)} (expected: 'val')")
    print(f"get('key', 6): {timeMap7.get('key', 6)} (expected: 'val')")
    print(f"get('key', 4): '{timeMap7.get('key', 4)}' (expected: '')")


if __name__ == "__main__":
    test_time_map()
