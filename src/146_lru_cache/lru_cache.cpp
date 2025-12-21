/**
 * 146. LRU Cache
 *
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *
 * Implement the LRUCache class:
 * - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * - int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * - void put(int key, int value) Update the value of the key if the key exists.
 *   Otherwise, add the key-value pair to the cache. If the number of keys exceeds
 *   the capacity from this operation, evict the least recently used key.
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 * Difficulty: Medium
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
   public:
    /**
     * Initialize the LRU cache with positive size capacity.
     *
     * @param capacity Maximum number of items the cache can hold
     */
    LRUCache(int capacity) : capacity_(capacity) {
        head_ = new Node(0, 0);
        tail_ = new Node(0, 0);
        head_->next = tail_;
        tail_->prev = head_;
    }

    /**
     * Destructor - Clean up all allocated nodes
     */
    ~LRUCache() {
        Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Disable copying (cache shouldn't be copied)
    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;

    /**
     * Return the value of the key if the key exists, otherwise return -1.
     *
     * @param key The key to look up
     * @return The value associated with the key, or -1 if not found
     *
     * Time Complexity: O(1)
     */
    int get(int key) {
        if (cache_.find(key) == cache_.end()) {
            return -1;
        }

        Node* node = cache_[key];
        remove(node);
        add(node);

        return node->value;
    }

    /**
     * Update the value of the key if the key exists. Otherwise, add the key-value
     * pair to the cache. If the number of keys exceeds the capacity from this
     * operation, evict the least recently used key.
     *
     * @param key The key to add or update
     * @param value The value to associate with the key
     *
     * Time Complexity: O(1)
     */
    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            remove(cache_[key]);
        }

        Node* node = new Node(key, value);
        add(node);
        cache_[key] = node;

        if (cache_.size() > capacity_) {
            Node* lru = head_->next;
            remove(lru);
            cache_.erase(lru->key);
            delete lru;  // Free memory!
        }
    }

   private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(Node* node) {
        node->prev = tail_->prev;
        node->next = tail_;
        tail_->prev->next = node;
        tail_->prev = node;
    }

    int capacity_;
    std::unordered_map<int, Node*> cache_;
    Node* head_;
    Node* tail_;
};

void test_lru_cache() {
    // Test case 1: Example from problem
    cout << "Test 1: Basic operations" << endl;
    LRUCache cache(2);

    cache.put(1, 1);
    cout << "After put(1,1)" << endl;

    cache.put(2, 2);
    cout << "After put(2,2)" << endl;

    int result1 = cache.get(1);
    cout << "get(1) = " << result1 << " (expected: 1)" << endl;

    cache.put(3, 3);  // evicts key 2
    cout << "After put(3,3) - should evict key 2" << endl;

    int result2 = cache.get(2);
    cout << "get(2) = " << result2 << " (expected: -1)" << endl;

    cache.put(4, 4);  // evicts key 1
    cout << "After put(4,4) - should evict key 1" << endl;

    int result3 = cache.get(1);
    cout << "get(1) = " << result3 << " (expected: -1)" << endl;

    int result4 = cache.get(3);
    cout << "get(3) = " << result4 << " (expected: 3)" << endl;

    int result5 = cache.get(4);
    cout << "get(4) = " << result5 << " (expected: 4)" << endl;

    cout << endl;

    // Test case 2: Update existing key
    cout << "Test 2: Update existing key" << endl;
    LRUCache cache2(2);
    cache2.put(1, 1);
    cache2.put(2, 2);
    cache2.put(1, 10);  // update key 1
    int result6 = cache2.get(1);
    cout << "get(1) = " << result6 << " (expected: 10)" << endl;

    cout << endl;

    // Test case 3: Capacity 1
    cout << "Test 3: Capacity 1" << endl;
    LRUCache cache3(1);
    cache3.put(1, 1);
    int result7 = cache3.get(1);
    cout << "get(1) = " << result7 << " (expected: 1)" << endl;

    cache3.put(2, 2);  // evicts key 1
    int result8 = cache3.get(1);
    cout << "get(1) = " << result8 << " (expected: -1)" << endl;

    int result9 = cache3.get(2);
    cout << "get(2) = " << result9 << " (expected: 2)" << endl;
}

int main() {
    test_lru_cache();
    return 0;
}
