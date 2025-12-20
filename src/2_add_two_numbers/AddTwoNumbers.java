/**
 * 2. Add Two Numbers
 * 
 * You are given two non-empty linked lists representing two non-negative
 * integers.
 * The digits are stored in reverse order, and each of their nodes contains a
 * single digit.
 * Add the two numbers and return the sum as a linked list.
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

class AddTwoNumbers {
    /**
     * Add two numbers represented as linked lists in reverse order.
     * 
     * Approach:
     * 1. Traverse both lists simultaneously
     * 2. Add corresponding digits plus carry
     * 3. Create new node with sum % 10
     * 4. Update carry as sum / 10
     * 5. Handle remaining carry at the end
     * 
     * Time Complexity: O(max(m, n)) where m, n are lengths of lists
     * Space Complexity: O(max(m, n)) for the result list
     */
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            // Get values from current nodes (0 if null)
            int val1 = (l1 != null) ? l1.val : 0;
            int val2 = (l2 != null) ? l2.val : 0;

            // Calculate sum and carry
            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;

            // Create new node with the digit
            current.next = new ListNode(digit);
            current = current.next;

            // Move to next nodes
            l1 = (l1 != null) ? l1.next : null;
            l2 = (l2 != null) ? l2.next : null;
        }

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
        AddTwoNumbers solution = new AddTwoNumbers();

        // Test case 1: Example 1 - basic addition
        ListNode l1 = arrayToList(new int[] { 2, 4, 3 });
        ListNode l2 = arrayToList(new int[] { 5, 6, 4 });
        ListNode result1 = solution.addTwoNumbers(l1, l2);
        System.out.println("Test 1: " + arrayToString(listToArray(result1)) + " (expected: [7, 0, 8])");

        // Test case 2: Example 2 - both zero
        l1 = arrayToList(new int[] { 0 });
        l2 = arrayToList(new int[] { 0 });
        ListNode result2 = solution.addTwoNumbers(l1, l2);
        System.out.println("Test 2: " + arrayToString(listToArray(result2)) + " (expected: [0])");

        // Test case 3: Example 3 - different lengths with carry
        l1 = arrayToList(new int[] { 9, 9, 9, 9, 9, 9, 9 });
        l2 = arrayToList(new int[] { 9, 9, 9, 9 });
        ListNode result3 = solution.addTwoNumbers(l1, l2);
        System.out.println("Test 3: " + arrayToString(listToArray(result3)) + " (expected: [8, 9, 9, 9, 0, 0, 0, 1])");

        // Test case 4: Single digit with carry
        l1 = arrayToList(new int[] { 5 });
        l2 = arrayToList(new int[] { 5 });
        ListNode result4 = solution.addTwoNumbers(l1, l2);
        System.out.println("Test 4: " + arrayToString(listToArray(result4)) + " (expected: [0, 1])");

        // Test case 5: Different lengths
        l1 = arrayToList(new int[] { 9, 9 });
        l2 = arrayToList(new int[] { 1 });
        ListNode result5 = solution.addTwoNumbers(l1, l2);
        System.out.println("Test 5: " + arrayToString(listToArray(result5)) + " (expected: [0, 0, 1])");

        // Test case 6: No carry
        l1 = arrayToList(new int[] { 1, 2, 3 });
        l2 = arrayToList(new int[] { 4, 5, 6 });
        ListNode result6 = solution.addTwoNumbers(l1, l2);
        System.out.println("Test 6: " + arrayToString(listToArray(result6)) + " (expected: [5, 7, 9])");

        // Test case 7: One list longer
        l1 = arrayToList(new int[] { 1, 8 });
        l2 = arrayToList(new int[] { 0 });
        ListNode result7 = solution.addTwoNumbers(l1, l2);
        System.out.println("Test 7: " + arrayToString(listToArray(result7)) + " (expected: [1, 8])");
    }
}
