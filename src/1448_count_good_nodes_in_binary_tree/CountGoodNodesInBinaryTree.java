
/**
 * 1448. Count Good Nodes in Binary Tree
 *
 * Given a binary tree root, a node X in the tree is named good if in the path
 * from root to X there are no nodes with a value greater than X.
 *
 * Return the number of good nodes in the binary tree.
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
     * Count the number of good nodes in the binary tree.
     * 
     * A node is "good" if in the path from root to that node,
     * there are no nodes with a value greater than it.
     *
     * @param root The root of the binary tree
     * @return The number of good nodes in the tree
     */
    public int goodNodes(TreeNode root) {
        return countGoodNodes(root, root.val);
    }

    private int countGoodNodes(TreeNode root, int maxVal) {
        if (root == null)
            return 0;

        int count = root.val >= maxVal ? 1 : 0;
        int newMax = Math.max(maxVal, root.val);
        count += countGoodNodes(root.left, newMax);
        count += countGoodNodes(root.right, newMax);

        return count;
    }
}

public class CountGoodNodesInBinaryTree {
    // Helper function to build a binary tree from array (level-order)
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

        // Test case 1: Standard example with mix of good and bad nodes
        System.out.println("Test 1: Tree [3,1,4,3,null,1,5]");
        TreeNode root1 = buildTree(new Integer[] { 3, 1, 4, 3, null, 1, 5 });
        int result1 = solution.goodNodes(root1);
        int expected1 = 4;
        System.out.println("Result: " + result1);
        System.out.println("Expected: " + expected1);
        assert result1 == expected1 : "Test 1 failed";

        // Test case 2: Tree where not all nodes are good
        System.out.println("\nTest 2: Tree [3,3,null,4,2]");
        TreeNode root2 = buildTree(new Integer[] { 3, 3, null, 4, 2 });
        int result2 = solution.goodNodes(root2);
        int expected2 = 3;
        System.out.println("Result: " + result2);
        System.out.println("Expected: " + expected2);
        assert result2 == expected2 : "Test 2 failed";

        // Test case 3: Single node
        System.out.println("\nTest 3: Single node [1]");
        TreeNode root3 = buildTree(new Integer[] { 1 });
        int result3 = solution.goodNodes(root3);
        int expected3 = 1;
        System.out.println("Result: " + result3);
        System.out.println("Expected: " + expected3);
        assert result3 == expected3 : "Test 3 failed";

        // Test case 4: All nodes equal (all should be good)
        System.out.println("\nTest 4: All equal values [2,2,2,2,2]");
        TreeNode root4 = buildTree(new Integer[] { 2, 2, 2, 2, 2 });
        int result4 = solution.goodNodes(root4);
        int expected4 = 5;
        System.out.println("Result: " + result4);
        System.out.println("Expected: " + expected4);
        assert result4 == expected4 : "Test 4 failed";

        // Test case 5: Strictly increasing (all good)
        System.out.println("\nTest 5: Strictly increasing [1,2,3,4,5]");
        TreeNode root5 = buildTree(new Integer[] { 1, 2, 3, 4, 5 });
        int result5 = solution.goodNodes(root5);
        int expected5 = 5;
        System.out.println("Result: " + result5);
        System.out.println("Expected: " + expected5);
        assert result5 == expected5 : "Test 5 failed";

        // Test case 6: Strictly decreasing (only root good)
        System.out.println("\nTest 6: Strictly decreasing [5,4,3,2,1]");
        TreeNode root6 = buildTree(new Integer[] { 5, 4, 3, 2, 1 });
        int result6 = solution.goodNodes(root6);
        int expected6 = 1;
        System.out.println("Result: " + result6);
        System.out.println("Expected: " + expected6);
        assert result6 == expected6 : "Test 6 failed";

        // Test case 7: Negative values
        System.out.println("\nTest 7: With negative values [-1,5,-2,4,null,null,8]");
        TreeNode root7 = buildTree(new Integer[] { -1, 5, -2, 4, null, null, 8 });
        int result7 = solution.goodNodes(root7);
        int expected7 = 3;
        System.out.println("Result: " + result7);
        System.out.println("Expected: " + expected7);
        assert result7 == expected7 : "Test 7 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
