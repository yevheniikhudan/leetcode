# 226. Invert Binary Tree
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
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Inverts a binary tree (mirrors it).

        Args:
            root: The root of the binary tree

        Returns:
            The root of the inverted binary tree
        """
        if not root:
            return None

        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)

        return root


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


def tree_to_list(root: Optional[TreeNode]) -> List[Optional[int]]:
    """Convert binary tree to level-order list representation."""
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        node = queue.popleft()

        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)

    # Remove trailing None values
    while result and result[-1] is None:
        result.pop()

    return result


def run_tests():
    solution = Solution()

    # Test case 1: Example 1
    root1 = build_tree([4, 2, 7, 1, 3, 6, 9])
    result1 = solution.invertTree(root1)
    print(f"Test 1 - Input: [4,2,7,1,3,6,9]")
    print(f"Expected: [4,7,2,9,6,3,1]")
    print(f"Got: {tree_to_list(result1)}")
    print()

    # Test case 2: Example 2
    root2 = build_tree([2, 1, 3])
    result2 = solution.invertTree(root2)
    print(f"Test 2 - Input: [2,1,3]")
    print(f"Expected: [2,3,1]")
    print(f"Got: {tree_to_list(result2)}")
    print()

    # Test case 3: Empty tree
    root3 = build_tree([])
    result3 = solution.invertTree(root3)
    print(f"Test 3 - Input: []")
    print(f"Expected: []")
    print(f"Got: {tree_to_list(result3)}")
    print()

    # Test case 4: Single node
    root4 = build_tree([1])
    result4 = solution.invertTree(root4)
    print(f"Test 4 - Input: [1]")
    print(f"Expected: [1]")
    print(f"Got: {tree_to_list(result4)}")
    print()

    # Test case 5: Left-skewed tree
    root5 = build_tree([1, 2, None, 3])
    result5 = solution.invertTree(root5)
    print(f"Test 5 - Input: [1,2,null,3]")
    print(f"Expected: [1,null,2,null,3]")
    print(f"Got: {tree_to_list(result5)}")
    print()


if __name__ == "__main__":
    run_tests()
