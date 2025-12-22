
/**
 * 23. Merge k Sorted Lists
 * 
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * Difficulty: Hard
 */

import java.util.*;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class MergeKSortedLists {

    /**
     * Merge k sorted linked lists into one sorted linked list using Min-Heap.
     * 
     * @param lists Array of k linked-lists, each sorted in ascending order
     * @return Head of the merged sorted linked list
     * 
     *         Time Complexity: O(N log k) where N is total nodes, k is number of
     *         lists
     *         Space Complexity: O(k) for the heap
     */
    public ListNode mergeKLists(ListNode[] lists) {
        // Min-heap: compare nodes by their values
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);

        // Add the first node from each list to the heap
        for (ListNode node : lists) {
            if (node != null) {
                minHeap.offer(node);
            }
        }

        // Dummy node to build result list
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        // Process heap until empty
        while (!minHeap.isEmpty()) {
            // Get the smallest node
            ListNode smallest = minHeap.poll();

            // Add to result list
            curr.next = smallest;
            curr = curr.next;

            // If this node has a next node, add it to heap
            if (smallest.next != null) {
                minHeap.offer(smallest.next);
            }
        }

        return dummy.next;
    }

    // Helper methods for testing
    private static List<Integer> listToArray(ListNode head) {
        List<Integer> result = new ArrayList<>();
        ListNode curr = head;
        while (curr != null) {
            result.add(curr.val);
            curr = curr.next;
        }
        return result;
    }

    private static ListNode arrayToList(int[] arr) {
        if (arr.length == 0)
            return null;
        ListNode head = new ListNode(arr[0]);
        ListNode curr = head;
        for (int i = 1; i < arr.length; i++) {
            curr.next = new ListNode(arr[i]);
            curr = curr.next;
        }
        return curr;
    }

    public static void main(String[] args) {
        MergeKSortedLists solution = new MergeKSortedLists();

        // Test case 1: Example 1 - three lists
        ListNode[] lists1 = {
                arrayToList(new int[] { 1, 4, 5 }),
                arrayToList(new int[] { 1, 3, 4 }),
                arrayToList(new int[] { 2, 6 })
        };
        ListNode result1 = solution.mergeKLists(lists1);
        System.out.println("Test 1: " + listToArray(result1) + " (expected: [1, 1, 2, 3, 4, 4, 5, 6])");

        // Test case 2: Example 2 - empty list
        ListNode[] lists2 = {};
        ListNode result2 = solution.mergeKLists(lists2);
        System.out.println("Test 2: " + listToArray(result2) + " (expected: [])");

        // Test case 3: Example 3 - list with empty list
        ListNode[] lists3 = { arrayToList(new int[] {}) };
        ListNode result3 = solution.mergeKLists(lists3);
        System.out.println("Test 3: " + listToArray(result3) + " (expected: [])");

        // Test case 4: Single list
        ListNode[] lists4 = { arrayToList(new int[] { 1, 2, 3 }) };
        ListNode result4 = solution.mergeKLists(lists4);
        System.out.println("Test 4: " + listToArray(result4) + " (expected: [1, 2, 3])");

        // Test case 5: Two lists
        ListNode[] lists5 = {
                arrayToList(new int[] { 1, 3, 5 }),
                arrayToList(new int[] { 2, 4, 6 })
        };
        ListNode result5 = solution.mergeKLists(lists5);
        System.out.println("Test 5: " + listToArray(result5) + " (expected: [1, 2, 3, 4, 5, 6])");

        // Test case 6: Lists with different lengths
        ListNode[] lists6 = {
                arrayToList(new int[] { 1 }),
                arrayToList(new int[] { 1, 3, 4 }),
                arrayToList(new int[] { 2, 6 })
        };
        ListNode result6 = solution.mergeKLists(lists6);
        System.out.println("Test 6: " + listToArray(result6) + " (expected: [1, 1, 2, 3, 4, 6])");

        // Test case 7: Negative values
        ListNode[] lists7 = {
                arrayToList(new int[] { -2, -1, 0 }),
                arrayToList(new int[] { -3, 1, 2 })
        };
        ListNode result7 = solution.mergeKLists(lists7);
        System.out.println("Test 7: " + listToArray(result7) + " (expected: [-3, -2, -1, 0, 1, 2])");
    }
}
