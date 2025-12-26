
/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes
 * p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a
 * descendant of itself)."
 */

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    /**
     * Find the lowest common ancestor of two nodes in a BST.
     * 
     * @param root Root of the BST
     * @param p    First node
     * @param q    Second node
     * @return The lowest common ancestor node
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (root != null) {
            if (p.val < root.val && q.val < root.val) {
                root = root.left;
            } else if (p.val > root.val && q.val > root.val) {
                root = root.right;
            } else {
                return root;
            }
        }
        return root;
    }
}

public class LowestCommonAncestorOfBst {
    /**
     * Helper function to build a BST from an array (level-order).
     */
    private static TreeNode buildBST(Integer[] values) {
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

    /**
     * Helper to find a node with given value in the tree.
     */
    private static TreeNode findNode(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        if (root.val == val) {
            return root;
        }

        TreeNode left = findNode(root.left, val);
        if (left != null) {
            return left;
        }

        return findNode(root.right, val);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: LCA of nodes in different subtrees
        System.out.println("Test 1: LCA of nodes in different subtrees (2, 8)");
        TreeNode root1 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p1 = findNode(root1, 2);
        TreeNode q1 = findNode(root1, 8);
        TreeNode result1 = solution.lowestCommonAncestor(root1, p1, q1);
        System.out.println("Result: " + (result1 != null ? result1.val : null) + ", Expected: 6");
        assert result1 != null && result1.val == 6 : "Test 1 failed";

        // Test case 2: LCA where one node is ancestor of the other
        System.out.println("\nTest 2: LCA where one node is ancestor of the other (2, 4)");
        TreeNode root2 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p2 = findNode(root2, 2);
        TreeNode q2 = findNode(root2, 4);
        TreeNode result2 = solution.lowestCommonAncestor(root2, p2, q2);
        System.out.println("Result: " + (result2 != null ? result2.val : null) + ", Expected: 2");
        assert result2 != null && result2.val == 2 : "Test 2 failed";

        // Test case 3: Small tree
        System.out.println("\nTest 3: Small tree (2, 1)");
        TreeNode root3 = buildBST(new Integer[] { 2, 1 });
        TreeNode p3 = findNode(root3, 2);
        TreeNode q3 = findNode(root3, 1);
        TreeNode result3 = solution.lowestCommonAncestor(root3, p3, q3);
        System.out.println("Result: " + (result3 != null ? result3.val : null) + ", Expected: 2");
        assert result3 != null && result3.val == 2 : "Test 3 failed";

        // Test case 4: LCA of leaf nodes
        System.out.println("\nTest 4: LCA of leaf nodes (3, 5)");
        TreeNode root4 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p4 = findNode(root4, 3);
        TreeNode q4 = findNode(root4, 5);
        TreeNode result4 = solution.lowestCommonAncestor(root4, p4, q4);
        System.out.println("Result: " + (result4 != null ? result4.val : null) + ", Expected: 4");
        assert result4 != null && result4.val == 4 : "Test 4 failed";

        // Test case 5: LCA in right subtree
        System.out.println("\nTest 5: LCA in right subtree (7, 9)");
        TreeNode root5 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p5 = findNode(root5, 7);
        TreeNode q5 = findNode(root5, 9);
        TreeNode result5 = solution.lowestCommonAncestor(root5, p5, q5);
        System.out.println("Result: " + (result5 != null ? result5.val : null) + ", Expected: 8");
        assert result5 != null && result5.val == 8 : "Test 5 failed";

        // Test case 6: LCA is the root
        System.out.println("\nTest 6: LCA is the root (0, 9)");
        TreeNode root6 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p6 = findNode(root6, 0);
        TreeNode q6 = findNode(root6, 9);
        TreeNode result6 = solution.lowestCommonAncestor(root6, p6, q6);
        System.out.println("Result: " + (result6 != null ? result6.val : null) + ", Expected: 6");
        assert result6 != null && result6.val == 6 : "Test 6 failed";

        // Test case 7: Adjacent nodes (parent-child)
        System.out.println("\nTest 7: Adjacent nodes (2, 0)");
        TreeNode root7 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p7 = findNode(root7, 2);
        TreeNode q7 = findNode(root7, 0);
        TreeNode result7 = solution.lowestCommonAncestor(root7, p7, q7);
        System.out.println("Result: " + (result7 != null ? result7.val : null) + ", Expected: 2");
        assert result7 != null && result7.val == 2 : "Test 7 failed";

        // Test case 8: Root and child
        System.out.println("\nTest 8: Root and child (6, 8)");
        TreeNode root8 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p8 = findNode(root8, 6);
        TreeNode q8 = findNode(root8, 8);
        TreeNode result8 = solution.lowestCommonAncestor(root8, p8, q8);
        System.out.println("Result: " + (result8 != null ? result8.val : null) + ", Expected: 6");
        assert result8 != null && result8.val == 6 : "Test 8 failed";

        // Test case 9: Deep nodes on same side
        System.out.println("\nTest 9: Deep nodes on same side (3, 4)");
        TreeNode root9 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p9 = findNode(root9, 3);
        TreeNode q9 = findNode(root9, 4);
        TreeNode result9 = solution.lowestCommonAncestor(root9, p9, q9);
        System.out.println("Result: " + (result9 != null ? result9.val : null) + ", Expected: 4");
        assert result9 != null && result9.val == 4 : "Test 9 failed";

        // Test case 10: Reversed order (q, p instead of p, q)
        System.out.println("\nTest 10: Reversed order (8, 2)");
        TreeNode root10 = buildBST(new Integer[] { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 });
        TreeNode p10 = findNode(root10, 8);
        TreeNode q10 = findNode(root10, 2);
        TreeNode result10 = solution.lowestCommonAncestor(root10, p10, q10);
        System.out.println("Result: " + (result10 != null ? result10.val : null) + ", Expected: 6");
        assert result10 != null && result10.val == 6 : "Test 10 failed";

        System.out.println("\n✅ All tests passed!");
    }
}
