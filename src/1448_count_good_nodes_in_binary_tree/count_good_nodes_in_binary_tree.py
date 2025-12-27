"""
1448. Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path
from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        """
        Count the number of good nodes in the binary tree.

        A node is "good" if in the path from root to that node,
        there are no nodes with a value greater than it.

        Args:
            root: The root of the binary tree

        Returns:
            The number of good nodes in the tree
        """
        if not root:
            return 0

        def countGoodNodes(root, maxVal):
            if not root:
                return 0

            count = 1 if root.val >= maxVal else 0
            newMax = max(maxVal, root.val)
            count += countGoodNodes(root.left, newMax)
            count += countGoodNodes(root.right, newMax)

            return count

        return countGoodNodes(root, root.val)


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

    # Test case 1: Standard example with mix of good and bad nodes
    print("Test 1: Tree [3,1,4,3,null,1,5]")
    root1 = build_tree([3, 1, 4, 3, None, 1, 5])
    result1 = solution.goodNodes(root1)
    expected1 = 4
    print(f"Result: {result1}")
    print(f"Expected: {expected1}")
    assert result1 == expected1, "Test 1 failed"

    # Test case 2: Tree where not all nodes are good
    print("\nTest 2: Tree [3,3,null,4,2]")
    root2 = build_tree([3, 3, None, 4, 2])
    result2 = solution.goodNodes(root2)
    expected2 = 3
    print(f"Result: {result2}")
    print(f"Expected: {expected2}")
    assert result2 == expected2, "Test 2 failed"

    # Test case 3: Single node
    print("\nTest 3: Single node [1]")
    root3 = build_tree([1])
    result3 = solution.goodNodes(root3)
    expected3 = 1
    print(f"Result: {result3}")
    print(f"Expected: {expected3}")
    assert result3 == expected3, "Test 3 failed"

    # Test case 4: All nodes equal (all should be good)
    print("\nTest 4: All equal values [2,2,2,2,2]")
    root4 = build_tree([2, 2, 2, 2, 2])
    result4 = solution.goodNodes(root4)
    expected4 = 5
    print(f"Result: {result4}")
    print(f"Expected: {expected4}")
    assert result4 == expected4, "Test 4 failed"

    # Test case 5: Strictly increasing (all good)
    print("\nTest 5: Strictly increasing [1,2,3,4,5]")
    root5 = build_tree([1, 2, 3, 4, 5])
    result5 = solution.goodNodes(root5)
    expected5 = 5
    print(f"Result: {result5}")
    print(f"Expected: {expected5}")
    assert result5 == expected5, "Test 5 failed"

    # Test case 6: Strictly decreasing (only root good)
    print("\nTest 6: Strictly decreasing [5,4,3,2,1]")
    root6 = build_tree([5, 4, 3, 2, 1])
    result6 = solution.goodNodes(root6)
    expected6 = 1
    print(f"Result: {result6}")
    print(f"Expected: {expected6}")
    assert result6 == expected6, "Test 6 failed"

    # Test case 7: Negative values
    print("\nTest 7: With negative values [-1,5,-2,4,null,null,8]")
    root7 = build_tree([-1, 5, -2, 4, None, None, 8])
    result7 = solution.goodNodes(root7)
    expected7 = 3
    print(f"Result: {result7}")
    print(f"Expected: {expected7}")
    assert result7 == expected7, "Test 7 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
