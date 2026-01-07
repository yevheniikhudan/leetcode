// Definition for a binary tree node.
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

// Solution class for logic
class Solution {
    int MOD;
    long maxProduct;
    long totalSum;

    public int maxProduct(TreeNode root) {
        MOD = 1_000_000_007;

        totalSum = totalSum(root);
        dfs(root);

        return (int) (maxProduct % MOD);
    }

    private int totalSum(TreeNode root) {
        if (root == null)
            return 0;

        return totalSum(root.left) + totalSum(root.right) + root.val;
    }

    private long dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }

        long subtreeSum = dfs(root.left) + dfs(root.right) + root.val;

        maxProduct = Math.max(maxProduct, (long) ((totalSum - subtreeSum) * subtreeSum));

        return subtreeSum;
    }
}

// ...existing code...
