
/**
 * 138. Copy List with Random Pointer
 * 
 * A linked list of length n is given such that each node contains an additional random pointer,
 * which could point to any node in the list, or null.
 * 
 * Construct a deep copy of the list.
 * 
 * Difficulty: Medium
 */

import java.util.*;

// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class CopyRandomList {
    /**
     * Create a deep copy of a linked list with random pointers.
     * 
     * Approach: Use a hash map to track old -> new node mappings
     * Recursive implementation with memoization
     * 
     * Time Complexity: O(n) - each node visited once
     * Space Complexity: O(n) - hash map to store node mappings + recursion stack
     */
    public Node copyRandomList(Node head) {
        return copyRandomList(head, new HashMap<>());
    }

    private Node copyRandomList(Node head, Map<Node, Node> cache) {
        if (head == null) {
            return null;
        }

        if (cache.containsKey(head)) {
            return cache.get(head);
        }

        Node copy = new Node(head.val);
        cache.put(head, copy);
        copy.next = copyRandomList(head.next, cache);
        copy.random = cache.containsKey(head.random) ? cache.get(head.random) : null;

        return copy;
    }

    // Helper methods for testing
    private static Node createListWithRandom(int[][] values) {
        if (values == null || values.length == 0) {
            return null;
        }

        // Create all nodes first
        Node[] nodes = new Node[values.length];
        for (int i = 0; i < values.length; i++) {
            nodes[i] = new Node(values[i][0]);
        }

        // Set next pointers
        for (int i = 0; i < nodes.length - 1; i++) {
            nodes[i].next = nodes[i + 1];
        }

        // Set random pointers
        for (int i = 0; i < values.length; i++) {
            if (values[i][1] != -1) {
                nodes[i].random = nodes[values[i][1]];
            }
        }

        return nodes[0];
    }

    private static String listToString(Node head) {
        if (head == null) {
            return "[]";
        }

        // Map nodes to indices
        Map<Node, Integer> nodeToIndex = new HashMap<>();
        Node curr = head;
        int index = 0;
        while (curr != null) {
            nodeToIndex.put(curr, index);
            curr = curr.next;
            index++;
        }

        // Build result string
        StringBuilder sb = new StringBuilder("[");
        curr = head;
        while (curr != null) {
            sb.append("[").append(curr.val).append(",");
            if (curr.random != null) {
                sb.append(nodeToIndex.get(curr.random));
            } else {
                sb.append("null");
            }
            sb.append("]");
            if (curr.next != null) {
                sb.append(",");
            }
            curr = curr.next;
        }
        sb.append("]");
        return sb.toString();
    }

    private static boolean verifyDeepCopy(Node original, Node copied) {
        if (original == null && copied == null) {
            return true;
        }
        if (original == null || copied == null) {
            return false;
        }

        // Check that no nodes are shared
        Set<Node> originalNodes = new HashSet<>();
        Node curr = original;
        while (curr != null) {
            originalNodes.add(curr);
            curr = curr.next;
        }

        curr = copied;
        while (curr != null) {
            if (originalNodes.contains(curr)) {
                return false;
            }
            curr = curr.next;
        }

        return true;
    }

    public static void main(String[] args) {
        CopyRandomList solution = new CopyRandomList();

        // Test case 1: Example 1 - complex random pointers
        // [[7,null],[13,0],[11,4],[10,2],[1,0]]
        Node head1 = createListWithRandom(new int[][] { { 7, -1 }, { 13, 0 }, { 11, 4 }, { 10, 2 }, { 1, 0 } });
        Node result1 = solution.copyRandomList(head1);
        System.out.println("Test 1: " + listToString(result1));
        System.out.println("  Expected: [[7,null],[13,0],[11,4],[10,2],[1,0]]");
        System.out.println("  Deep copy: " + verifyDeepCopy(head1, result1));

        // Test case 2: Example 2 - simple case
        Node head2 = createListWithRandom(new int[][] { { 1, 1 }, { 2, 1 } });
        Node result2 = solution.copyRandomList(head2);
        System.out.println("\nTest 2: " + listToString(result2));
        System.out.println("  Expected: [[1,1],[2,1]]");
        System.out.println("  Deep copy: " + verifyDeepCopy(head2, result2));

        // Test case 3: Example 3 - some null random pointers
        Node head3 = createListWithRandom(new int[][] { { 3, -1 }, { 3, 0 }, { 3, -1 } });
        Node result3 = solution.copyRandomList(head3);
        System.out.println("\nTest 3: " + listToString(result3));
        System.out.println("  Expected: [[3,null],[3,0],[3,null]]");
        System.out.println("  Deep copy: " + verifyDeepCopy(head3, result3));

        // Test case 4: Empty list
        Node head4 = null;
        Node result4 = solution.copyRandomList(head4);
        System.out.println("\nTest 4: " + listToString(result4));
        System.out.println("  Expected: []");

        // Test case 5: Single node
        Node head5 = createListWithRandom(new int[][] { { 1, -1 } });
        Node result5 = solution.copyRandomList(head5);
        System.out.println("\nTest 5: " + listToString(result5));
        System.out.println("  Expected: [[1,null]]");
        System.out.println("  Deep copy: " + verifyDeepCopy(head5, result5));

        // Test case 6: Self-referencing random pointer
        Node head6 = createListWithRandom(new int[][] { { 1, 0 }, { 2, 1 } });
        Node result6 = solution.copyRandomList(head6);
        System.out.println("\nTest 6: " + listToString(result6));
        System.out.println("  Expected: [[1,0],[2,1]]");
        System.out.println("  Deep copy: " + verifyDeepCopy(head6, result6));
    }
}
