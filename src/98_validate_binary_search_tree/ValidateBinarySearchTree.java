
/**
 * 98. Validate Binary Search Tree
 *
 * Given the root of a binary tree, return true if it is a valid binary search tree,
 * otherwise return false.
 *
 * A valid BST satisfies:
 * - Left subtree contains only nodes with keys less than node's key
 * - Right subtree contains only nodes with keys greater than node's key
 * - Both left and right subtrees are also BSTs
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
     * Determine if a binary tree is a valid binary search tree.
     *
     * @param root The root of the binary tree
     * @return True if the tree is a valid BST, false otherwise
     */
    public boolean isValidBST(TreeNode root) {
        return dfs(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean dfs(TreeNode root, long minVal, long maxVal) {
        if (root == null)
            return true;
        if (!(minVal < root.val && root.val < maxVal))
            return false;

        return dfs(root.left, minVal, root.val) && dfs(root.right, root.val, maxVal);
    }
}

public class ValidateBinarySearchTree {
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

        // Test case 1: Valid BST
        System.out.println("Test 1: Valid BST [2,1,3]");
        TreeNode root1 = buildTree(new Integer[] { 2, 1, 3 });
        boolean result1 = solution.isValidBST(root1);
        boolean expected1 = true;
        System.out.println("Result: " + result1);
        System.out.println("Expected: " + expected1);
        assert result1 == expected1 : "Test 1 failed";

        // Test case 2: Invalid BST (left child greater than root)
        System.out.println("\nTest 2: Invalid BST [1,2,3]");
        TreeNode root2 = buildTree(new Integer[] { 1, 2, 3 });
        boolean result2 = solution.isValidBST(root2);
        boolean expected2 = false;
        System.out.println("Result: " + result2);
        System.out.println("Expected: " + expected2);
        assert result2 == expected2 : "Test 2 failed";

        // Test case 3: Invalid BST (right subtree has value less than root)
        System.out.println("\nTest 3: Invalid BST [5,1,4,null,null,3,6]");
        TreeNode root3 = buildTree(new Integer[] { 5, 1, 4, null, null, 3, 6 });
        boolean result3 = solution.isValidBST(root3);
        boolean expected3 = false;
        System.out.println("Result: " + result3);
        System.out.println("Expected: " + expected3);
        assert result3 == expected3 : "Test 3 failed";

        // Test case 4: Single node
        System.out.println("\nTest 4: Single node [1]");
        TreeNode root4 = buildTree(new Integer[] { 1 });
        boolean result4 = solution.isValidBST(root4);
        boolean expected4 = true;
        System.out.println("Result: " + result4);
        System.out.println("Expected: " + expected4);
        assert result4 == expected4 : "Test 4 failed";

        // Test case 5: Valid BST with negative values
        System.out.println("\nTest 5: Valid BST with negatives [0,-1,1]");
        TreeNode root5 = buildTree(new Integer[] { 0, -1, 1 });
        boolean result5 = solution.isValidBST(root5);
        boolean expected5 = true;
        System.out.println("Result: " + result5);
        System.out.println("Expected: " + expected5);
        assert result5 == expected5 : "Test 5 failed";

        // Test case 6: Invalid BST (duplicate value)
        System.out.println("\nTest 6: Invalid BST with duplicate [5,1,5]");
        TreeNode root6 = buildTree(new Integer[] { 5, 1, 5 });
        boolean result6 = solution.isValidBST(root6);
        boolean expected6 = false;
        System.out.println("Result: " + result6);
        System.out.println("Expected: " + expected6);
        assert result6 == expected6 : "Test 6 failed";

        // Test case 7: Valid larger BST
        System.out.println("\nTest 7: Invalid BST [10,5,15,null,null,6,20]");
        TreeNode root7 = buildTree(new Integer[] { 10, 5, 15, null, null, 6, 20 });
        boolean result7 = solution.isValidBST(root7);
        boolean expected7 = false;
        System.out.println("Result: " + result7);
        System.out.println("Expected: " + expected7);
        assert result7 == expected7 : "Test 7 failed";

        // Test case 8: Left-skewed valid BST
        System.out.println("\nTest 8: Left-skewed BST [3,2,null,1]");
        TreeNode root8 = buildTree(new Integer[] { 3, 2, null, 1 });
        boolean result8 = solution.isValidBST(root8);
        boolean expected8 = true;
        System.out.println("Result: " + result8);
        System.out.println("Expected: " + expected8);
        assert result8 == expected8 : "Test 8 failed";

        // Test case 9: Right-skewed valid BST
        System.out.println("\nTest 9: Right-skewed BST [1,null,2,null,3]");
        TreeNode root9 = buildTree(new Integer[] { 1, null, 2, null, 3 });
        boolean result9 = solution.isValidBST(root9);
        boolean expected9 = true;
        System.out.println("Result: " + result9);
        System.out.println("Expected: " + expected9);
        assert result9 == expected9 : "Test 9 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
