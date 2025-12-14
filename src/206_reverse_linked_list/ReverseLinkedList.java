/*
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Difficulty: Easy
*/

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

class Solution {
    /**
     * Reverse a singly linked list iteratively.
     * 
     * @param head Head of the linked list
     * @return Head of the reversed linked list
     * 
     *         Time Complexity: O(n) - visit each node once
     *         Space Complexity: O(1) - only use three pointers
     */
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    /**
     * Reverse a singly linked list recursively.
     * 
     * @param head Head of the linked list
     * @return Head of the reversed linked list
     * 
     *         Time Complexity: O(n) - visit each node once
     *         Space Complexity: O(n) - recursive call stack
     */
    public ListNode reverseListRecursive(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHead = reverseListRecursive(head.next);

        head.next.next = head;
        head.next = null;

        return newHead;
    }
}

public class ReverseLinkedList {
    // Helper functions for testing
    static int[] listToArray(ListNode head) {
        int count = 0;
        ListNode curr = head;
        while (curr != null) {
            count++;
            curr = curr.next;
        }

        int[] result = new int[count];
        curr = head;
        int i = 0;
        while (curr != null) {
            result[i++] = curr.val;
            curr = curr.next;
        }
        return result;
    }

    static ListNode arrayToList(int[] arr) {
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

    static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1)
                System.out.print(", ");
        }
        System.out.print("]");
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1 - regular list
        ListNode head1 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result1 = solution.reverseList(head1);
        System.out.print("Test 1 (Iterative): ");
        printArray(listToArray(result1));
        System.out.println(" (expected: [5, 4, 3, 2, 1])");

        // Test case 2: Example 2 - two nodes
        ListNode head2 = arrayToList(new int[] { 1, 2 });
        ListNode result2 = solution.reverseList(head2);
        System.out.print("Test 2 (Iterative): ");
        printArray(listToArray(result2));
        System.out.println(" (expected: [2, 1])");

        // Test case 3: Example 3 - empty list
        ListNode head3 = arrayToList(new int[] {});
        ListNode result3 = solution.reverseList(head3);
        System.out.print("Test 3 (Iterative): ");
        printArray(listToArray(result3));
        System.out.println(" (expected: [])");

        // Test case 4: Single node
        ListNode head4 = arrayToList(new int[] { 1 });
        ListNode result4 = solution.reverseList(head4);
        System.out.print("Test 4 (Iterative): ");
        printArray(listToArray(result4));
        System.out.println(" (expected: [1])");

        // Test case 5: Three nodes
        ListNode head5 = arrayToList(new int[] { 1, 2, 3 });
        ListNode result5 = solution.reverseList(head5);
        System.out.print("Test 5 (Iterative): ");
        printArray(listToArray(result5));
        System.out.println(" (expected: [3, 2, 1])");

        System.out.println("\n--- Recursive Tests ---");

        // Test case 6: Recursive - regular list
        ListNode head6 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result6 = solution.reverseListRecursive(head6);
        System.out.print("Test 6 (Recursive): ");
        printArray(listToArray(result6));
        System.out.println(" (expected: [5, 4, 3, 2, 1])");

        // Test case 7: Recursive - two nodes
        ListNode head7 = arrayToList(new int[] { 1, 2 });
        ListNode result7 = solution.reverseListRecursive(head7);
        System.out.print("Test 7 (Recursive): ");
        printArray(listToArray(result7));
        System.out.println(" (expected: [2, 1])");

        // Test case 8: Recursive - empty list
        ListNode head8 = arrayToList(new int[] {});
        ListNode result8 = solution.reverseListRecursive(head8);
        System.out.print("Test 8 (Recursive): ");
        printArray(listToArray(result8));
        System.out.println(" (expected: [])");

        // Test case 9: Recursive - single node
        ListNode head9 = arrayToList(new int[] { 1 });
        ListNode result9 = solution.reverseListRecursive(head9);
        System.out.print("Test 9 (Recursive): ");
        printArray(listToArray(result9));
        System.out.println(" (expected: [1])");

        // Test case 10: Recursive - three nodes
        ListNode head10 = arrayToList(new int[] { 1, 2, 3 });
        ListNode result10 = solution.reverseListRecursive(head10);
        System.out.print("Test 10 (Recursive): ");
        printArray(listToArray(result10));
        System.out.println(" (expected: [3, 2, 1])");
    }
}
