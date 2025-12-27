"""
98. Validate Binary Search Tree

Given the root of a binary tree, return true if it is a valid binary search tree,
otherwise return false.

A valid BST satisfies:
- Left subtree contains only nodes with keys less than node's key
- Right subtree contains only nodes with keys greater than node's key
- Both left and right subtrees are also BSTs
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        """
        Determine if a binary tree is a valid binary search tree.

        Args:
            root: The root of the binary tree

        Returns:
            True if the tree is a valid BST, False otherwise
        """

        def dfs(root, minVal, maxVal):
            if not root:
                return True

            if not (minVal < root.val < maxVal):
                return False

            return dfs(root.left, minVal, root.val) and dfs(
                root.right, root.val, maxVal
            )

        return dfs(root, float("-inf"), float("+inf"))


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

    # Test case 1: Valid BST
    print("Test 1: Valid BST [2,1,3]")
    root1 = build_tree([2, 1, 3])
    result1 = solution.isValidBST(root1)
    expected1 = True
    print(f"Result: {result1}")
    print(f"Expected: {expected1}")
    assert result1 == expected1, "Test 1 failed"

    # Test case 2: Invalid BST (left child greater than root)
    print("\nTest 2: Invalid BST [1,2,3]")
    root2 = build_tree([1, 2, 3])
    result2 = solution.isValidBST(root2)
    expected2 = False
    print(f"Result: {result2}")
    print(f"Expected: {expected2}")
    assert result2 == expected2, "Test 2 failed"

    # Test case 3: Invalid BST (right subtree has value less than root)
    print("\nTest 3: Invalid BST [5,1,4,null,null,3,6]")
    root3 = build_tree([5, 1, 4, None, None, 3, 6])
    result3 = solution.isValidBST(root3)
    expected3 = False
    print(f"Result: {result3}")
    print(f"Expected: {expected3}")
    assert result3 == expected3, "Test 3 failed"

    # Test case 4: Single node
    print("\nTest 4: Single node [1]")
    root4 = build_tree([1])
    result4 = solution.isValidBST(root4)
    expected4 = True
    print(f"Result: {result4}")
    print(f"Expected: {expected4}")
    assert result4 == expected4, "Test 4 failed"

    # Test case 5: Valid BST with negative values
    print("\nTest 5: Valid BST with negatives [0,-1,1]")
    root5 = build_tree([0, -1, 1])
    result5 = solution.isValidBST(root5)
    expected5 = True
    print(f"Result: {result5}")
    print(f"Expected: {expected5}")
    assert result5 == expected5, "Test 5 failed"

    # Test case 6: Invalid BST (duplicate value)
    print("\nTest 6: Invalid BST with duplicate [5,1,5]")
    root6 = build_tree([5, 1, 5])
    result6 = solution.isValidBST(root6)
    expected6 = False
    print(f"Result: {result6}")
    print(f"Expected: {expected6}")
    assert result6 == expected6, "Test 6 failed"

    # Test case 7: Valid larger BST
    print("\nTest 7: Valid BST [10,5,15,null,null,6,20]")
    root7 = build_tree([10, 5, 15, None, None, 6, 20])
    result7 = solution.isValidBST(root7)
    expected7 = False  # 6 is in right subtree of 10 but 6 < 10
    print(f"Result: {result7}")
    print(f"Expected: {expected7}")
    assert result7 == expected7, "Test 7 failed"

    # Test case 8: Left-skewed valid BST
    print("\nTest 8: Left-skewed BST [3,2,null,1]")
    root8 = build_tree([3, 2, None, 1])
    result8 = solution.isValidBST(root8)
    expected8 = True
    print(f"Result: {result8}")
    print(f"Expected: {expected8}")
    assert result8 == expected8, "Test 8 failed"

    # Test case 9: Right-skewed valid BST
    print("\nTest 9: Right-skewed BST [1,null,2,null,3]")
    root9 = build_tree([1, None, 2, None, 3])
    result9 = solution.isValidBST(root9)
    expected9 = True
    print(f"Result: {result9}")
    print(f"Expected: {expected9}")
    assert result9 == expected9, "Test 9 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
