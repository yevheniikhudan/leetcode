/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing 
together the nodes of the first two lists.

Return the head of the merged linked list.

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
     * Merge two sorted linked lists iteratively using dummy node.
     * 
     * @param list1 Head of first sorted linked list
     * @param list2 Head of second sorted linked list
     * @return Head of merged sorted linked list
     * 
     *         Time Complexity: O(n + m) - visit each node once
     *         Space Complexity: O(1) - only use a few pointers
     */
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }

            curr = curr.next;
        }

        curr.next = list1 != null ? list1 : list2;

        return dummy.next;
    }

    /**
     * Merge two sorted linked lists recursively.
     * 
     * @param list1 Head of first sorted linked list
     * @param list2 Head of second sorted linked list
     * @return Head of merged sorted linked list
     * 
     *         Time Complexity: O(n + m) - visit each node once
     *         Space Complexity: O(n + m) - recursive call stack
     */
    public ListNode mergeTwoListsRecursive(ListNode list1, ListNode list2) {
        if (list2 == null) {
            return list1;
        }
        if (list1 == null) {
            return list2;
        }

        if (list1.val < list2.val) {
            list1.next = mergeTwoListsRecursive(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoListsRecursive(list1, list2.next);
            return list2;
        }
    }
}

public class MergeTwoSortedLists {
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

        // Test case 1: Example 1 - regular merge
        ListNode list1_1 = arrayToList(new int[] { 1, 2, 4 });
        ListNode list2_1 = arrayToList(new int[] { 1, 3, 4 });
        ListNode result1 = solution.mergeTwoLists(list1_1, list2_1);
        System.out.print("Test 1 (Iterative): ");
        printArray(listToArray(result1));
        System.out.println(" (expected: [1, 1, 2, 3, 4, 4])");

        // Test case 2: Example 2 - both empty
        ListNode list1_2 = arrayToList(new int[] {});
        ListNode list2_2 = arrayToList(new int[] {});
        ListNode result2 = solution.mergeTwoLists(list1_2, list2_2);
        System.out.print("Test 2 (Iterative): ");
        printArray(listToArray(result2));
        System.out.println(" (expected: [])");

        // Test case 3: Example 3 - one empty
        ListNode list1_3 = arrayToList(new int[] {});
        ListNode list2_3 = arrayToList(new int[] { 0 });
        ListNode result3 = solution.mergeTwoLists(list1_3, list2_3);
        System.out.print("Test 3 (Iterative): ");
        printArray(listToArray(result3));
        System.out.println(" (expected: [0])");

        // Test case 4: First list empty
        ListNode list1_4 = arrayToList(new int[] {});
        ListNode list2_4 = arrayToList(new int[] { 1, 2, 3 });
        ListNode result4 = solution.mergeTwoLists(list1_4, list2_4);
        System.out.print("Test 4 (Iterative): ");
        printArray(listToArray(result4));
        System.out.println(" (expected: [1, 2, 3])");

        // Test case 5: Second list empty
        ListNode list1_5 = arrayToList(new int[] { 1, 2, 3 });
        ListNode list2_5 = arrayToList(new int[] {});
        ListNode result5 = solution.mergeTwoLists(list1_5, list2_5);
        System.out.print("Test 5 (Iterative): ");
        printArray(listToArray(result5));
        System.out.println(" (expected: [1, 2, 3])");

        // Test case 6: No overlap
        ListNode list1_6 = arrayToList(new int[] { 1, 2, 3 });
        ListNode list2_6 = arrayToList(new int[] { 4, 5, 6 });
        ListNode result6 = solution.mergeTwoLists(list1_6, list2_6);
        System.out.print("Test 6 (Iterative): ");
        printArray(listToArray(result6));
        System.out.println(" (expected: [1, 2, 3, 4, 5, 6])");

        // Test case 7: Different lengths
        ListNode list1_7 = arrayToList(new int[] { 1, 3, 5, 7, 9 });
        ListNode list2_7 = arrayToList(new int[] { 2, 4 });
        ListNode result7 = solution.mergeTwoLists(list1_7, list2_7);
        System.out.print("Test 7 (Iterative): ");
        printArray(listToArray(result7));
        System.out.println(" (expected: [1, 2, 3, 4, 5, 7, 9])");

        // Test case 8: All duplicates
        ListNode list1_8 = arrayToList(new int[] { 1, 1, 1 });
        ListNode list2_8 = arrayToList(new int[] { 1, 1 });
        ListNode result8 = solution.mergeTwoLists(list1_8, list2_8);
        System.out.print("Test 8 (Iterative): ");
        printArray(listToArray(result8));
        System.out.println(" (expected: [1, 1, 1, 1, 1])");

        System.out.println("\n--- Recursive Tests ---");

        // Test case 9: Recursive - regular merge
        ListNode list1_9 = arrayToList(new int[] { 1, 2, 4 });
        ListNode list2_9 = arrayToList(new int[] { 1, 3, 4 });
        ListNode result9 = solution.mergeTwoListsRecursive(list1_9, list2_9);
        System.out.print("Test 9 (Recursive): ");
        printArray(listToArray(result9));
        System.out.println(" (expected: [1, 1, 2, 3, 4, 4])");

        // Test case 10: Recursive - both empty
        ListNode list1_10 = arrayToList(new int[] {});
        ListNode list2_10 = arrayToList(new int[] {});
        ListNode result10 = solution.mergeTwoListsRecursive(list1_10, list2_10);
        System.out.print("Test 10 (Recursive): ");
        printArray(listToArray(result10));
        System.out.println(" (expected: [])");

        // Test case 11: Recursive - one empty
        ListNode list1_11 = arrayToList(new int[] {});
        ListNode list2_11 = arrayToList(new int[] { 0 });
        ListNode result11 = solution.mergeTwoListsRecursive(list1_11, list2_11);
        System.out.print("Test 11 (Recursive): ");
        printArray(listToArray(result11));
        System.out.println(" (expected: [0])");

        // Test case 12: Recursive - different lengths
        ListNode list1_12 = arrayToList(new int[] { 1, 3, 5 });
        ListNode list2_12 = arrayToList(new int[] { 2, 4, 6, 8, 10 });
        ListNode result12 = solution.mergeTwoListsRecursive(list1_12, list2_12);
        System.out.print("Test 12 (Recursive): ");
        printArray(listToArray(result12));
        System.out.println(" (expected: [1, 2, 3, 4, 5, 6, 8, 10])");
    }
}
