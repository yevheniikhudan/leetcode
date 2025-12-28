"""
124. Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
in the sequence has an edge connecting them. A node can only appear in the sequence
at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        """
        Find the maximum path sum in a binary tree.

        Args:
            root: Root of the binary tree

        Returns:
            Maximum path sum of any non-empty path
        """
        maxSum = float("-inf")

        def dfs(root):
            nonlocal maxSum

            if not root:
                return 0

            currentSum = root.val
            leftSum = max(dfs(root.left), 0)
            rightSum = max(dfs(root.right), 0)

            currentSum += max(leftSum, rightSum)

            maxSum = max(maxSum, root.val + leftSum + rightSum)

            return currentSum

        dfs(root)
        return maxSum


def build_tree(values: list) -> Optional[TreeNode]:
    """Build a binary tree from level-order list."""
    if not values:
        return None

    root = TreeNode(values[0])
    queue = [root]
    i = 1

    while queue and i < len(values):
        node = queue.pop(0)

        if i < len(values) and values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)
        i += 1

        if i < len(values) and values[i] is not None:
            node.right = TreeNode(values[i])
            queue.append(node.right)
        i += 1

    return root


def test_max_path_sum():
    """Test cases for maxPathSum."""
    solution = Solution()

    # Test case 1: Simple tree
    print("Test 1: root = [1,2,3]")
    root1 = build_tree([1, 2, 3])
    result1 = solution.maxPathSum(root1)
    expected1 = 6
    print(f"Result: {result1}")
    print(f"Expected: {expected1}")
    assert result1 == expected1, f"Test 1 failed"

    # Test case 2: Tree with negative root
    print("\nTest 2: root = [-10,9,20,null,null,15,7]")
    root2 = build_tree([-10, 9, 20, None, None, 15, 7])
    result2 = solution.maxPathSum(root2)
    expected2 = 42
    print(f"Result: {result2}")
    print(f"Expected: {expected2}")
    assert result2 == expected2, f"Test 2 failed"

    # Test case 3: Single node
    print("\nTest 3: root = [-3]")
    root3 = build_tree([-3])
    result3 = solution.maxPathSum(root3)
    expected3 = -3
    print(f"Result: {result3}")
    print(f"Expected: {expected3}")
    assert result3 == expected3, f"Test 3 failed"

    # Test case 4: All negative values
    print("\nTest 4: root = [-2,-1]")
    root4 = build_tree([-2, -1])
    result4 = solution.maxPathSum(root4)
    expected4 = -1
    print(f"Result: {result4}")
    print(f"Expected: {expected4}")
    assert result4 == expected4, f"Test 4 failed"

    # Test case 5: Path doesn't include root
    print("\nTest 5: root = [2,-1,-2]")
    root5 = build_tree([2, -1, -2])
    result5 = solution.maxPathSum(root5)
    expected5 = 2
    print(f"Result: {result5}")
    print(f"Expected: {expected5}")
    assert result5 == expected5, f"Test 5 failed"

    # Test case 6: Left skewed tree
    print("\nTest 6: root = [5,4,null,3,null,2,null,1]")
    root6 = build_tree([5, 4, None, 3, None, 2, None, 1])
    result6 = solution.maxPathSum(root6)
    expected6 = 15
    print(f"Result: {result6}")
    print(f"Expected: {expected6}")
    assert result6 == expected6, f"Test 6 failed"

    # Test case 7: Larger tree
    print("\nTest 7: root = [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]")
    root7 = build_tree([9, 6, -3, None, None, -6, 2, None, None, 2, None, -6, -6, -6])
    result7 = solution.maxPathSum(root7)
    expected7 = 16
    print(f"Result: {result7}")
    print(f"Expected: {expected7}")
    assert result7 == expected7, f"Test 7 failed"

    # Test case 8: Two nodes with positive values
    print("\nTest 8: root = [1,2]")
    root8 = build_tree([1, 2])
    result8 = solution.maxPathSum(root8)
    expected8 = 3
    print(f"Result: {result8}")
    print(f"Expected: {expected8}")
    assert result8 == expected8, f"Test 8 failed"

    # Test case 9: Mix of positive and negative
    print("\nTest 9: root = [-1,5,null,4,null,null,2,-4]")
    root9 = build_tree([-1, 5, None, 4, None, None, 2, -4])
    result9 = solution.maxPathSum(root9)
    expected9 = 11
    print(f"Result: {result9}")
    print(f"Expected: {expected9}")
    assert result9 == expected9, f"Test 9 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    test_max_path_sum()
