// 543. Diameter of Binary Tree
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

public class DiameterOfBinaryTree {
    /**
     * Returns the diameter of a binary tree.
     * 
     * The diameter is the length of the longest path between any two nodes,
     * measured in number of edges.
     * 
     * @param root The root of the binary tree
     * @return The diameter (number of edges in longest path)
     */
    public int diameterOfBinaryTree(TreeNode root) {
        // TODO: Implement this method
        return 0;
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
        DiameterOfBinaryTree solution = new DiameterOfBinaryTree();

        // Test case 1: Example 1
        TreeNode root1 = buildTree(new Integer[] { 1, 2, 3, 4, 5 });
        System.out.println("Test 1 - Input: [1,2,3,4,5]");
        System.out.println("Expected: 3");
        System.out.println("Got: " + solution.diameterOfBinaryTree(root1));
        System.out.println();

        // Test case 2: Example 2
        TreeNode root2 = buildTree(new Integer[] { 1, 2 });
        System.out.println("Test 2 - Input: [1,2]");
        System.out.println("Expected: 1");
        System.out.println("Got: " + solution.diameterOfBinaryTree(root2));
        System.out.println();

        // Test case 3: Single node
        TreeNode root3 = buildTree(new Integer[] { 1 });
        System.out.println("Test 3 - Input: [1]");
        System.out.println("Expected: 0");
        System.out.println("Got: " + solution.diameterOfBinaryTree(root3));
        System.out.println();

        // Test case 4: Balanced tree
        TreeNode root4 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        System.out.println("Test 4 - Input: [1,2,3,4,5,6,7]");
        System.out.println("Expected: 4");
        System.out.println("Got: " + solution.diameterOfBinaryTree(root4));
        System.out.println();

        // Test case 5: Left-skewed tree
        TreeNode root5 = buildTree(new Integer[] { 1, 2, null, 3, null, 4 });
        System.out.println("Test 5 - Input: [1,2,null,3,null,4]");
        System.out.println("Expected: 3");
        System.out.println("Got: " + solution.diameterOfBinaryTree(root5));
        System.out.println();

        // Test case 6: Diameter not through root
        TreeNode root6 = buildTree(new Integer[] { 1, 2, null, 4, 5, null, null, 6, 7 });
        System.out.println("Test 6 - Input: [1,2,null,4,5,null,null,6,7]");
        System.out.println("Expected: 4");
        System.out.println("Got: " + solution.diameterOfBinaryTree(root6));
        System.out.println();
    }
}
