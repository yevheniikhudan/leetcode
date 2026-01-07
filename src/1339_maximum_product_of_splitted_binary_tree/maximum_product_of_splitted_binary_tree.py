from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7

        def computeSum(node):
            if not node:
                return 0

            leftSum = computeSum(node.left)
            rightSum = computeSum(node.right)

            return node.val + leftSum + rightSum

        totalSum = computeSum(root)

        maxProduct = 0

        def dfs(node):
            nonlocal maxProduct

            if not node:
                return 0

            leftSum = dfs(node.left)
            rightSum = dfs(node.right)
            subSum = node.val + leftSum + rightSum

            maxProduct = max(maxProduct, (subSum * (totalSum - subSum)))
            return subSum

        dfs(root)
        return maxProduct % MOD
