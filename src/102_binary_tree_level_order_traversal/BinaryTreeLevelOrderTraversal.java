
/**
 * 102. Binary Tree Level Order Traversal
 * 
 * Given the root of a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
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
     * Return level order traversal of binary tree.
     * 
     * @param root Root of the binary tree
     * @return List of lists, where each inner list contains values at that level
     */

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null)
            return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> currentLevel = new ArrayList<>();

            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                currentLevel.add(node.val);

                if (node.left != null)
                    queue.offer(node.left);
                if (node.right != null)
                    queue.offer(node.right);
            }

            result.add(currentLevel);
        }

        return result;
    }

    public List<List<Integer>> levelOrderDfs(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        dfs(root, 0, result);

        return result;
    }

    private void dfs(TreeNode root, int lvl, List<List<Integer>> levelOrder) {
        if (root == null) {
            return;
        }

        if (levelOrder.size() == lvl) {
            levelOrder.add(new ArrayList<>());
        }

        levelOrder.get(lvl).add(root.val);

        dfs(root.left, lvl + 1, levelOrder);
        dfs(root.right, lvl + 1, levelOrder);
    }
}

public class BinaryTreeLevelOrderTraversal {
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

        // Test case 1: Standard tree with 3 levels
        System.out.println("Test 1: Standard tree [3,9,20,null,null,15,7]");
        TreeNode root1 = buildTree(new Integer[] { 3, 9, 20, null, null, 15, 7 });
        List<List<Integer>> result1 = solution.levelOrder(root1);
        List<List<Integer>> expected1 = Arrays.asList(
                Arrays.asList(3),
                Arrays.asList(9, 20),
                Arrays.asList(15, 7));
        System.out.println("Result: " + result1);
        System.out.println("Expected: " + expected1);
        assert result1.equals(expected1) : "Test 1 failed";

        // Test case 2: Single node
        System.out.println("\nTest 2: Single node [1]");
        TreeNode root2 = buildTree(new Integer[] { 1 });
        List<List<Integer>> result2 = solution.levelOrder(root2);
        List<List<Integer>> expected2 = Arrays.asList(Arrays.asList(1));
        System.out.println("Result: " + result2);
        System.out.println("Expected: " + expected2);
        assert result2.equals(expected2) : "Test 2 failed";

        // Test case 3: Empty tree
        System.out.println("\nTest 3: Empty tree []");
        TreeNode root3 = null;
        List<List<Integer>> result3 = solution.levelOrder(root3);
        List<List<Integer>> expected3 = new ArrayList<>();
        System.out.println("Result: " + result3);
        System.out.println("Expected: " + expected3);
        assert result3.equals(expected3) : "Test 3 failed";

        // Test case 4: Complete binary tree
        System.out.println("\nTest 4: Complete binary tree [1,2,3,4,5,6,7]");
        TreeNode root4 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        List<List<Integer>> result4 = solution.levelOrder(root4);
        List<List<Integer>> expected4 = Arrays.asList(
                Arrays.asList(1),
                Arrays.asList(2, 3),
                Arrays.asList(4, 5, 6, 7));
        System.out.println("Result: " + result4);
        System.out.println("Expected: " + expected4);
        assert result4.equals(expected4) : "Test 4 failed";

        // Test case 5: Left-skewed tree
        System.out.println("\nTest 5: Left-skewed tree [1,2,null,3]");
        TreeNode root5 = buildTree(new Integer[] { 1, 2, null, 3 });
        List<List<Integer>> result5 = solution.levelOrder(root5);
        List<List<Integer>> expected5 = Arrays.asList(
                Arrays.asList(1),
                Arrays.asList(2),
                Arrays.asList(3));
        System.out.println("Result: " + result5);
        System.out.println("Expected: " + expected5);
        assert result5.equals(expected5) : "Test 5 failed";

        // Test case 6: Right-skewed tree
        System.out.println("\nTest 6: Right-skewed tree [1,null,2,null,3]");
        TreeNode root6 = buildTree(new Integer[] { 1, null, 2, null, 3 });
        List<List<Integer>> result6 = solution.levelOrder(root6);
        List<List<Integer>> expected6 = Arrays.asList(
                Arrays.asList(1),
                Arrays.asList(2),
                Arrays.asList(3));
        System.out.println("Result: " + result6);
        System.out.println("Expected: " + expected6);
        assert result6.equals(expected6) : "Test 6 failed";

        // Test case 7: Tree with negative values
        System.out.println("\nTest 7: Tree with negative values [-10,9,20,null,null,15,7]");
        TreeNode root7 = buildTree(new Integer[] { -10, 9, 20, null, null, 15, 7 });
        List<List<Integer>> result7 = solution.levelOrder(root7);
        List<List<Integer>> expected7 = Arrays.asList(
                Arrays.asList(-10),
                Arrays.asList(9, 20),
                Arrays.asList(15, 7));
        System.out.println("Result: " + result7);
        System.out.println("Expected: " + expected7);
        assert result7.equals(expected7) : "Test 7 failed";

        // Test case 8: Unbalanced tree
        System.out.println("\nTest 8: Unbalanced tree [1,2,3,4,null,null,5]");
        TreeNode root8 = buildTree(new Integer[] { 1, 2, 3, 4, null, null, 5 });
        List<List<Integer>> result8 = solution.levelOrder(root8);
        List<List<Integer>> expected8 = Arrays.asList(
                Arrays.asList(1),
                Arrays.asList(2, 3),
                Arrays.asList(4, 5));
        System.out.println("Result: " + result8);
        System.out.println("Expected: " + expected8);
        assert result8.equals(expected8) : "Test 8 failed";

        // Test case 9: Two nodes (parent-left child)
        System.out.println("\nTest 9: Two nodes [1,2]");
        TreeNode root9 = buildTree(new Integer[] { 1, 2 });
        List<List<Integer>> result9 = solution.levelOrder(root9);
        List<List<Integer>> expected9 = Arrays.asList(
                Arrays.asList(1),
                Arrays.asList(2));
        System.out.println("Result: " + result9);
        System.out.println("Expected: " + expected9);
        assert result9.equals(expected9) : "Test 9 failed";

        // Test case 10: Large tree with 4 levels
        System.out.println("\nTest 10: Large tree with 4 levels");
        TreeNode root10 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
        List<List<Integer>> result10 = solution.levelOrder(root10);
        List<List<Integer>> expected10 = Arrays.asList(
                Arrays.asList(1),
                Arrays.asList(2, 3),
                Arrays.asList(4, 5, 6, 7),
                Arrays.asList(8, 9, 10, 11, 12, 13, 14, 15));
        System.out.println("Result: " + result10);
        System.out.println("Expected: " + expected10);
        assert result10.equals(expected10) : "Test 10 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
