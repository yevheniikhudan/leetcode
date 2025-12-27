"""
102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).
"""

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Return level order traversal of binary tree.

        Args:
            root: Root of the binary tree

        Returns:
            List of lists, where each inner list contains values at that level
        """
        res = []

        def dfs(root, level):
            if not root:
                return

            if len(res) == level:
                res.append([])

            res[level].append(root.val)

            dfs(root.left, level + 1)
            dfs(root.right, level + 1)

        dfs(root, 0)

        return res


# Test cases
def build_tree(values):
    """Helper function to build a binary tree from a list (level-order)."""
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


def run_tests():
    solution = Solution()

    # Test case 1: Standard tree with 3 levels
    print("Test 1: Standard tree [3,9,20,null,null,15,7]")
    root1 = build_tree([3, 9, 20, None, None, 15, 7])
    result1 = solution.levelOrder(root1)
    expected1 = [[3], [9, 20], [15, 7]]
    print(f"Result: {result1}")
    print(f"Expected: {expected1}")
    assert result1 == expected1, "Test 1 failed"

    # Test case 2: Single node
    print("\nTest 2: Single node [1]")
    root2 = build_tree([1])
    result2 = solution.levelOrder(root2)
    expected2 = [[1]]
    print(f"Result: {result2}")
    print(f"Expected: {expected2}")
    assert result2 == expected2, "Test 2 failed"

    # Test case 3: Empty tree
    print("\nTest 3: Empty tree []")
    root3 = None
    result3 = solution.levelOrder(root3)
    expected3 = []
    print(f"Result: {result3}")
    print(f"Expected: {expected3}")
    assert result3 == expected3, "Test 3 failed"

    # Test case 4: Complete binary tree
    print("\nTest 4: Complete binary tree [1,2,3,4,5,6,7]")
    root4 = build_tree([1, 2, 3, 4, 5, 6, 7])
    result4 = solution.levelOrder(root4)
    expected4 = [[1], [2, 3], [4, 5, 6, 7]]
    print(f"Result: {result4}")
    print(f"Expected: {expected4}")
    assert result4 == expected4, "Test 4 failed"

    # Test case 5: Left-skewed tree
    print("\nTest 5: Left-skewed tree [1,2,null,3]")
    root5 = build_tree([1, 2, None, 3])
    result5 = solution.levelOrder(root5)
    expected5 = [[1], [2], [3]]
    print(f"Result: {result5}")
    print(f"Expected: {expected5}")
    assert result5 == expected5, "Test 5 failed"

    # Test case 6: Right-skewed tree
    print("\nTest 6: Right-skewed tree [1,null,2,null,3]")
    root6 = build_tree([1, None, 2, None, 3])
    result6 = solution.levelOrder(root6)
    expected6 = [[1], [2], [3]]
    print(f"Result: {result6}")
    print(f"Expected: {expected6}")
    assert result6 == expected6, "Test 6 failed"

    # Test case 7: Tree with negative values
    print("\nTest 7: Tree with negative values [-10,9,20,null,null,15,7]")
    root7 = build_tree([-10, 9, 20, None, None, 15, 7])
    result7 = solution.levelOrder(root7)
    expected7 = [[-10], [9, 20], [15, 7]]
    print(f"Result: {result7}")
    print(f"Expected: {expected7}")
    assert result7 == expected7, "Test 7 failed"

    # Test case 8: Unbalanced tree
    print("\nTest 8: Unbalanced tree [1,2,3,4,null,null,5]")
    root8 = build_tree([1, 2, 3, 4, None, None, 5])
    result8 = solution.levelOrder(root8)
    expected8 = [[1], [2, 3], [4, 5]]
    print(f"Result: {result8}")
    print(f"Expected: {expected8}")
    assert result8 == expected8, "Test 8 failed"

    # Test case 9: Two nodes (parent-left child)
    print("\nTest 9: Two nodes [1,2]")
    root9 = build_tree([1, 2])
    result9 = solution.levelOrder(root9)
    expected9 = [[1], [2]]
    print(f"Result: {result9}")
    print(f"Expected: {expected9}")
    assert result9 == expected9, "Test 9 failed"

    # Test case 10: Large tree with 4 levels
    print("\nTest 10: Large tree with 4 levels")
    root10 = build_tree([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    result10 = solution.levelOrder(root10)
    expected10 = [[1], [2, 3], [4, 5, 6, 7], [8, 9, 10, 11, 12, 13, 14, 15]]
    print(f"Result: {result10}")
    print(f"Expected: {expected10}")
    assert result10 == expected10, "Test 10 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
