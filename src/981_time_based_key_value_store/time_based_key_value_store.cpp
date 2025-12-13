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

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
   public:
    /**
     * Time-based key-value store using hash map and binary search.
     *
     * Time Complexity:
     * - set: O(1) - append to vector
     * - get: O(log n) - binary search on timestamps, n = number of timestamps for key
     *
     * Space Complexity: O(m * n) where m = unique keys, n = average timestamps per key
     */
    TimeMap() {
        // Map automatically initializes
    }

    /**
     * Store key-value pair with timestamp.
     */
    void set(string key, string value, int timestamp) { store[key].push_back({timestamp, value}); }

    /**
     * Get value at timestamp (or closest earlier timestamp).
     */
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        vector<pair<int, string>>& values = store[key];
        int left = 0, right = values.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int t = values[mid].first;
            string v = values[mid].second;

            if (t == timestamp) {
                return v;
            }

            if (t <= timestamp) {
                result = v;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

   private:
    // Map key -> vector of (timestamp, value) pairs
    unordered_map<string, vector<pair<int, string>>> store;
};

void runTests() {
    // Test case 1: Example from problem
    cout << "Test 1: Example from problem\n";
    TimeMap* timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);
    cout << "get('foo', 1): " << timeMap->get("foo", 1) << " (expected: 'bar')\n";
    cout << "get('foo', 3): " << timeMap->get("foo", 3) << " (expected: 'bar')\n";
    timeMap->set("foo", "bar2", 4);
    cout << "get('foo', 4): " << timeMap->get("foo", 4) << " (expected: 'bar2')\n";
    cout << "get('foo', 5): " << timeMap->get("foo", 5) << " (expected: 'bar2')\n";
    delete timeMap;

    // Test case 2: Key doesn't exist
    cout << "\nTest 2: Key doesn't exist\n";
    TimeMap* timeMap2 = new TimeMap();
    cout << "get('unknown', 1): '" << timeMap2->get("unknown", 1) << "' (expected: '')\n";
    delete timeMap2;

    // Test case 3: Query before all timestamps
    cout << "\nTest 3: Query before all timestamps\n";
    TimeMap* timeMap3 = new TimeMap();
    timeMap3->set("key", "val1", 5);
    timeMap3->set("key", "val2", 10);
    cout << "get('key', 3): '" << timeMap3->get("key", 3) << "' (expected: '')\n";
    delete timeMap3;

    // Test case 4: Query after all timestamps
    cout << "\nTest 4: Query after all timestamps\n";
    TimeMap* timeMap4 = new TimeMap();
    timeMap4->set("key", "val1", 5);
    timeMap4->set("key", "val2", 10);
    cout << "get('key', 15): " << timeMap4->get("key", 15) << " (expected: 'val2')\n";
    delete timeMap4;

    // Test case 5: Query between timestamps
    cout << "\nTest 5: Query between timestamps\n";
    TimeMap* timeMap5 = new TimeMap();
    timeMap5->set("key", "val1", 1);
    timeMap5->set("key", "val2", 5);
    timeMap5->set("key", "val3", 10);
    cout << "get('key', 7): " << timeMap5->get("key", 7) << " (expected: 'val2')\n";
    cout << "get('key', 2): " << timeMap5->get("key", 2) << " (expected: 'val1')\n";
    delete timeMap5;

    // Test case 6: Multiple keys
    cout << "\nTest 6: Multiple keys\n";
    TimeMap* timeMap6 = new TimeMap();
    timeMap6->set("key1", "val1", 1);
    timeMap6->set("key2", "val2", 2);
    timeMap6->set("key1", "val3", 3);
    cout << "get('key1', 3): " << timeMap6->get("key1", 3) << " (expected: 'val3')\n";
    cout << "get('key2', 3): " << timeMap6->get("key2", 3) << " (expected: 'val2')\n";
    delete timeMap6;

    // Test case 7: Single timestamp
    cout << "\nTest 7: Single timestamp\n";
    TimeMap* timeMap7 = new TimeMap();
    timeMap7->set("key", "val", 5);
    cout << "get('key', 5): " << timeMap7->get("key", 5) << " (expected: 'val')\n";
    cout << "get('key', 6): " << timeMap7->get("key", 6) << " (expected: 'val')\n";
    cout << "get('key', 4): '" << timeMap7->get("key", 4) << "' (expected: '')\n";
    delete timeMap7;
}

int main() {
    runTests();
    return 0;
}
