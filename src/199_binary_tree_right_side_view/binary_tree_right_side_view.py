"""
199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.
"""

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        """
        Returns the values of nodes visible from the right side of the tree.

        Args:
            root: The root of the binary tree

        Returns:
            List of values visible from the right side, ordered top to bottom
        """
        queue = deque()
        res = []

        if root:
            queue.append(root)

        while queue:
            levelSize = len(queue)

            for i in range(levelSize):
                cur = queue.popleft()

                if i == levelSize - 1:
                    res.append(cur.val)
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)

        return res


# Test cases
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

    # Test case 1: Standard example with left nodes visible
    print("Test 1: Tree [1,2,3,null,5,null,4]")
    root1 = build_tree([1, 2, 3, None, 5, None, 4])
    result1 = solution.rightSideView(root1)
    expected1 = [1, 3, 4]
    print(f"Result: {result1}")
    print(f"Expected: {expected1}")
    assert result1 == expected1, "Test 1 failed"

    # Test case 2: Left-skewed tree visible from right
    print("\nTest 2: Tree [1,2,3,4,null,null,null,5]")
    root2 = build_tree([1, 2, 3, 4, None, None, None, 5])
    result2 = solution.rightSideView(root2)
    expected2 = [1, 3, 4, 5]
    print(f"Result: {result2}")
    print(f"Expected: {expected2}")
    assert result2 == expected2, "Test 2 failed"

    # Test case 3: Only right children
    print("\nTest 3: Tree [1,null,3]")
    root3 = build_tree([1, None, 3])
    result3 = solution.rightSideView(root3)
    expected3 = [1, 3]
    print(f"Result: {result3}")
    print(f"Expected: {expected3}")
    assert result3 == expected3, "Test 3 failed"

    # Test case 4: Empty tree
    print("\nTest 4: Empty tree")
    root4 = None
    result4 = solution.rightSideView(root4)
    expected4 = []
    print(f"Result: {result4}")
    print(f"Expected: {expected4}")
    assert result4 == expected4, "Test 4 failed"

    # Test case 5: Single node
    print("\nTest 5: Single node [1]")
    root5 = build_tree([1])
    result5 = solution.rightSideView(root5)
    expected5 = [1]
    print(f"Result: {result5}")
    print(f"Expected: {expected5}")
    assert result5 == expected5, "Test 5 failed"

    # Test case 6: Complete binary tree
    print("\nTest 6: Complete tree [1,2,3,4,5,6,7]")
    root6 = build_tree([1, 2, 3, 4, 5, 6, 7])
    result6 = solution.rightSideView(root6)
    expected6 = [1, 3, 7]
    print(f"Result: {result6}")
    print(f"Expected: {expected6}")
    assert result6 == expected6, "Test 6 failed"

    # Test case 7: Only left children
    print("\nTest 7: Left-skewed tree [1,2,null,3,null,4]")
    root7 = build_tree([1, 2, None, 3, None, 4])
    result7 = solution.rightSideView(root7)
    expected7 = [1, 2, 3, 4]
    print(f"Result: {result7}")
    print(f"Expected: {expected7}")
    assert result7 == expected7, "Test 7 failed"

    # Test case 8: Zigzag pattern
    print("\nTest 8: Zigzag pattern [1,2,3,null,5,null,4,null,6]")
    root8 = build_tree([1, 2, 3, None, 5, None, 4, None, 6])
    result8 = solution.rightSideView(root8)
    expected8 = [1, 3, 4, 6]
    print(f"Result: {result8}")
    print(f"Expected: {expected8}")
    assert result8 == expected8, "Test 8 failed"

    # Test case 9: Two nodes (left child only)
    print("\nTest 9: Two nodes [1,2]")
    root9 = build_tree([1, 2])
    result9 = solution.rightSideView(root9)
    expected9 = [1, 2]
    print(f"Result: {result9}")
    print(f"Expected: {expected9}")
    assert result9 == expected9, "Test 9 failed"

    # Test case 10: Two nodes (right child only)
    print("\nTest 10: Two nodes [1,null,2]")
    root10 = build_tree([1, None, 2])
    result10 = solution.rightSideView(root10)
    expected10 = [1, 2]
    print(f"Result: {result10}")
    print(f"Expected: {expected10}")
    assert result10 == expected10, "Test 10 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
