
/**
 * 297. Serialize and Deserialize Binary Tree
 *
 * Design an algorithm to serialize and deserialize a binary tree.
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

class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializeHelper(root, sb);
        return sb.toString();
    }

    private void serializeHelper(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append("N,");
            return;
        }
        sb.append(root.val).append(",");
        serializeHelper(root.left, sb);
        serializeHelper(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] nodes = data.split(",");
        int[] idx = new int[] { 0 };
        return deserializeHelper(nodes, idx);
    }

    private TreeNode deserializeHelper(String[] nodes, int[] idx) {
        if (nodes[idx[0]].equals("N")) {
            idx[0]++;
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(nodes[idx[0]]));
        idx[0]++;
        root.left = deserializeHelper(nodes, idx);
        root.right = deserializeHelper(nodes, idx);
        return root;
    }
}

public class SerializeAndDeserializeBinaryTree {
    // Helper function to build tree from level-order array
    private static TreeNode buildTree(Integer[] values) {
        if (values == null || values.length == 0) {
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
        Codec codec = new Codec();
        // Test case 1: Example tree
        System.out.println("Test 1: root = [1,2,3,null,null,4,5]");
        TreeNode root1 = buildTree(new Integer[] { 1, 2, 3, null, null, 4, 5 });
        String data1 = codec.serialize(root1);
        TreeNode result1 = codec.deserialize(data1);
        List<Integer> resultList1 = treeToList(result1);
        List<Integer> expected1 = Arrays.asList(1, 2, 3, null, null, 4, 5);
        System.out.println("Result: " + resultList1);
        System.out.println("Expected: " + expected1);
        if (!resultList1.equals(expected1)) {
            throw new AssertionError("Test 1 failed");
        }
        // Test case 2: Empty tree
        System.out.println("\nTest 2: root = []");
        TreeNode root2 = buildTree(new Integer[] {});
        String data2 = codec.serialize(root2);
        TreeNode result2 = codec.deserialize(data2);
        List<Integer> resultList2 = treeToList(result2);
        List<Integer> expected2 = Arrays.asList();
        System.out.println("Result: " + resultList2);
        System.out.println("Expected: " + expected2);
        if (!resultList2.equals(expected2)) {
            throw new AssertionError("Test 2 failed");
        }
        // Test case 3: Single node
        System.out.println("\nTest 3: root = [42]");
        TreeNode root3 = buildTree(new Integer[] { 42 });
        String data3 = codec.serialize(root3);
        TreeNode result3 = codec.deserialize(data3);
        List<Integer> resultList3 = treeToList(result3);
        List<Integer> expected3 = Arrays.asList(42);
        System.out.println("Result: " + resultList3);
        System.out.println("Expected: " + expected3);
        if (!resultList3.equals(expected3)) {
            throw new AssertionError("Test 3 failed");
        }
        // Test case 4: Left-skewed tree
        System.out.println("\nTest 4: root = [1,2,null,3,null,4]");
        TreeNode root4 = buildTree(new Integer[] { 1, 2, null, 3, null, 4 });
        String data4 = codec.serialize(root4);
        TreeNode result4 = codec.deserialize(data4);
        List<Integer> resultList4 = treeToList(result4);
        List<Integer> expected4 = Arrays.asList(1, 2, null, 3, null, 4);
        System.out.println("Result: " + resultList4);
        System.out.println("Expected: " + expected4);
        if (!resultList4.equals(expected4)) {
            throw new AssertionError("Test 4 failed");
        }
        // Test case 5: Right-skewed tree
        System.out.println("\nTest 5: root = [1,null,2,null,3,null,4]");
        TreeNode root5 = buildTree(new Integer[] { 1, null, 2, null, 3, null, 4 });
        String data5 = codec.serialize(root5);
        TreeNode result5 = codec.deserialize(data5);
        List<Integer> resultList5 = treeToList(result5);
        List<Integer> expected5 = Arrays.asList(1, null, 2, null, 3, null, 4);
        System.out.println("Result: " + resultList5);
        System.out.println("Expected: " + expected5);
        if (!resultList5.equals(expected5)) {
            throw new AssertionError("Test 5 failed");
        }
        System.out.println("\n✅ All tests passed!");
    }
}
