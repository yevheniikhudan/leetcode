
/**
 * 199. Binary Tree Right Side View
 * 
 * Given the root of a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
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
     * Return the right side view of binary tree.
     * 
     * @param root Root of the binary tree
     * @return List of values visible from right side (rightmost node at each level)
     */
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();

        if (root != null) {
            queue.offer(root);
        }

        while (queue.size() > 0) {
            int levelSize = queue.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode current = queue.poll();

                if (i == levelSize - 1)
                    result.add(current.val);
                if (current.left != null)
                    queue.offer(current.left);
                if (current.right != null)
                    queue.offer(current.right);
            }
        }

        return result;
    }
}

public class BinaryTreeRightSideView {
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

        // Test case 1: Standard example with left nodes visible
        System.out.println("Test 1: Tree [1,2,3,null,5,null,4]");
        TreeNode root1 = buildTree(new Integer[] { 1, 2, 3, null, 5, null, 4 });
        List<Integer> result1 = solution.rightSideView(root1);
        List<Integer> expected1 = Arrays.asList(1, 3, 4);
        System.out.println("Result: " + result1);
        System.out.println("Expected: " + expected1);
        assert result1.equals(expected1) : "Test 1 failed";

        // Test case 2: Left-skewed tree visible from right
        System.out.println("\nTest 2: Tree [1,2,3,4,null,null,null,5]");
        TreeNode root2 = buildTree(new Integer[] { 1, 2, 3, 4, null, null, null, 5 });
        List<Integer> result2 = solution.rightSideView(root2);
        List<Integer> expected2 = Arrays.asList(1, 3, 4, 5);
        System.out.println("Result: " + result2);
        System.out.println("Expected: " + expected2);
        assert result2.equals(expected2) : "Test 2 failed";

        // Test case 3: Only right children
        System.out.println("\nTest 3: Tree [1,null,3]");
        TreeNode root3 = buildTree(new Integer[] { 1, null, 3 });
        List<Integer> result3 = solution.rightSideView(root3);
        List<Integer> expected3 = Arrays.asList(1, 3);
        System.out.println("Result: " + result3);
        System.out.println("Expected: " + expected3);
        assert result3.equals(expected3) : "Test 3 failed";

        // Test case 4: Empty tree
        System.out.println("\nTest 4: Empty tree");
        TreeNode root4 = null;
        List<Integer> result4 = solution.rightSideView(root4);
        List<Integer> expected4 = new ArrayList<>();
        System.out.println("Result: " + result4);
        System.out.println("Expected: " + expected4);
        assert result4.equals(expected4) : "Test 4 failed";

        // Test case 5: Single node
        System.out.println("\nTest 5: Single node [1]");
        TreeNode root5 = buildTree(new Integer[] { 1 });
        List<Integer> result5 = solution.rightSideView(root5);
        List<Integer> expected5 = Arrays.asList(1);
        System.out.println("Result: " + result5);
        System.out.println("Expected: " + expected5);
        assert result5.equals(expected5) : "Test 5 failed";

        // Test case 6: Complete binary tree
        System.out.println("\nTest 6: Complete tree [1,2,3,4,5,6,7]");
        TreeNode root6 = buildTree(new Integer[] { 1, 2, 3, 4, 5, 6, 7 });
        List<Integer> result6 = solution.rightSideView(root6);
        List<Integer> expected6 = Arrays.asList(1, 3, 7);
        System.out.println("Result: " + result6);
        System.out.println("Expected: " + expected6);
        assert result6.equals(expected6) : "Test 6 failed";

        // Test case 7: Only left children
        System.out.println("\nTest 7: Left-skewed tree [1,2,null,3,null,4]");
        TreeNode root7 = buildTree(new Integer[] { 1, 2, null, 3, null, 4 });
        List<Integer> result7 = solution.rightSideView(root7);
        List<Integer> expected7 = Arrays.asList(1, 2, 3, 4);
        System.out.println("Result: " + result7);
        System.out.println("Expected: " + expected7);
        assert result7.equals(expected7) : "Test 7 failed";

        // Test case 8: Zigzag pattern
        System.out.println("\nTest 8: Zigzag pattern [1,2,3,null,5,null,4,null,6]");
        TreeNode root8 = buildTree(new Integer[] { 1, 2, 3, null, 5, null, 4, null, 6 });
        List<Integer> result8 = solution.rightSideView(root8);
        List<Integer> expected8 = Arrays.asList(1, 3, 4, 6);
        System.out.println("Result: " + result8);
        System.out.println("Expected: " + expected8);
        assert result8.equals(expected8) : "Test 8 failed";

        // Test case 9: Two nodes (left child only)
        System.out.println("\nTest 9: Two nodes [1,2]");
        TreeNode root9 = buildTree(new Integer[] { 1, 2 });
        List<Integer> result9 = solution.rightSideView(root9);
        List<Integer> expected9 = Arrays.asList(1, 2);
        System.out.println("Result: " + result9);
        System.out.println("Expected: " + expected9);
        assert result9.equals(expected9) : "Test 9 failed";

        // Test case 10: Two nodes (right child only)
        System.out.println("\nTest 10: Two nodes [1,null,2]");
        TreeNode root10 = buildTree(new Integer[] { 1, null, 2 });
        List<Integer> result10 = solution.rightSideView(root10);
        List<Integer> expected10 = Arrays.asList(1, 2);
        System.out.println("Result: " + result10);
        System.out.println("Expected: " + expected10);
        assert result10.equals(expected10) : "Test 10 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
