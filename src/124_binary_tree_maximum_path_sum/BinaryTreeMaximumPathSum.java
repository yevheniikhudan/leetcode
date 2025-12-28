
/**
 * 124. Binary Tree Maximum Path Sum
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
 * in the sequence has an edge connecting them. A node can only appear in the sequence
 * at most once. Note that the path does not need to pass through the root.
 *
 * The path sum of a path is the sum of the node's values in the path.
 *
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
    int maxSum;

    /**
     * Find the maximum path sum in a binary tree.
     *
     * @param root Root of the binary tree
     * @return Maximum path sum of any non-empty path
     */
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;

        dfs(root);

        return maxSum;
    }

    private int dfs(TreeNode root) {
        if (root == null)
            return 0;

        int currentSum = root.val;
        int leftSum = Math.max(dfs(root.left), 0);
        int rightSum = Math.max(dfs(root.right), 0);

        currentSum += Math.max(leftSum, rightSum);

        maxSum = Math.max(maxSum, root.val + leftSum + rightSum);

        return currentSum;
    }
}

public class BinaryTreeMaximumPathSum {
    // Helper function to build tree from level-order array
    private static TreeNode buildTree(Integer[] values) {
        if (values == null || values.length == 0) {
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

        // Test case 1: Simple tree
        System.out.println("Test 1: root = [1,2,3]");
        TreeNode root1 = buildTree(new Integer[] { 1, 2, 3 });
        int result1 = solution.maxPathSum(root1);
        int expected1 = 6;
        System.out.println("Result: " + result1);
        System.out.println("Expected: " + expected1);
        if (result1 != expected1) {
            throw new AssertionError("Test 1 failed");
        }

        // Test case 2: Tree with negative root
        System.out.println("\nTest 2: root = [-10,9,20,null,null,15,7]");
        TreeNode root2 = buildTree(new Integer[] { -10, 9, 20, null, null, 15, 7 });
        int result2 = solution.maxPathSum(root2);
        int expected2 = 42;
        System.out.println("Result: " + result2);
        System.out.println("Expected: " + expected2);
        if (result2 != expected2) {
            throw new AssertionError("Test 2 failed");
        }

        // Test case 3: Single node
        System.out.println("\nTest 3: root = [-3]");
        TreeNode root3 = buildTree(new Integer[] { -3 });
        int result3 = solution.maxPathSum(root3);
        int expected3 = -3;
        System.out.println("Result: " + result3);
        System.out.println("Expected: " + expected3);
        if (result3 != expected3) {
            throw new AssertionError("Test 3 failed");
        }

        // Test case 4: All negative values
        System.out.println("\nTest 4: root = [-2,-1]");
        TreeNode root4 = buildTree(new Integer[] { -2, -1 });
        int result4 = solution.maxPathSum(root4);
        int expected4 = -1;
        System.out.println("Result: " + result4);
        System.out.println("Expected: " + expected4);
        if (result4 != expected4) {
            throw new AssertionError("Test 4 failed");
        }

        // Test case 5: Path doesn't include root
        System.out.println("\nTest 5: root = [2,-1,-2]");
        TreeNode root5 = buildTree(new Integer[] { 2, -1, -2 });
        int result5 = solution.maxPathSum(root5);
        int expected5 = 2;
        System.out.println("Result: " + result5);
        System.out.println("Expected: " + expected5);
        if (result5 != expected5) {
            throw new AssertionError("Test 5 failed");
        }

        // Test case 6: Left skewed tree
        System.out.println("\nTest 6: root = [5,4,null,3,null,2,null,1]");
        TreeNode root6 = buildTree(new Integer[] { 5, 4, null, 3, null, 2, null, 1 });
        int result6 = solution.maxPathSum(root6);
        int expected6 = 15;
        System.out.println("Result: " + result6);
        System.out.println("Expected: " + expected6);
        if (result6 != expected6) {
            throw new AssertionError("Test 6 failed");
        }

        // Test case 7: Larger tree
        System.out.println("\nTest 7: root = [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]");
        TreeNode root7 = buildTree(new Integer[] { 9, 6, -3, null, null, -6, 2, null, null, 2, null, -6, -6, -6 });
        int result7 = solution.maxPathSum(root7);
        int expected7 = 16;
        System.out.println("Result: " + result7);
        System.out.println("Expected: " + expected7);
        if (result7 != expected7) {
            throw new AssertionError("Test 7 failed");
        }

        // Test case 8: Two nodes with positive values
        System.out.println("\nTest 8: root = [1,2]");
        TreeNode root8 = buildTree(new Integer[] { 1, 2 });
        int result8 = solution.maxPathSum(root8);
        int expected8 = 3;
        System.out.println("Result: " + result8);
        System.out.println("Expected: " + expected8);
        if (result8 != expected8) {
            throw new AssertionError("Test 8 failed");
        }

        // Test case 9: Mix of positive and negative
        System.out.println("\nTest 9: root = [-1,5,null,4,null,null,2,-4]");
        TreeNode root9 = buildTree(new Integer[] { -1, 5, null, 4, null, null, 2, -4 });
        int result9 = solution.maxPathSum(root9);
        int expected9 = 11;
        System.out.println("Result: " + result9);
        System.out.println("Expected: " + expected9);
        if (result9 != expected9) {
            throw new AssertionError("Test 9 failed");
        }

        System.out.println("\n✅ All tests passed!");
    }
}
