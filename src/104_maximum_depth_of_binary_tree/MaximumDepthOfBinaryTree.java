// 104. Maximum Depth of Binary Tree
// Difficulty: Easy
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree

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

public class MaximumDepthOfBinaryTree {
    /**
     * Returns the maximum depth of a binary tree.
     * 
     * @param root The root of the binary tree
     * @return The maximum depth (number of nodes along longest path from root to
     *         leaf)
     */
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int level = 0;

        ArrayDeque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.pollFirst();

                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            level++;
        }

        return level;
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
        MaximumDepthOfBinaryTree solution = new MaximumDepthOfBinaryTree();

        // Test case 1: Example 1
        TreeNode root1 = buildTree(new Integer[] { 3, 9, 20, null, null, 15, 7 });
        System.out.println("Test 1 - Input: [3,9,20,null,null,15,7]");
        System.out.println("Expected: 3");
        System.out.println("Got: " + solution.maxDepth(root1));
        System.out.println();

        // Test case 2: Example 2
        TreeNode root2 = buildTree(new Integer[] { 1, null, 2 });
        System.out.println("Test 2 - Input: [1,null,2]");
        System.out.println("Expected: 2");
        System.out.println("Got: " + solution.maxDepth(root2));
        System.out.println();

        // Test case 3: Empty tree
        TreeNode root3 = buildTree(new Integer[] {});
        System.out.println("Test 3 - Input: []");
        System.out.println("Expected: 0");
        System.out.println("Got: " + solution.maxDepth(root3));
        System.out.println();

        // Test case 4: Single node
        TreeNode root4 = buildTree(new Integer[] { 1 });
        System.out.println("Test 4 - Input: [1]");
        System.out.println("Expected: 1");
        System.out.println("Got: " + solution.maxDepth(root4));
        System.out.println();

        // Test case 5: Left-skewed tree
        TreeNode root5 = buildTree(new Integer[] { 1, 2, null, 3, null, 4 });
        System.out.println("Test 5 - Input: [1,2,null,3,null,4]");
        System.out.println("Expected: 4");
        System.out.println("Got: " + solution.maxDepth(root5));
        System.out.println();

        // Test case 6: Balanced tree
        TreeNode root6 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        System.out.println("Test 6 - Input: [1,2,3,4,5,6,7]");
        System.out.println("Expected: 3");
        System.out.println("Got: " + solution.maxDepth(root6));
        System.out.println();
    }
}
