// 226. Invert Binary Tree
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

public class InvertBinaryTree {
    /**
     * Inverts a binary tree (mirrors it).
     * 
     * @param root The root of the binary tree
     * @return The root of the inverted binary tree
     */
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        invertTree(root.left);
        invertTree(root.right);

        return root;
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

    // Helper method to convert tree to level-order list
    private static List<Integer> treeToList(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<Integer> result = new ArrayList<>();
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

    // Helper method to print list
    private static void printList(List<Integer> list) {
        System.out.print("[");
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == null) {
                System.out.print("null");
            } else {
                System.out.print(list.get(i));
            }
            if (i < list.size() - 1) {
                System.out.print(",");
            }
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        InvertBinaryTree solution = new InvertBinaryTree();

        // Test case 1: Example 1
        TreeNode root1 = buildTree(new Integer[] { 4, 2, 7, 1, 3, 6, 9 });
        System.out.println("Test 1 - Input: [4,2,7,1,3,6,9]");
        System.out.println("Expected: [4,7,2,9,6,3,1]");
        System.out.print("Got: ");
        printList(treeToList(solution.invertTree(root1)));
        System.out.println();

        // Test case 2: Example 2
        TreeNode root2 = buildTree(new Integer[] { 2, 1, 3 });
        System.out.println("Test 2 - Input: [2,1,3]");
        System.out.println("Expected: [2,3,1]");
        System.out.print("Got: ");
        printList(treeToList(solution.invertTree(root2)));
        System.out.println();

        // Test case 3: Empty tree
        TreeNode root3 = buildTree(new Integer[] {});
        System.out.println("Test 3 - Input: []");
        System.out.println("Expected: []");
        System.out.print("Got: ");
        printList(treeToList(solution.invertTree(root3)));
        System.out.println();

        // Test case 4: Single node
        TreeNode root4 = buildTree(new Integer[] { 1 });
        System.out.println("Test 4 - Input: [1]");
        System.out.println("Expected: [1]");
        System.out.print("Got: ");
        printList(treeToList(solution.invertTree(root4)));
        System.out.println();

        // Test case 5: Left-skewed tree
        TreeNode root5 = buildTree(new Integer[] { 1, 2, null, 3 });
        System.out.println("Test 5 - Input: [1,2,null,3]");
        System.out.println("Expected: [1,null,2,null,3]");
        System.out.print("Got: ");
        printList(treeToList(solution.invertTree(root5)));
        System.out.println();
    }
}
