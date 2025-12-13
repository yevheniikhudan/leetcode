/*
981. Time Based Key-Value Store

Design a time-based key-value data structure that can store multiple values for
the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:
- TimeMap() Initializes the object of the data structure.
- void set(String key, String value, int timestamp) Stores the key with value at timestamp.
- String get(String key, int timestamp) Returns a value such that set was called previously,
  with timestamp_prev <= timestamp. If there are multiple such values, it returns the value
  associated with the largest timestamp_prev. If there are no values, it returns "".
*/

import java.util.*;

class TimeMap {
    /**
     * Time-based key-value store using hash map and binary search.
     * 
     * Time Complexity:
     * - set: O(1) - append to list
     * - get: O(log n) - binary search on timestamps, n = number of timestamps for
     * key
     * 
     * Space Complexity: O(m * n) where m = unique keys, n = average timestamps per
     * key
     */

    private Map<String, List<Pair>> store;

    // Helper class to store timestamp-value pairs
    private static class Pair {
        int timestamp;
        String value;

        Pair(int timestamp, String value) {
            this.timestamp = timestamp;
            this.value = value;
        }
    }

    public TimeMap() {
        store = new HashMap<>();
    }

    /**
     * Store key-value pair with timestamp.
     */
    public void set(String key, String value, int timestamp) {
        if (!store.containsKey(key)) {
            store.put(key, new ArrayList<>());
        }
        store.get(key).add(new Pair(timestamp, value));
    }

    /**
     * Get value at timestamp (or closest earlier timestamp).
     */
    public String get(String key, int timestamp) {
        if (!store.containsKey(key)) {
            return "";
        }

        List<Pair> values = store.get(key);
        int left = 0, right = values.size() - 1;
        String result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            Pair pair = values.get(mid);

            if (pair.timestamp == timestamp) {
                return pair.value;
            }

            if (pair.timestamp <= timestamp) {
                result = pair.value;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}

public class TimeBasedKeyValueStore {
    public static void main(String[] args) {
        // Test case 1: Example from problem
        System.out.println("Test 1: Example from problem");
        TimeMap timeMap = new TimeMap();
        timeMap.set("foo", "bar", 1);
        System.out.println("get('foo', 1): " + timeMap.get("foo", 1) + " (expected: 'bar')");
        System.out.println("get('foo', 3): " + timeMap.get("foo", 3) + " (expected: 'bar')");
        timeMap.set("foo", "bar2", 4);
        System.out.println("get('foo', 4): " + timeMap.get("foo", 4) + " (expected: 'bar2')");
        System.out.println("get('foo', 5): " + timeMap.get("foo", 5) + " (expected: 'bar2')");

        // Test case 2: Key doesn't exist
        System.out.println("\nTest 2: Key doesn't exist");
        TimeMap timeMap2 = new TimeMap();
        System.out.println("get('unknown', 1): '" + timeMap2.get("unknown", 1) + "' (expected: '')");

        // Test case 3: Query before all timestamps
        System.out.println("\nTest 3: Query before all timestamps");
        TimeMap timeMap3 = new TimeMap();
        timeMap3.set("key", "val1", 5);
        timeMap3.set("key", "val2", 10);
        System.out.println("get('key', 3): '" + timeMap3.get("key", 3) + "' (expected: '')");

        // Test case 4: Query after all timestamps
        System.out.println("\nTest 4: Query after all timestamps");
        TimeMap timeMap4 = new TimeMap();
        timeMap4.set("key", "val1", 5);
        timeMap4.set("key", "val2", 10);
        System.out.println("get('key', 15): " + timeMap4.get("key", 15) + " (expected: 'val2')");

        // Test case 5: Query between timestamps
        System.out.println("\nTest 5: Query between timestamps");
        TimeMap timeMap5 = new TimeMap();
        timeMap5.set("key", "val1", 1);
        timeMap5.set("key", "val2", 5);
        timeMap5.set("key", "val3", 10);
        System.out.println("get('key', 7): " + timeMap5.get("key", 7) + " (expected: 'val2')");
        System.out.println("get('key', 2): " + timeMap5.get("key", 2) + " (expected: 'val1')");

        // Test case 6: Multiple keys
        System.out.println("\nTest 6: Multiple keys");
        TimeMap timeMap6 = new TimeMap();
        timeMap6.set("key1", "val1", 1);
        timeMap6.set("key2", "val2", 2);
        timeMap6.set("key1", "val3", 3);
        System.out.println("get('key1', 3): " + timeMap6.get("key1", 3) + " (expected: 'val3')");
        System.out.println("get('key2', 3): " + timeMap6.get("key2", 3) + " (expected: 'val2')");

        // Test case 7: Single timestamp
        System.out.println("\nTest 7: Single timestamp");
        TimeMap timeMap7 = new TimeMap();
        timeMap7.set("key", "val", 5);
        System.out.println("get('key', 5): " + timeMap7.get("key", 5) + " (expected: 'val')");
        System.out.println("get('key', 6): " + timeMap7.get("key", 6) + " (expected: 'val')");
        System.out.println("get('key', 4): '" + timeMap7.get("key", 4) + "' (expected: '')");
    }
}
