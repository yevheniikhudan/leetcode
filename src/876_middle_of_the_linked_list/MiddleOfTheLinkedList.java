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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }
}

public class MiddleOfTheLinkedList {
    // Helper to build list from array
    public static ListNode buildList(int[] arr) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        for (int x : arr) {
            curr.next = new ListNode(x);
            curr = curr.next;
        }
        return dummy.next;
    }

    // Helper to convert list to array
    public static int[] listToArray(ListNode head) {
        java.util.List<Integer> res = new java.util.ArrayList<>();
        while (head != null) {
            res.add(head.val);
            head = head.next;
        }
        return res.stream().mapToInt(i -> i).toArray();
    }

    // Test scaffolding
    public static void main(String[] args) {
        int[][] tests = {
                { 1, 2, 3, 4, 5 },
                { 1, 2, 3, 4, 5, 6 },
                { 1 },
                { 1, 2 },
                { 1, 2, 3 }
        };
        int[][] expected = {
                { 3, 4, 5 },
                { 4, 5, 6 },
                { 1 },
                { 2 },
                { 2, 3 }
        };
        Solution sol = new Solution();
        for (int i = 0; i < tests.length; i++) {
            ListNode head = buildList(tests[i]);
            int[] actual = listToArray(sol.middleNode(head));
            System.out.println(java.util.Arrays.toString(actual) + " | " + java.util.Arrays.toString(expected[i]));
        }
    }
}
