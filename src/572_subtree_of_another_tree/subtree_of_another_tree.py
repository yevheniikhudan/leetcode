"""
572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a subtree
of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of
this node's descendants. The tree tree could also be considered as a subtree of itself.
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        """
        Check if subRoot is a subtree of root.

        Args:
            root: Root of the main binary tree
            subRoot: Root of the potential subtree

        Returns:
            True if subRoot is a subtree of root, False otherwise
        """

        if not root:
            return False

        def isSameTree(a, b):
            if not a or not b:
                return a == b

            if a.val != b.val:
                return False

            return isSameTree(a.left, b.left) and isSameTree(a.right, b.right)

        if isSameTree(root, subRoot):
            return True

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)


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

    # Test case 1: subRoot is subtree at left child
    print("Test 1: subRoot is subtree at left child")
    root1 = build_tree([3, 4, 5, 1, 2])
    subRoot1 = build_tree([4, 1, 2])
    result1 = solution.isSubtree(root1, subRoot1)
    print(f"Result: {result1}, Expected: True")
    assert result1 == True, "Test 1 failed"

    # Test case 2: Extra node in root's subtree
    print("\nTest 2: Extra node in root's subtree")
    root2 = build_tree([3, 4, 5, 1, 2, None, None, None, None, 0])
    subRoot2 = build_tree([4, 1, 2])
    result2 = solution.isSubtree(root2, subRoot2)
    print(f"Result: {result2}, Expected: False")
    assert result2 == False, "Test 2 failed"

    # Test case 3: subRoot equals entire root
    print("\nTest 3: subRoot equals entire root")
    root3 = build_tree([1, 2, 3])
    subRoot3 = build_tree([1, 2, 3])
    result3 = solution.isSubtree(root3, subRoot3)
    print(f"Result: {result3}, Expected: True")
    assert result3 == True, "Test 3 failed"

    # Test case 4: Single node trees, matching
    print("\nTest 4: Single node trees, matching")
    root4 = build_tree([1])
    subRoot4 = build_tree([1])
    result4 = solution.isSubtree(root4, subRoot4)
    print(f"Result: {result4}, Expected: True")
    assert result4 == True, "Test 4 failed"

    # Test case 5: Single node trees, not matching
    print("\nTest 5: Single node trees, not matching")
    root5 = build_tree([1])
    subRoot5 = build_tree([2])
    result5 = solution.isSubtree(root5, subRoot5)
    print(f"Result: {result5}, Expected: False")
    assert result5 == False, "Test 5 failed"

    # Test case 6: subRoot at right child
    print("\nTest 6: subRoot at right child")
    root6 = build_tree([3, 4, 5, 1, 2])
    subRoot6 = build_tree([5])
    result6 = solution.isSubtree(root6, subRoot6)
    print(f"Result: {result6}, Expected: True")
    assert result6 == True, "Test 6 failed"

    # Test case 7: subRoot is leaf node
    print("\nTest 7: subRoot is leaf node")
    root7 = build_tree([3, 4, 5, 1, 2])
    subRoot7 = build_tree([2])
    result7 = solution.isSubtree(root7, subRoot7)
    print(f"Result: {result7}, Expected: True")
    assert result7 == True, "Test 7 failed"

    # Test case 8: Similar structure but different values
    print("\nTest 8: Similar structure but different values")
    root8 = build_tree([3, 4, 5, 1, 2])
    subRoot8 = build_tree([4, 1, 3])
    result8 = solution.isSubtree(root8, subRoot8)
    print(f"Result: {result8}, Expected: False")
    assert result8 == False, "Test 8 failed"

    # Test case 9: subRoot larger than root
    print("\nTest 9: subRoot larger than root")
    root9 = build_tree([1, 2])
    subRoot9 = build_tree([1, 2, 3])
    result9 = solution.isSubtree(root9, subRoot9)
    print(f"Result: {result9}, Expected: False")
    assert result9 == False, "Test 9 failed"

    # Test case 10: Complex tree, subRoot deep inside
    print("\nTest 10: Complex tree, subRoot deep inside")
    root10 = build_tree([1, 2, 3, 4, 5, 6, 7, 8, 9])
    subRoot10 = build_tree([4, 8, 9])
    result10 = solution.isSubtree(root10, subRoot10)
    print(f"Result: {result10}, Expected: True")
    assert result10 == True, "Test 10 failed"

    # Test case 11: Partial match (substring-like scenario)
    print("\nTest 11: Value appears but not as subtree")
    root11 = build_tree([12])
    subRoot11 = build_tree([2])
    result11 = solution.isSubtree(root11, subRoot11)
    print(f"Result: {result11}, Expected: False")
    assert result11 == False, "Test 11 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
