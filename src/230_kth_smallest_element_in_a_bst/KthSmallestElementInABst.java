
/**
 * 230. Kth Smallest Element in a BST
 *
 * Given the root of a binary search tree, and an integer k, return the kth
 * smallest value (1-indexed) of all the values of the nodes in the tree.
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
     * Find the kth smallest element in a BST.
     *
     * @param root The root of the binary search tree
     * @param k    The k value (1-indexed)
     * @return The kth smallest value in the BST
     */
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> inorder = new ArrayList<>();

        dfs(root, inorder, k);

        return inorder.get(k - 1);
    }

    private void dfs(TreeNode root, ArrayList<Integer> inorder, int k) {
        if (root == null)
            return;
        if (inorder.size() == k)
            return;

        dfs(root.left, inorder, k);
        inorder.add(root.val);
        dfs(root.right, inorder, k);
    }
}

public class KthSmallestElementInABst {
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

        // Test case 1: k=1 (smallest element)
        System.out.println("Test 1: BST [3,1,4,null,2], k=1");
        TreeNode root1 = buildTree(new Integer[] { 3, 1, 4, null, 2 });
        int result1 = solution.kthSmallest(root1, 1);
        int expected1 = 1;
        System.out.println("Result: " + result1);
        System.out.println("Expected: " + expected1);
        assert result1 == expected1 : "Test 1 failed";

        // Test case 2: k=3 (middle element)
        System.out.println("\nTest 2: BST [5,3,6,2,4,null,null,1], k=3");
        TreeNode root2 = buildTree(new Integer[] { 5, 3, 6, 2, 4, null, null, 1 });
        int result2 = solution.kthSmallest(root2, 3);
        int expected2 = 3;
        System.out.println("Result: " + result2);
        System.out.println("Expected: " + expected2);
        assert result2 == expected2 : "Test 2 failed";

        // Test case 3: Single node, k=1
        System.out.println("\nTest 3: BST [1], k=1");
        TreeNode root3 = buildTree(new Integer[] { 1 });
        int result3 = solution.kthSmallest(root3, 1);
        int expected3 = 1;
        System.out.println("Result: " + result3);
        System.out.println("Expected: " + expected3);
        assert result3 == expected3 : "Test 3 failed";

        // Test case 4: Two nodes, k=2
        System.out.println("\nTest 4: BST [2,1], k=2");
        TreeNode root4 = buildTree(new Integer[] { 2, 1 });
        int result4 = solution.kthSmallest(root4, 2);
        int expected4 = 2;
        System.out.println("Result: " + result4);
        System.out.println("Expected: " + expected4);
        assert result4 == expected4 : "Test 4 failed";

        // Test case 5: Right-skewed tree, k=3
        System.out.println("\nTest 5: BST [1,null,2,null,3,null,4], k=3");
        TreeNode root5 = buildTree(new Integer[] { 1, null, 2, null, 3, null, 4 });
        int result5 = solution.kthSmallest(root5, 3);
        int expected5 = 3;
        System.out.println("Result: " + result5);
        System.out.println("Expected: " + expected5);
        assert result5 == expected5 : "Test 5 failed";

        // Test case 6: Left-skewed tree, k=2
        System.out.println("\nTest 6: BST [4,3,null,2,null,1], k=2");
        TreeNode root6 = buildTree(new Integer[] { 4, 3, null, 2, null, 1 });
        int result6 = solution.kthSmallest(root6, 2);
        int expected6 = 2;
        System.out.println("Result: " + result6);
        System.out.println("Expected: " + expected6);
        assert result6 == expected6 : "Test 6 failed";

        // Test case 7: Balanced tree, k=4
        System.out.println("\nTest 7: BST [4,2,6,1,3,5,7], k=4");
        TreeNode root7 = buildTree(new Integer[] { 4, 2, 6, 1, 3, 5, 7 });
        int result7 = solution.kthSmallest(root7, 4);
        int expected7 = 4;
        System.out.println("Result: " + result7);
        System.out.println("Expected: " + expected7);
        assert result7 == expected7 : "Test 7 failed";

        // Test case 8: Last element (maximum)
        System.out.println("\nTest 8: BST [3,1,4,null,2], k=4");
        TreeNode root8 = buildTree(new Integer[] { 3, 1, 4, null, 2 });
        int result8 = solution.kthSmallest(root8, 4);
        int expected8 = 4;
        System.out.println("Result: " + result8);
        System.out.println("Expected: " + expected8);
        assert result8 == expected8 : "Test 8 failed";

        // Test case 9: Large tree, k=5
        System.out.println("\nTest 9: BST [10,5,15,3,7,null,18,1,4,6,8], k=5");
        TreeNode root9 = buildTree(new Integer[] { 10, 5, 15, 3, 7, null, 18, 1, 4, 6, 8 });
        int result9 = solution.kthSmallest(root9, 5);
        int expected9 = 6;
        System.out.println("Result: " + result9);
        System.out.println("Expected: " + expected9);
        assert result9 == expected9 : "Test 9 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
