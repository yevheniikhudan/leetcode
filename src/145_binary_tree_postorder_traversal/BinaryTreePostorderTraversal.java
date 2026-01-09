// Definition for a binary tree node.

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

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

class Pair {
    TreeNode node;
    boolean visited;

    Pair(TreeNode node, boolean visited) {
        this.node = node;
        this.visited = visited;
    }
}

// Solution class for logic
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        Deque<Pair> stack = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();

        stack.add(new Pair(root, false));

        while (!stack.isEmpty()) {
            Pair pair = stack.pollLast();
            if (pair.visited) {
                res.add(pair.node.val);
            } else if (pair.node != null) {
                stack.add(new Pair(pair.node, true));
                stack.add(new Pair(pair.node.right, false));
                stack.add(new Pair(pair.node.left, false));
            }
        }

        return res;
    }
}

// Main/test class
public class BinaryTreePostorderTraversal {
    // Helper to build tree from array (level order)
    private static TreeNode buildTree(Integer[] arr) {
        if (arr.length == 0)
            return null;
        java.util.Queue<TreeNode> queue = new java.util.LinkedList<>();
        TreeNode root = new TreeNode(arr[0]);
        queue.add(root);
        int i = 1;
        while (!queue.isEmpty() && i < arr.length) {
            TreeNode node = queue.poll();
            if (i < arr.length && arr[i] != null) {
                node.left = new TreeNode(arr[i]);
                queue.add(node.left);
            }
            i++;
            if (i < arr.length && arr[i] != null) {
                node.right = new TreeNode(arr[i]);
                queue.add(node.right);
            }
            i++;
        }
        return root;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        Object[][] tests = {
                { new Integer[] { 1, null, 2, 3 }, java.util.Arrays.asList(3, 2, 1) },
                { new Integer[] {}, java.util.Arrays.asList() },
                { new Integer[] { 1 }, java.util.Arrays.asList(1) },
                { new Integer[] { 1, 2, 3 }, java.util.Arrays.asList(2, 3, 1) },
                { new Integer[] { 1, null, 2 }, java.util.Arrays.asList(2, 1) },
        };
        for (int i = 0; i < tests.length; ++i) {
            TreeNode root = buildTree((Integer[]) tests[i][0]);
            java.util.List<Integer> expected = (java.util.List<Integer>) tests[i][1];
            java.util.List<Integer> result = sol.postorderTraversal(root);
            System.out.println("Test " + (i + 1) + ": " + result + " | " + expected);
        }
    }
}
