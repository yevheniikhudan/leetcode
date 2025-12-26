# 110. Balanced Binary Tree
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
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        """
        Determines if a binary tree is height-balanced.

        A height-balanced binary tree is one where the depth of the two subtrees
        of every node never differs by more than 1.

        Args:
            root: The root of the binary tree

        Returns:
            True if the tree is balanced, False otherwise
        """

        def dfs(root):
            if not root:
                return 0

            longest_left = dfs(root.left)
            if longest_left == -1:
                return -1

            longest_right = dfs(root.right)
            if longest_right == -1:
                return -1

            if abs(longest_left - longest_right) > 1:
                return -1

            return max(longest_left, longest_right) + 1

        return dfs(root) != -1


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

    # Test case 1: Example 1 - Balanced tree
    root1 = build_tree([3, 9, 20, None, None, 15, 7])
    result1 = solution.isBalanced(root1)
    print(f"Test 1 - Input: [3,9,20,null,null,15,7]")
    print(f"Expected: True")
    print(f"Got: {result1}")
    print()

    # Test case 2: Example 2 - Not balanced
    root2 = build_tree([1, 2, 2, 3, 3, None, None, 4, 4])
    result2 = solution.isBalanced(root2)
    print(f"Test 2 - Input: [1,2,2,3,3,null,null,4,4]")
    print(f"Expected: False")
    print(f"Got: {result2}")
    print()

    # Test case 3: Empty tree
    root3 = build_tree([])
    result3 = solution.isBalanced(root3)
    print(f"Test 3 - Input: []")
    print(f"Expected: True")
    print(f"Got: {result3}")
    print()

    # Test case 4: Single node
    root4 = build_tree([1])
    result4 = solution.isBalanced(root4)
    print(f"Test 4 - Input: [1]")
    print(f"Expected: True")
    print(f"Got: {result4}")
    print()

    # Test case 5: Left-skewed tree
    root5 = build_tree([1, 2, None, 3])
    result5 = solution.isBalanced(root5)
    print(f"Test 5 - Input: [1,2,null,3]")
    print(f"Expected: False")
    print(f"Got: {result5}")
    print()

    # Test case 6: Balanced complete tree
    root6 = build_tree([1, 2, 3, 4, 5, 6, 7])
    result6 = solution.isBalanced(root6)
    print(f"Test 6 - Input: [1,2,3,4,5,6,7]")
    print(f"Expected: True")
    print(f"Got: {result6}")
    print()


if __name__ == "__main__":
    run_tests()
