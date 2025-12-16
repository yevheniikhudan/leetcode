/*
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

Return true if there is a cycle in the linked list. Otherwise, return false.

Difficulty: Easy
*/

import java.util.HashSet;
import java.util.Set;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
    /**
     * Detect cycle in linked list using Floyd's Cycle Detection (Two Pointers).
     * 
     * @param head Head of the linked list
     * @return true if cycle exists, false otherwise
     * 
     *         Time Complexity: O(n) - visit each node at most once
     *         Space Complexity: O(1) - only two pointers
     */
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow.equals(fast)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Detect cycle in linked list using hash set.
     * 
     * @param head Head of the linked list
     * @return true if cycle exists, false otherwise
     * 
     *         Time Complexity: O(n) - visit each node once
     *         Space Complexity: O(n) - store all visited nodes
     */
    public boolean hasCycleHashSet(ListNode head) {
        Set<ListNode> seen = new HashSet<>();

        while (head != null && head.next != null) {
            if (seen.contains(head)) {
                return true;
            }

            seen.add(head);
            head = head.next;
        }

        return false;
    }
}

public class LinkedListCycle {
    // Helper function for testing
    static ListNode createCycleList(int[] values, int pos) {
        if (values.length == 0)
            return null;

        ListNode head = new ListNode(values[0]);
        ListNode curr = head;
        ListNode cycleNode = (pos == 0) ? head : null;

        for (int i = 1; i < values.length; i++) {
            curr.next = new ListNode(values[i]);
            curr = curr.next;
            if (i == pos) {
                cycleNode = curr;
            }
        }

        // Create cycle if pos is valid
        if (pos >= 0 && cycleNode != null) {
            curr.next = cycleNode;
        }

        return head;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1 - cycle at position 1
        ListNode head1 = createCycleList(new int[] { 3, 2, 0, -4 }, 1);
        boolean result1 = solution.hasCycle(head1);
        System.out.println("Test 1 (Two Pointers): " + result1 + " (expected: true)");

        // Test case 2: Example 2 - cycle at position 0
        ListNode head2 = createCycleList(new int[] { 1, 2 }, 0);
        boolean result2 = solution.hasCycle(head2);
        System.out.println("Test 2 (Two Pointers): " + result2 + " (expected: true)");

        // Test case 3: Example 3 - no cycle
        ListNode head3 = createCycleList(new int[] { 1 }, -1);
        boolean result3 = solution.hasCycle(head3);
        System.out.println("Test 3 (Two Pointers): " + result3 + " (expected: false)");

        // Test case 4: Empty list
        ListNode head4 = createCycleList(new int[] {}, -1);
        boolean result4 = solution.hasCycle(head4);
        System.out.println("Test 4 (Two Pointers): " + result4 + " (expected: false)");

        // Test case 5: Two nodes, no cycle
        ListNode head5 = createCycleList(new int[] { 1, 2 }, -1);
        boolean result5 = solution.hasCycle(head5);
        System.out.println("Test 5 (Two Pointers): " + result5 + " (expected: false)");

        // Test case 6: Single node with self-loop
        ListNode head6 = createCycleList(new int[] { 1 }, 0);
        boolean result6 = solution.hasCycle(head6);
        System.out.println("Test 6 (Two Pointers): " + result6 + " (expected: true)");

        // Test case 7: Large cycle
        ListNode head7 = createCycleList(new int[] { 1, 2, 3, 4, 5, 6 }, 2);
        boolean result7 = solution.hasCycle(head7);
        System.out.println("Test 7 (Two Pointers): " + result7 + " (expected: true)");

        // Test case 8: Cycle at end
        ListNode head8 = createCycleList(new int[] { 1, 2, 3, 4 }, 3);
        boolean result8 = solution.hasCycle(head8);
        System.out.println("Test 8 (Two Pointers): " + result8 + " (expected: true)");

        System.out.println("\n--- Hash Set Tests ---");

        // Test case 9: Hash set - cycle exists
        ListNode head9 = createCycleList(new int[] { 3, 2, 0, -4 }, 1);
        boolean result9 = solution.hasCycleHashSet(head9);
        System.out.println("Test 9 (Hash Set): " + result9 + " (expected: true)");

        // Test case 10: Hash set - no cycle
        ListNode head10 = createCycleList(new int[] { 1, 2, 3 }, -1);
        boolean result10 = solution.hasCycleHashSet(head10);
        System.out.println("Test 10 (Hash Set): " + result10 + " (expected: false)");

        // Test case 11: Hash set - empty list
        ListNode head11 = createCycleList(new int[] {}, -1);
        boolean result11 = solution.hasCycleHashSet(head11);
        System.out.println("Test 11 (Hash Set): " + result11 + " (expected: false)");

        // Test case 12: Hash set - single node with cycle
        ListNode head12 = createCycleList(new int[] { 1 }, 0);
        boolean result12 = solution.hasCycleHashSet(head12);
        System.out.println("Test 12 (Hash Set): " + result12 + " (expected: true)");
    }
}
