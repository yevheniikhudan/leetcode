import java.util.HashMap;
import java.util.Map;

/**
 * 146. LRU Cache
 * 
 * Design a data structure that follows the constraints of a Least Recently Used
 * (LRU) cache.
 * 
 * Implement the LRUCache class:
 * - LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * - int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * - void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys exceeds
 * the capacity from this operation, evict the least recently used key.
 * 
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * Difficulty: Medium
 */

public class LRUCache {
    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }

    private int capacity;
    private Node left;
    private Node right;
    private Map<Integer, Node> cache;

    /**
     * Initialize the LRU cache with positive size capacity.
     * 
     * @param capacity Maximum number of items the cache can hold
     */
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.cache = new HashMap<>();
        this.left = new Node(0, 0);
        this.right = new Node(0, 0);
        left.next = right;
        right.prev = left;
    }

    /**
     * Return the value of the key if the key exists, otherwise return -1.
     * 
     * @param key The key to look up
     * @return The value associated with the key, or -1 if not found
     * 
     *         Time Complexity: O(1)
     */
    public int get(int key) {
        Node node = this.cache.get(key);

        if (node == null) {
            return -1;
        }

        remove(node);
        add(node);

        return node.value;
    }

    /**
     * Update the value of the key if the key exists. Otherwise, add the key-value
     * pair to the cache. If the number of keys exceeds the capacity from this
     * operation, evict the least recently used key.
     * 
     * @param key   The key to add or update
     * @param value The value to associate with the key
     * 
     *              Time Complexity: O(1)
     */
    public void put(int key, int value) {
        if (this.cache.containsKey(key)) {
            remove(this.cache.get(key));
        }

        Node node = new Node(key, value);
        add(node);
        this.cache.put(key, node);

        if (this.cache.size() > this.capacity) {
            Node lRU = this.left.next;
            remove(lRU);
            this.cache.remove(lRU.key);
        }
    }

    private void add(Node node) {
        node.next = this.right;
        node.prev = this.right.prev;
        this.right.prev.next = node;
        this.right.prev = node;
    }

    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public static void main(String[] args) {
        // Test case 1: Example from problem
        System.out.println("Test 1: Basic operations");
        LRUCache cache = new LRUCache(2);

        cache.put(1, 1);
        System.out.println("After put(1,1)");

        cache.put(2, 2);
        System.out.println("After put(2,2)");

        int result1 = cache.get(1);
        System.out.println("get(1) = " + result1 + " (expected: 1)");

        cache.put(3, 3); // evicts key 2
        System.out.println("After put(3,3) - should evict key 2");

        int result2 = cache.get(2);
        System.out.println("get(2) = " + result2 + " (expected: -1)");

        cache.put(4, 4); // evicts key 1
        System.out.println("After put(4,4) - should evict key 1");

        int result3 = cache.get(1);
        System.out.println("get(1) = " + result3 + " (expected: -1)");

        int result4 = cache.get(3);
        System.out.println("get(3) = " + result4 + " (expected: 3)");

        int result5 = cache.get(4);
        System.out.println("get(4) = " + result5 + " (expected: 4)");

        System.out.println();

        // Test case 2: Update existing key
        System.out.println("Test 2: Update existing key");
        LRUCache cache2 = new LRUCache(2);
        cache2.put(1, 1);
        cache2.put(2, 2);
        cache2.put(1, 10); // update key 1
        int result6 = cache2.get(1);
        System.out.println("get(1) = " + result6 + " (expected: 10)");

        System.out.println();

        // Test case 3: Capacity 1
        System.out.println("Test 3: Capacity 1");
        LRUCache cache3 = new LRUCache(1);
        cache3.put(1, 1);
        int result7 = cache3.get(1);
        System.out.println("get(1) = " + result7 + " (expected: 1)");

        cache3.put(2, 2); // evicts key 1
        int result8 = cache3.get(1);
        System.out.println("get(1) = " + result8 + " (expected: -1)");

        int result9 = cache3.get(2);
        System.out.println("get(2) = " + result9 + " (expected: 2)");
    }
}
