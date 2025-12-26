# 543. Diameter of Binary Tree
# Difficulty: Easy
# Topics: Tree, Depth-First Search, Binary Tree

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        """
        Returns the diameter of a binary tree.

        The diameter is the length of the longest path between any two nodes,
        measured in number of edges.

        Args:
            root: The root of the binary tree

        Returns:
            The diameter (number of edges in longest path)
        """
        diameter = 0

        def dfs(root: Optional[TreeNode]):
            nonlocal diameter

            if not root:
                return 0

            longest_left = dfs(root.left)
            longest_right = dfs(root.right)

            diameter = max(diameter, longest_left + longest_right)

            return max(longest_left, longest_right) + 1

        dfs(root)

        return diameter


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
    root1 = build_tree([1, 2, 3, 4, 5])
    result1 = solution.diameterOfBinaryTree(root1)
    print(f"Test 1 - Input: [1,2,3,4,5]")
    print(f"Expected: 3")
    print(f"Got: {result1}")
    print()

    # Test case 2: Example 2
    root2 = build_tree([1, 2])
    result2 = solution.diameterOfBinaryTree(root2)
    print(f"Test 2 - Input: [1,2]")
    print(f"Expected: 1")
    print(f"Got: {result2}")
    print()

    # Test case 3: Single node
    root3 = build_tree([1])
    result3 = solution.diameterOfBinaryTree(root3)
    print(f"Test 3 - Input: [1]")
    print(f"Expected: 0")
    print(f"Got: {result3}")
    print()

    # Test case 4: Balanced tree
    root4 = build_tree([1, 2, 3, 4, 5, 6, 7])
    result4 = solution.diameterOfBinaryTree(root4)
    print(f"Test 4 - Input: [1,2,3,4,5,6,7]")
    print(f"Expected: 4")
    print(f"Got: {result4}")
    print()

    # Test case 5: Left-skewed tree
    root5 = build_tree([1, 2, None, 3, None, 4])
    result5 = solution.diameterOfBinaryTree(root5)
    print(f"Test 5 - Input: [1,2,null,3,null,4]")
    print(f"Expected: 3")
    print(f"Got: {result5}")
    print()

    # Test case 6: Diameter not through root
    root6 = build_tree([1, 2, None, 4, 5, None, None, 6, 7])
    result6 = solution.diameterOfBinaryTree(root6)
    print(f"Test 6 - Input: [1,2,null,4,5,null,null,6,7]")
    print(f"Expected: 3")
    print(f"Got: {result6}")
    print(f"Tree structure:")
    print(f"      1")
    print(f"     /")
    print(f"    2")
    print(f"   / \\")
    print(f"  4   5")
    print(f"     / \\")
    print(f"    6   7")
    print(f"Longest path: 4->2->5->7 (3 edges)")
    print()


if __name__ == "__main__":
    run_tests()
