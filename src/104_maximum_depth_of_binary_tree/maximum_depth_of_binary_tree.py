# 104. Maximum Depth of Binary Tree
# Difficulty: Easy
# Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        Returns the maximum depth of a binary tree.

        Args:
            root: The root of the binary tree

        Returns:
            The maximum depth (number of nodes along longest path from root to leaf)
        """
        return (
            0
            if not root
            else max(1 + self.maxDepth(root.left), 1 + self.maxDepth(root.right))
        )


# Helper functions for testing
def build_tree(values: List[Optional[int]]) -> Optional[TreeNode]:
    """Build a binary tree from level-order list representation."""
    if not values:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        node = queue.popleft()

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

    # Test case 1: Example 1
    root1 = build_tree([3, 9, 20, None, None, 15, 7])
    result1 = solution.maxDepth(root1)
    print(f"Test 1 - Input: [3,9,20,null,null,15,7]")
    print(f"Expected: 3")
    print(f"Got: {result1}")
    print()

    # Test case 2: Example 2
    root2 = build_tree([1, None, 2])
    result2 = solution.maxDepth(root2)
    print(f"Test 2 - Input: [1,null,2]")
    print(f"Expected: 2")
    print(f"Got: {result2}")
    print()

    # Test case 3: Empty tree
    root3 = build_tree([])
    result3 = solution.maxDepth(root3)
    print(f"Test 3 - Input: []")
    print(f"Expected: 0")
    print(f"Got: {result3}")
    print()

    # Test case 4: Single node
    root4 = build_tree([1])
    result4 = solution.maxDepth(root4)
    print(f"Test 4 - Input: [1]")
    print(f"Expected: 1")
    print(f"Got: {result4}")
    print()

    # Test case 5: Left-skewed tree
    root5 = build_tree([1, 2, None, 3, None, 4])
    result5 = solution.maxDepth(root5)
    print(f"Test 5 - Input: [1,2,null,3,null,4]")
    print(f"Expected: 4")
    print(f"Got: {result5}")
    print()

    # Test case 6: Balanced tree
    root6 = build_tree([1, 2, 3, 4, 5, 6, 7])
    result6 = solution.maxDepth(root6)
    print(f"Test 6 - Input: [1,2,3,4,5,6,7]")
    print(f"Expected: 3")
    print(f"Got: {result6}")
    print()


if __name__ == "__main__":
    run_tests()
