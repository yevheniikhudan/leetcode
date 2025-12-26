"""
100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        """
        Check if two binary trees are the same.

        Args:
            p: Root of first binary tree
            q: Root of second binary tree

        Returns:
            True if trees are identical in structure and values, False otherwise
        """
        # Base case: if either is None, both must be None for equality
        if not p or not q:
            return p == q
        
        # Check current node values first (early exit optimization)
        if p.val != q.val:
            return False
        
        # Recursively check both subtrees
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


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

    # Test case 1: Both trees identical [1,2,3]
    print("Test 1: Both trees [1,2,3]")
    p1 = build_tree([1, 2, 3])
    q1 = build_tree([1, 2, 3])
    result1 = solution.isSameTree(p1, q1)
    print(f"Result: {result1}, Expected: True")
    assert result1 == True, "Test 1 failed"

    # Test case 2: Different structure [1,2] vs [1,null,2]
    print("\nTest 2: Different structure [1,2] vs [1,null,2]")
    p2 = build_tree([1, 2])
    q2 = build_tree([1, None, 2])
    result2 = solution.isSameTree(p2, q2)
    print(f"Result: {result2}, Expected: False")
    assert result2 == False, "Test 2 failed"

    # Test case 3: Different values [1,2,1] vs [1,1,2]
    print("\nTest 3: Different values [1,2,1] vs [1,1,2]")
    p3 = build_tree([1, 2, 1])
    q3 = build_tree([1, 1, 2])
    result3 = solution.isSameTree(p3, q3)
    print(f"Result: {result3}, Expected: False")
    assert result3 == False, "Test 3 failed"

    # Test case 4: Both empty trees
    print("\nTest 4: Both empty trees")
    p4 = None
    q4 = None
    result4 = solution.isSameTree(p4, q4)
    print(f"Result: {result4}, Expected: True")
    assert result4 == True, "Test 4 failed"

    # Test case 5: One empty, one not
    print("\nTest 5: One empty [1] vs []")
    p5 = build_tree([1])
    q5 = None
    result5 = solution.isSameTree(p5, q5)
    print(f"Result: {result5}, Expected: False")
    assert result5 == False, "Test 5 failed"

    # Test case 6: Single nodes with same value
    print("\nTest 6: Single nodes both [1]")
    p6 = build_tree([1])
    q6 = build_tree([1])
    result6 = solution.isSameTree(p6, q6)
    print(f"Result: {result6}, Expected: True")
    assert result6 == True, "Test 6 failed"

    # Test case 7: Single nodes with different values
    print("\nTest 7: Single nodes [1] vs [2]")
    p7 = build_tree([1])
    q7 = build_tree([2])
    result7 = solution.isSameTree(p7, q7)
    print(f"Result: {result7}, Expected: False")
    assert result7 == False, "Test 7 failed"

    # Test case 8: Larger identical trees
    print("\nTest 8: Larger identical trees")
    p8 = build_tree([1, 2, 3, 4, 5, 6, 7])
    q8 = build_tree([1, 2, 3, 4, 5, 6, 7])
    result8 = solution.isSameTree(p8, q8)
    print(f"Result: {result8}, Expected: True")
    assert result8 == True, "Test 8 failed"

    # Test case 9: Different at leaf level
    print("\nTest 9: Different at leaf level")
    p9 = build_tree([1, 2, 3, 4, 5, 6, 7])
    q9 = build_tree([1, 2, 3, 4, 5, 6, 8])
    result9 = solution.isSameTree(p9, q9)
    print(f"Result: {result9}, Expected: False")
    assert result9 == False, "Test 9 failed"

    # Test case 10: Different tree sizes
    print("\nTest 10: Different tree sizes")
    p10 = build_tree([1, 2, 3])
    q10 = build_tree([1, 2, 3, 4])
    result10 = solution.isSameTree(p10, q10)
    print(f"Result: {result10}, Expected: False")
    assert result10 == False, "Test 10 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
