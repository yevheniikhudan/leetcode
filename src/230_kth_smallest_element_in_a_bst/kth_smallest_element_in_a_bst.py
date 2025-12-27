"""
230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth
smallest value (1-indexed) of all the values of the nodes in the tree.
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
        Find the kth smallest element in a BST.

        Args:
            root: The root of the binary search tree
            k: The k value (1-indexed)

        Returns:
            The kth smallest value in the BST
        """
        inorder = []

        def dfs(root):
            if not root:
                return

            if len(inorder) == k:
                return

            dfs(root.left)
            inorder.append(root.val)
            dfs(root.right)

        dfs(root)

        return inorder[k - 1]


# Test cases
def build_tree(values: list[Optional[int]]) -> Optional[TreeNode]:
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

    # Test case 1: k=1 (smallest element)
    print("Test 1: BST [3,1,4,null,2], k=1")
    root1 = build_tree([3, 1, 4, None, 2])
    result1 = solution.kthSmallest(root1, 1)
    expected1 = 1
    print(f"Result: {result1}")
    print(f"Expected: {expected1}")
    assert result1 == expected1, "Test 1 failed"

    # Test case 2: k=3 (middle element)
    print("\nTest 2: BST [5,3,6,2,4,null,null,1], k=3")
    root2 = build_tree([5, 3, 6, 2, 4, None, None, 1])
    result2 = solution.kthSmallest(root2, 3)
    expected2 = 3
    print(f"Result: {result2}")
    print(f"Expected: {expected2}")
    assert result2 == expected2, "Test 2 failed"

    # Test case 3: Single node, k=1
    print("\nTest 3: BST [1], k=1")
    root3 = build_tree([1])
    result3 = solution.kthSmallest(root3, 1)
    expected3 = 1
    print(f"Result: {result3}")
    print(f"Expected: {expected3}")
    assert result3 == expected3, "Test 3 failed"

    # Test case 4: Two nodes, k=2
    print("\nTest 4: BST [2,1], k=2")
    root4 = build_tree([2, 1])
    result4 = solution.kthSmallest(root4, 2)
    expected4 = 2
    print(f"Result: {result4}")
    print(f"Expected: {expected4}")
    assert result4 == expected4, "Test 4 failed"

    # Test case 5: Right-skewed tree, k=3
    print("\nTest 5: BST [1,null,2,null,3,null,4], k=3")
    root5 = build_tree([1, None, 2, None, 3, None, 4])
    result5 = solution.kthSmallest(root5, 3)
    expected5 = 3
    print(f"Result: {result5}")
    print(f"Expected: {expected5}")
    assert result5 == expected5, "Test 5 failed"

    # Test case 6: Left-skewed tree, k=2
    print("\nTest 6: BST [4,3,null,2,null,1], k=2")
    root6 = build_tree([4, 3, None, 2, None, 1])
    result6 = solution.kthSmallest(root6, 2)
    expected6 = 2
    print(f"Result: {result6}")
    print(f"Expected: {expected6}")
    assert result6 == expected6, "Test 6 failed"

    # Test case 7: Balanced tree, k=4
    print("\nTest 7: BST [4,2,6,1,3,5,7], k=4")
    root7 = build_tree([4, 2, 6, 1, 3, 5, 7])
    result7 = solution.kthSmallest(root7, 4)
    expected7 = 4
    print(f"Result: {result7}")
    print(f"Expected: {expected7}")
    assert result7 == expected7, "Test 7 failed"

    # Test case 8: Last element (maximum)
    print("\nTest 8: BST [3,1,4,null,2], k=4")
    root8 = build_tree([3, 1, 4, None, 2])
    result8 = solution.kthSmallest(root8, 4)
    expected8 = 4
    print(f"Result: {result8}")
    print(f"Expected: {expected8}")
    assert result8 == expected8, "Test 8 failed"

    # Test case 9: Large tree, k=5
    print("\nTest 9: BST [10,5,15,3,7,null,18,1,4,6,8], k=5")
    root9 = build_tree([10, 5, 15, 3, 7, None, 18, 1, 4, 6, 8])
    result9 = solution.kthSmallest(root9, 5)
    expected9 = 6  # Inorder: [1,3,4,5,6,7,8,10,15,18], 5th = 6
    print(f"Result: {result9}")
    print(f"Expected: {expected9}")
    assert result9 == expected9, "Test 9 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
