
/**
 * 25. Reverse Nodes in k-Group
 * 
 * Given the head of a linked list, reverse the nodes of the list k at a time, 
 * and return the modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, 
 * should remain as it is.
 * 
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
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

public class ReverseNodesInKGroup {

    /**
     * Reverse the nodes of the list k at a time.
     * 
     * @param head Head of the linked list
     * @param k    Number of nodes to reverse in each group
     * @return Head of the modified list
     * 
     *         Time Complexity: O(n) where n is number of nodes
     *         Space Complexity: O(1) for iterative, O(n/k) for recursive
     */
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode groupPrev = dummy;

        while (true) {
            ListNode kth = findKth(groupPrev, k);

            if (kth == null) {
                return dummy.next;
            }

            ListNode groupNext = kth.next;
            ListNode curr = groupPrev.next;
            reverseGroup(curr, groupNext);

            groupPrev.next = kth;
            groupPrev = curr;
        }
    }

    private void reverseGroup(ListNode curr, ListNode end) {
        ListNode prev = end;

        while (curr != end) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
    }

    private ListNode findKth(ListNode curr, int k) {
        while (curr != null && k > 0) {
            curr = curr.next;
            k -= 1;
        }

        return curr;
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
        return head;
    }

    public static void main(String[] args) {
        ReverseNodesInKGroup solution = new ReverseNodesInKGroup();

        // Test case 1: Example 1 - k=2
        ListNode head1 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result1 = solution.reverseKGroup(head1, 2);
        System.out.println("Test 1: " + listToArray(result1) + " (expected: [2, 1, 4, 3, 5])");

        // Test case 2: Example 2 - k=3
        ListNode head2 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result2 = solution.reverseKGroup(head2, 3);
        System.out.println("Test 2: " + listToArray(result2) + " (expected: [3, 2, 1, 4, 5])");

        // Test case 3: k=1 (no change)
        ListNode head3 = arrayToList(new int[] { 1, 2, 3 });
        ListNode result3 = solution.reverseKGroup(head3, 1);
        System.out.println("Test 3: " + listToArray(result3) + " (expected: [1, 2, 3])");

        // Test case 4: k equals list length
        ListNode head4 = arrayToList(new int[] { 1, 2, 3 });
        ListNode result4 = solution.reverseKGroup(head4, 3);
        System.out.println("Test 4: " + listToArray(result4) + " (expected: [3, 2, 1])");

        // Test case 5: Single node
        ListNode head5 = arrayToList(new int[] { 1 });
        ListNode result5 = solution.reverseKGroup(head5, 1);
        System.out.println("Test 5: " + listToArray(result5) + " (expected: [1])");

        // Test case 6: Two nodes, k=2
        ListNode head6 = arrayToList(new int[] { 1, 2 });
        ListNode result6 = solution.reverseKGroup(head6, 2);
        System.out.println("Test 6: " + listToArray(result6) + " (expected: [2, 1])");

        // Test case 7: Exact multiple of k
        ListNode head7 = arrayToList(new int[] { 1, 2, 3, 4, 5, 6 });
        ListNode result7 = solution.reverseKGroup(head7, 3);
        System.out.println("Test 7: " + listToArray(result7) + " (expected: [3, 2, 1, 6, 5, 4])");

        // Test case 8: Large k
        ListNode head8 = arrayToList(new int[] { 1, 2, 3 });
        ListNode result8 = solution.reverseKGroup(head8, 10);
        System.out.println("Test 8: " + listToArray(result8) + " (expected: [1, 2, 3])");
    }
}
