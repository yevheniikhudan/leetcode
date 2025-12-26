
/**
 * 100. Same Tree
 * 
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    /**
     * Check if two binary trees are the same.
     * 
     * @param p Root of first binary tree
     * @param q Root of second binary tree
     * @return true if trees are identical in structure and values, false otherwise
     */
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null || q == null) {
            return p == q;
        }

        if (p.val != q.val) {
            return false;
        }

        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}

public class SameTree {
    /**
     * Helper function to build a binary tree from an array (level-order).
     */
    private static TreeNode buildTree(Integer[] values) {
        if (values == null || values.length == 0 || values[0] == null) {
            return null;
        }

        TreeNode root = new TreeNode(values[0]);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int i = 1;

        while (!queue.isEmpty() && i < values.length) {
            TreeNode node = queue.poll();

            if (i < values.length && values[i] != null) {
                node.left = new TreeNode(values[i]);
                queue.offer(node.left);
            }
            i++;

            if (i < values.length && values[i] != null) {
                node.right = new TreeNode(values[i]);
                queue.offer(node.right);
            }
            i++;
        }

        return root;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Both trees identical [1,2,3]
        System.out.println("Test 1: Both trees [1,2,3]");
        TreeNode p1 = buildTree(new Integer[] { 1, 2, 3 });
        TreeNode q1 = buildTree(new Integer[] { 1, 2, 3 });
        boolean result1 = solution.isSameTree(p1, q1);
        System.out.println("Result: " + result1 + ", Expected: true");
        assert result1 == true : "Test 1 failed";

        // Test case 2: Different structure [1,2] vs [1,null,2]
        System.out.println("\nTest 2: Different structure [1,2] vs [1,null,2]");
        TreeNode p2 = buildTree(new Integer[] { 1, 2 });
        TreeNode q2 = buildTree(new Integer[] { 1, null, 2 });
        boolean result2 = solution.isSameTree(p2, q2);
        System.out.println("Result: " + result2 + ", Expected: false");
        assert result2 == false : "Test 2 failed";

        // Test case 3: Different values [1,2,1] vs [1,1,2]
        System.out.println("\nTest 3: Different values [1,2,1] vs [1,1,2]");
        TreeNode p3 = buildTree(new Integer[] { 1, 2, 1 });
        TreeNode q3 = buildTree(new Integer[] { 1, 1, 2 });
        boolean result3 = solution.isSameTree(p3, q3);
        System.out.println("Result: " + result3 + ", Expected: false");
        assert result3 == false : "Test 3 failed";

        // Test case 4: Both empty trees
        System.out.println("\nTest 4: Both empty trees");
        TreeNode p4 = null;
        TreeNode q4 = null;
        boolean result4 = solution.isSameTree(p4, q4);
        System.out.println("Result: " + result4 + ", Expected: true");
        assert result4 == true : "Test 4 failed";

        // Test case 5: One empty, one not
        System.out.println("\nTest 5: One empty [1] vs []");
        TreeNode p5 = buildTree(new Integer[] { 1 });
        TreeNode q5 = null;
        boolean result5 = solution.isSameTree(p5, q5);
        System.out.println("Result: " + result5 + ", Expected: false");
        assert result5 == false : "Test 5 failed";

        // Test case 6: Single nodes with same value
        System.out.println("\nTest 6: Single nodes both [1]");
        TreeNode p6 = buildTree(new Integer[] { 1 });
        TreeNode q6 = buildTree(new Integer[] { 1 });
        boolean result6 = solution.isSameTree(p6, q6);
        System.out.println("Result: " + result6 + ", Expected: true");
        assert result6 == true : "Test 6 failed";

        // Test case 7: Single nodes with different values
        System.out.println("\nTest 7: Single nodes [1] vs [2]");
        TreeNode p7 = buildTree(new Integer[] { 1 });
        TreeNode q7 = buildTree(new Integer[] { 2 });
        boolean result7 = solution.isSameTree(p7, q7);
        System.out.println("Result: " + result7 + ", Expected: false");
        assert result7 == false : "Test 7 failed";

        // Test case 8: Larger identical trees
        System.out.println("\nTest 8: Larger identical trees");
        TreeNode p8 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        TreeNode q8 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        boolean result8 = solution.isSameTree(p8, q8);
        System.out.println("Result: " + result8 + ", Expected: true");
        assert result8 == true : "Test 8 failed";

        // Test case 9: Different at leaf level
        System.out.println("\nTest 9: Different at leaf level");
        TreeNode p9 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        TreeNode q9 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 8 });
        boolean result9 = solution.isSameTree(p9, q9);
        System.out.println("Result: " + result9 + ", Expected: false");
        assert result9 == false : "Test 9 failed";

        // Test case 10: Different tree sizes
        System.out.println("\nTest 10: Different tree sizes");
        TreeNode p10 = buildTree(new Integer[] { 1, 2, 3 });
        TreeNode q10 = buildTree(new Integer[] { 1, 2, 3, 4 });
        boolean result10 = solution.isSameTree(p10, q10);
        System.out.println("Result: " + result10 + ", Expected: false");
        assert result10 == false : "Test 10 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
