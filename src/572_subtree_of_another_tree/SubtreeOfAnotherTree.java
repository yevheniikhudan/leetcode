
/**
 * 572. Subtree of Another Tree
 * 
 * Given the roots of two binary trees root and subRoot, return true if there is a subtree 
 * of root with the same structure and node values of subRoot and false otherwise.
 * 
 * A subtree of a binary tree tree is a tree that consists of a node in tree and all of 
 * this node's descendants. The tree tree could also be considered as a subtree of itself.
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
     * Check if subRoot is a subtree of root.
     * 
     * @param root    Root of the main binary tree
     * @param subRoot Root of the potential subtree
     * @return true if subRoot is a subtree of root, false otherwise
     */
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }

    private boolean isSameTree(TreeNode a, TreeNode b) {
        if (a == null || b == null) {
            return a == b;
        }

        if (a.val != b.val) {
            return false;
        }

        return isSameTree(a.left, b.left) && isSameTree(a.right, b.right);
    }
}

public class SubtreeOfAnotherTree {
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

        // Test case 1: subRoot is subtree at left child
        System.out.println("Test 1: subRoot is subtree at left child");
        TreeNode root1 = buildTree(new Integer[] { 3, 4, 5, 1, 2 });
        TreeNode subRoot1 = buildTree(new Integer[] { 4, 1, 2 });
        boolean result1 = solution.isSubtree(root1, subRoot1);
        System.out.println("Result: " + result1 + ", Expected: true");
        assert result1 == true : "Test 1 failed";

        // Test case 2: Extra node in root's subtree
        System.out.println("\nTest 2: Extra node in root's subtree");
        TreeNode root2 = buildTree(new Integer[] { 3, 4, 5, 1, 2, null, null, null, null, 0 });
        TreeNode subRoot2 = buildTree(new Integer[] { 4, 1, 2 });
        boolean result2 = solution.isSubtree(root2, subRoot2);
        System.out.println("Result: " + result2 + ", Expected: false");
        assert result2 == false : "Test 2 failed";

        // Test case 3: subRoot equals entire root
        System.out.println("\nTest 3: subRoot equals entire root");
        TreeNode root3 = buildTree(new Integer[] { 1, 2, 3 });
        TreeNode subRoot3 = buildTree(new Integer[] { 1, 2, 3 });
        boolean result3 = solution.isSubtree(root3, subRoot3);
        System.out.println("Result: " + result3 + ", Expected: true");
        assert result3 == true : "Test 3 failed";

        // Test case 4: Single node trees, matching
        System.out.println("\nTest 4: Single node trees, matching");
        TreeNode root4 = buildTree(new Integer[] { 1 });
        TreeNode subRoot4 = buildTree(new Integer[] { 1 });
        boolean result4 = solution.isSubtree(root4, subRoot4);
        System.out.println("Result: " + result4 + ", Expected: true");
        assert result4 == true : "Test 4 failed";

        // Test case 5: Single node trees, not matching
        System.out.println("\nTest 5: Single node trees, not matching");
        TreeNode root5 = buildTree(new Integer[] { 1 });
        TreeNode subRoot5 = buildTree(new Integer[] { 2 });
        boolean result5 = solution.isSubtree(root5, subRoot5);
        System.out.println("Result: " + result5 + ", Expected: false");
        assert result5 == false : "Test 5 failed";

        // Test case 6: subRoot at right child
        System.out.println("\nTest 6: subRoot at right child");
        TreeNode root6 = buildTree(new Integer[] { 3, 4, 5, 1, 2 });
        TreeNode subRoot6 = buildTree(new Integer[] { 5 });
        boolean result6 = solution.isSubtree(root6, subRoot6);
        System.out.println("Result: " + result6 + ", Expected: true");
        assert result6 == true : "Test 6 failed";

        // Test case 7: subRoot is leaf node
        System.out.println("\nTest 7: subRoot is leaf node");
        TreeNode root7 = buildTree(new Integer[] { 3, 4, 5, 1, 2 });
        TreeNode subRoot7 = buildTree(new Integer[] { 2 });
        boolean result7 = solution.isSubtree(root7, subRoot7);
        System.out.println("Result: " + result7 + ", Expected: true");
        assert result7 == true : "Test 7 failed";

        // Test case 8: Similar structure but different values
        System.out.println("\nTest 8: Similar structure but different values");
        TreeNode root8 = buildTree(new Integer[] { 3, 4, 5, 1, 2 });
        TreeNode subRoot8 = buildTree(new Integer[] { 4, 1, 3 });
        boolean result8 = solution.isSubtree(root8, subRoot8);
        System.out.println("Result: " + result8 + ", Expected: false");
        assert result8 == false : "Test 8 failed";

        // Test case 9: subRoot larger than root
        System.out.println("\nTest 9: subRoot larger than root");
        TreeNode root9 = buildTree(new Integer[] { 1, 2 });
        TreeNode subRoot9 = buildTree(new Integer[] { 1, 2, 3 });
        boolean result9 = solution.isSubtree(root9, subRoot9);
        System.out.println("Result: " + result9 + ", Expected: false");
        assert result9 == false : "Test 9 failed";

        // Test case 10: Complex tree, subRoot deep inside
        System.out.println("\nTest 10: Complex tree, subRoot deep inside");
        TreeNode root10 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
        TreeNode subRoot10 = buildTree(new Integer[] { 4, 8, 9 });
        boolean result10 = solution.isSubtree(root10, subRoot10);
        System.out.println("Result: " + result10 + ", Expected: true");
        assert result10 == true : "Test 10 failed";

        // Test case 11: Partial match (substring-like scenario)
        System.out.println("\nTest 11: Value appears but not as subtree");
        TreeNode root11 = buildTree(new Integer[] { 12 });
        TreeNode subRoot11 = buildTree(new Integer[] { 2 });
        boolean result11 = solution.isSubtree(root11, subRoot11);
        System.out.println("Result: " + result11 + ", Expected: false");
        assert result11 == false : "Test 11 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
