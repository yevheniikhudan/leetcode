// 110. Balanced Binary Tree
// Difficulty: Easy
// Topics: Tree, Depth-First Search, Binary Tree

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

public class BalancedBinaryTree {
    /**
     * Determines if a binary tree is height-balanced.
     * 
     * A height-balanced binary tree is one where the depth of the two subtrees
     * of every node never differs by more than 1.
     * 
     * @param root The root of the binary tree
     * @return True if the tree is balanced, false otherwise
     */
    public boolean isBalanced(TreeNode root) {
        return dfs(root) != -1;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int longestLeft = dfs(root.left);
        if (longestLeft == -1) {
            return -1;
        }

        int longestRight = dfs(root.right);
        if (longestRight == -1) {
            return -1;
        }

        if (Math.abs(longestLeft - longestRight) > 1) {
            return -1;
        }

        return Math.max(longestLeft, longestRight) + 1;
    }

    // Helper method to build tree from level-order array
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
        BalancedBinaryTree solution = new BalancedBinaryTree();

        // Test case 1: Example 1 - Balanced tree
        TreeNode root1 = buildTree(new Integer[] { 3, 9, 20, null, null, 15, 7 });
        System.out.println("Test 1 - Input: [3,9,20,null,null,15,7]");
        System.out.println("Expected: true");
        System.out.println("Got: " + solution.isBalanced(root1));
        System.out.println();

        // Test case 2: Example 2 - Not balanced
        TreeNode root2 = buildTree(new Integer[] { 1, 2, 2, 3, 3, null, null, 4, 4 });
        System.out.println("Test 2 - Input: [1,2,2,3,3,null,null,4,4]");
        System.out.println("Expected: false");
        System.out.println("Got: " + solution.isBalanced(root2));
        System.out.println();

        // Test case 3: Empty tree
        TreeNode root3 = buildTree(new Integer[] {});
        System.out.println("Test 3 - Input: []");
        System.out.println("Expected: true");
        System.out.println("Got: " + solution.isBalanced(root3));
        System.out.println();

        // Test case 4: Single node
        TreeNode root4 = buildTree(new Integer[] { 1 });
        System.out.println("Test 4 - Input: [1]");
        System.out.println("Expected: true");
        System.out.println("Got: " + solution.isBalanced(root4));
        System.out.println();

        // Test case 5: Left-skewed tree
        TreeNode root5 = buildTree(new Integer[] { 1, 2, null, 3 });
        System.out.println("Test 5 - Input: [1,2,null,3]");
        System.out.println("Expected: false");
        System.out.println("Got: " + solution.isBalanced(root5));
        System.out.println();

        // Test case 6: Balanced complete tree
        TreeNode root6 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        System.out.println("Test 6 - Input: [1,2,3,4,5,6,7]");
        System.out.println("Expected: true");
        System.out.println("Got: " + solution.isBalanced(root6));
        System.out.println();
    }
}
