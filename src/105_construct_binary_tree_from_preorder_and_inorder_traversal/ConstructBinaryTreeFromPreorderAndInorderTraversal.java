
/**
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same tree,
 * construct and return the binary tree.
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
    int preId;
    Map<Integer, Integer> indices;

    /**
     * Construct binary tree from preorder and inorder traversals.
     *
     * @param preorder Preorder traversal of the tree
     * @param inorder  Inorder traversal of the tree
     * @return Root of the constructed binary tree
     */
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        preId = 0;
        indices = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            indices.put(inorder[i], i);
        }

        return dfs(preorder, 0, preorder.length - 1);
    }

    private TreeNode dfs(int[] preorder, int left, int right) {
        if (left > right) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[preId++]);
        int mid = indices.get(root.val);

        root.left = dfs(preorder, left, mid - 1);
        root.right = dfs(preorder, mid + 1, right);

        return root;
    }
}

public class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    // Helper function to convert tree to level-order list
    private static List<Integer> treeToList(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node != null) {
                result.add(node.val);
                queue.offer(node.left);
                queue.offer(node.right);
            } else {
                result.add(null);
            }
        }

        // Remove trailing nulls
        while (!result.isEmpty() && result.get(result.size() - 1) == null) {
            result.remove(result.size() - 1);
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example tree
        System.out.println("Test 1: preorder=[3,9,20,15,7], inorder=[9,3,15,20,7]");
        int[] preorder1 = { 3, 9, 20, 15, 7 };
        int[] inorder1 = { 9, 3, 15, 20, 7 };
        TreeNode result1 = solution.buildTree(preorder1, inorder1);
        List<Integer> resultList1 = treeToList(result1);
        List<Integer> expected1 = Arrays.asList(3, 9, 20, null, null, 15, 7);
        System.out.println("Result: " + resultList1);
        System.out.println("Expected: " + expected1);
        if (!resultList1.equals(expected1)) {
            throw new AssertionError("Test 1 failed");
        }

        // Test case 2: Single node
        System.out.println("\nTest 2: preorder=[-1], inorder=[-1]");
        int[] preorder2 = { -1 };
        int[] inorder2 = { -1 };
        TreeNode result2 = solution.buildTree(preorder2, inorder2);
        List<Integer> resultList2 = treeToList(result2);
        List<Integer> expected2 = Arrays.asList(-1);
        System.out.println("Result: " + resultList2);
        System.out.println("Expected: " + expected2);
        if (!resultList2.equals(expected2)) {
            throw new AssertionError("Test 2 failed");
        }

        // Test case 3: Left-skewed tree
        System.out.println("\nTest 3: preorder=[1,2,3], inorder=[3,2,1]");
        int[] preorder3 = { 1, 2, 3 };
        int[] inorder3 = { 3, 2, 1 };
        TreeNode result3 = solution.buildTree(preorder3, inorder3);
        List<Integer> resultList3 = treeToList(result3);
        List<Integer> expected3 = Arrays.asList(1, 2, null, 3);
        System.out.println("Result: " + resultList3);
        System.out.println("Expected: " + expected3);
        if (!resultList3.equals(expected3)) {
            throw new AssertionError("Test 3 failed");
        }

        // Test case 4: Right-skewed tree
        System.out.println("\nTest 4: preorder=[1,2,3], inorder=[1,2,3]");
        int[] preorder4 = { 1, 2, 3 };
        int[] inorder4 = { 1, 2, 3 };
        TreeNode result4 = solution.buildTree(preorder4, inorder4);
        List<Integer> resultList4 = treeToList(result4);
        List<Integer> expected4 = Arrays.asList(1, null, 2, null, 3);
        System.out.println("Result: " + resultList4);
        System.out.println("Expected: " + expected4);
        if (!resultList4.equals(expected4)) {
            throw new AssertionError("Test 4 failed");
        }

        // Test case 5: Balanced tree
        System.out.println("\nTest 5: preorder=[1,2,4,5,3,6,7], inorder=[4,2,5,1,6,3,7]");
        int[] preorder5 = { 1, 2, 4, 5, 3, 6, 7 };
        int[] inorder5 = { 4, 2, 5, 1, 6, 3, 7 };
        TreeNode result5 = solution.buildTree(preorder5, inorder5);
        List<Integer> resultList5 = treeToList(result5);
        List<Integer> expected5 = Arrays.asList(1, 2, 3, 4, 5, 6, 7);
        System.out.println("Result: " + resultList5);
        System.out.println("Expected: " + expected5);
        if (!resultList5.equals(expected5)) {
            throw new AssertionError("Test 5 failed");
        }

        // Test case 6: Two nodes (left child)
        System.out.println("\nTest 6: preorder=[1,2], inorder=[2,1]");
        int[] preorder6 = { 1, 2 };
        int[] inorder6 = { 2, 1 };
        TreeNode result6 = solution.buildTree(preorder6, inorder6);
        List<Integer> resultList6 = treeToList(result6);
        List<Integer> expected6 = Arrays.asList(1, 2);
        System.out.println("Result: " + resultList6);
        System.out.println("Expected: " + expected6);
        if (!resultList6.equals(expected6)) {
            throw new AssertionError("Test 6 failed");
        }

        // Test case 7: Two nodes (right child)
        System.out.println("\nTest 7: preorder=[1,2], inorder=[1,2]");
        int[] preorder7 = { 1, 2 };
        int[] inorder7 = { 1, 2 };
        TreeNode result7 = solution.buildTree(preorder7, inorder7);
        List<Integer> resultList7 = treeToList(result7);
        List<Integer> expected7 = Arrays.asList(1, null, 2);
        System.out.println("Result: " + resultList7);
        System.out.println("Expected: " + expected7);
        if (!resultList7.equals(expected7)) {
            throw new AssertionError("Test 7 failed");
        }

        // Test case 8: Larger unbalanced tree
        System.out.println("\nTest 8: preorder=[3,9,8,5,20,15,7], inorder=[8,9,5,3,15,20,7]");
        int[] preorder8 = { 3, 9, 8, 5, 20, 15, 7 };
        int[] inorder8 = { 8, 9, 5, 3, 15, 20, 7 };
        TreeNode result8 = solution.buildTree(preorder8, inorder8);
        List<Integer> resultList8 = treeToList(result8);
        List<Integer> expected8 = Arrays.asList(3, 9, 20, 8, 5, 15, 7);
        System.out.println("Result: " + resultList8);
        System.out.println("Expected: " + expected8);
        if (!resultList8.equals(expected8)) {
            throw new AssertionError("Test 8 failed");
        }

        System.out.println("\n✅ All tests passed!");
    }
}
