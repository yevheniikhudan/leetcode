/**
 * 19. Remove Nth Node From End of List
 * 
 * Given the head of a linked list, remove the nth node from the end of the list
 * and return its head.
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

class RemoveNthFromEnd {
    /**
     * Remove nth node from end using two-pointer technique with dummy node.
     * 
     * Approach:
     * 1. Use dummy node to handle edge case of removing head
     * 2. Use two pointers with n gap between them
     * 3. Move both until fast reaches end
     * 4. Remove the node after slow pointer
     * 
     * Time Complexity: O(L) where L is the length of the list
     * Space Complexity: O(1) - only using pointers
     */
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode slow = dummy;
        ListNode fast = dummy;

        while (n > 0) {
            fast = fast.next;
            n--;
        }

        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        slow.next = slow.next.next;

        return dummy.next;
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
        RemoveNthFromEnd solution = new RemoveNthFromEnd();

        // Test case 1: Remove 2nd from end
        ListNode head1 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result1 = solution.removeNthFromEnd(head1, 2);
        System.out.println("Test 1: " + arrayToString(listToArray(result1)) + " (expected: [1, 2, 3, 5])");

        // Test case 2: Remove only node
        ListNode head2 = arrayToList(new int[] { 1 });
        ListNode result2 = solution.removeNthFromEnd(head2, 1);
        System.out.println("Test 2: " + arrayToString(listToArray(result2)) + " (expected: [])");

        // Test case 3: Remove first of two nodes
        ListNode head3 = arrayToList(new int[] { 1, 2 });
        ListNode result3 = solution.removeNthFromEnd(head3, 1);
        System.out.println("Test 3: " + arrayToString(listToArray(result3)) + " (expected: [1])");

        // Test case 4: Remove last node (head)
        ListNode head4 = arrayToList(new int[] { 1, 2 });
        ListNode result4 = solution.removeNthFromEnd(head4, 2);
        System.out.println("Test 4: " + arrayToString(listToArray(result4)) + " (expected: [2])");

        // Test case 5: Remove from middle
        ListNode head5 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result5 = solution.removeNthFromEnd(head5, 3);
        System.out.println("Test 5: " + arrayToString(listToArray(result5)) + " (expected: [1, 2, 4, 5])");

        // Test case 6: Remove first node (last from end)
        ListNode head6 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result6 = solution.removeNthFromEnd(head6, 5);
        System.out.println("Test 6: " + arrayToString(listToArray(result6)) + " (expected: [2, 3, 4, 5])");

        // Test case 7: Remove last node
        ListNode head7 = arrayToList(new int[] { 1, 2, 3, 4, 5 });
        ListNode result7 = solution.removeNthFromEnd(head7, 1);
        System.out.println("Test 7: " + arrayToString(listToArray(result7)) + " (expected: [1, 2, 3, 4])");
    }
}
