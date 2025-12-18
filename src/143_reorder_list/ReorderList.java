/**
 * 143. Reorder List
 * 
 * You are given the head of a singly linked-list. Reorder the list to be in the
 * form:
 * L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 * 
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
 * 
 * Difficulty: Medium
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

class ReorderList {
    /**
     * Reorder list in-place using three-step approach:
     * 1. Find middle
     * 2. Reverse second half
     * 3. Merge two halves
     * 
     * Time Complexity: O(n) - three passes through the list
     * Space Complexity: O(1) - only using pointers
     */
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }

        // Step 1: Find middle using slow and fast pointers
        ListNode slow = head;
        ListNode fast = head.next;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 2: Reverse second half
        ListNode prev = null;
        ListNode curr = slow.next;
        slow.next = null; // Split the list

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Merge two halves
        ListNode first = head;
        ListNode second = prev;

        while (second != null) {
            ListNode next1 = first.next;
            ListNode next2 = second.next;

            first.next = second;
            second.next = next1;

            first = next1;
            second = next2;
        }
    }

    // Helper methods for testing
    private static int[] listToArray(ListNode head) {
        // Count nodes
        int count = 0;
        ListNode curr = head;
        while (curr != null) {
            count++;
            curr = curr.next;
        }

        // Convert to array
        int[] result = new int[count];
        curr = head;
        int i = 0;
        while (curr != null) {
            result[i++] = curr.val;
            curr = curr.next;
        }
        return result;
    }

    private static ListNode arrayToList(int[] arr) {
        if (arr == null || arr.length == 0) {
            return null;
        }
        ListNode head = new ListNode(arr[0]);
        ListNode curr = head;
        for (int i = 1; i < arr.length; i++) {
            curr.next = new ListNode(arr[i]);
            curr = curr.next;
        }
        return head;
    }

    private static String arrayToString(int[] arr) {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i]);
            if (i < arr.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    public static void main(String[] args) {
        ReorderList solution = new ReorderList();

        // Test case 1: Example 1 - even length
        ListNode head1 = arrayToList(new int[] { 1, 2, 3, 4 });
        solution.reorderList(head1);
        System.out.println("Test 1: " + arrayToString(listToArray(head1)) + " (expected: [1, 4, 2, 3])");

        // Test case 2: Example 2 - odd length
        ListNode head2 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        solution.reorderList(head2);
        System.out.println("Test 2: " + arrayToString(listToArray(head2)) + " (expected: [1, 5, 2, 4, 3])");

        // Test case 3: Single node
        ListNode head3 = arrayToList(new int[] { 1 });
        solution.reorderList(head3);
        System.out.println("Test 3: " + arrayToString(listToArray(head3)) + " (expected: [1])");

        // Test case 4: Two nodes
        ListNode head4 = arrayToList(new int[] { 1, 2 });
        solution.reorderList(head4);
        System.out.println("Test 4: " + arrayToString(listToArray(head4)) + " (expected: [1, 2])");

        // Test case 5: Three nodes
        ListNode head5 = arrayToList(new int[] { 1, 2, 3 });
        solution.reorderList(head5);
        System.out.println("Test 5: " + arrayToString(listToArray(head5)) + " (expected: [1, 3, 2])");

        // Test case 6: Six nodes
        ListNode head6 = arrayToList(new int[] { 1, 2, 3, 4, 5, 6 });
        solution.reorderList(head6);
        System.out.println("Test 6: " + arrayToString(listToArray(head6)) + " (expected: [1, 6, 2, 5, 3, 4])");

        // Test case 7: Seven nodes
        ListNode head7 = arrayToList(new int[] { 1, 2, 3, 4, 5, 6, 7 });
        solution.reorderList(head7);
        System.out.println("Test 7: " + arrayToString(listToArray(head7)) + " (expected: [1, 7, 2, 6, 3, 5, 4])");

        // Test case 8: Large even list
        ListNode head8 = arrayToList(new int[] { 1, 2, 3, 4, 5, 6, 7, 8 });
        solution.reorderList(head8);
        System.out.println("Test 8: " + arrayToString(listToArray(head8)) + " (expected: [1, 8, 2, 7, 3, 6, 4, 5])");
    }
}
