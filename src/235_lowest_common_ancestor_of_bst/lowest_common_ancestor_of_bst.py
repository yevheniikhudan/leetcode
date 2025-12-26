"""
235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a
descendant of itself)."
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(
        self, root: TreeNode, p: TreeNode, q: TreeNode
    ) -> TreeNode:
        """
        Find the lowest common ancestor of two nodes in a BST.

        Args:
            root: Root of the BST
            p: First node
            q: Second node

        Returns:
            The lowest common ancestor node
        """
        if not root:
            return root

        if max(p.val, q.val) < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif min(p.val, q.val) > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root


# Test cases
def build_bst(values):
    """Helper function to build a BST from a list (level-order)."""
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


def find_node(root, val):
    """Helper to find a node with given value in the tree."""
    if not root:
        return None
    if root.val == val:
        return root

    left = find_node(root.left, val)
    if left:
        return left

    return find_node(root.right, val)


def run_tests():
    solution = Solution()

    # Test case 1: LCA of nodes in different subtrees
    print("Test 1: LCA of nodes in different subtrees (2, 8)")
    root1 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p1 = find_node(root1, 2)
    q1 = find_node(root1, 8)
    result1 = solution.lowestCommonAncestor(root1, p1, q1)
    print(f"Result: {result1.val if result1 else None}, Expected: 6")
    assert result1 and result1.val == 6, "Test 1 failed"

    # Test case 2: LCA where one node is ancestor of the other
    print("\nTest 2: LCA where one node is ancestor of the other (2, 4)")
    root2 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p2 = find_node(root2, 2)
    q2 = find_node(root2, 4)
    result2 = solution.lowestCommonAncestor(root2, p2, q2)
    print(f"Result: {result2.val if result2 else None}, Expected: 2")
    assert result2 and result2.val == 2, "Test 2 failed"

    # Test case 3: Small tree
    print("\nTest 3: Small tree (2, 1)")
    root3 = build_bst([2, 1])
    p3 = find_node(root3, 2)
    q3 = find_node(root3, 1)
    result3 = solution.lowestCommonAncestor(root3, p3, q3)
    print(f"Result: {result3.val if result3 else None}, Expected: 2")
    assert result3 and result3.val == 2, "Test 3 failed"

    # Test case 4: LCA of leaf nodes
    print("\nTest 4: LCA of leaf nodes (3, 5)")
    root4 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p4 = find_node(root4, 3)
    q4 = find_node(root4, 5)
    result4 = solution.lowestCommonAncestor(root4, p4, q4)
    print(f"Result: {result4.val if result4 else None}, Expected: 4")
    assert result4 and result4.val == 4, "Test 4 failed"

    # Test case 5: LCA in right subtree
    print("\nTest 5: LCA in right subtree (7, 9)")
    root5 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p5 = find_node(root5, 7)
    q5 = find_node(root5, 9)
    result5 = solution.lowestCommonAncestor(root5, p5, q5)
    print(f"Result: {result5.val if result5 else None}, Expected: 8")
    assert result5 and result5.val == 8, "Test 5 failed"

    # Test case 6: LCA is the root
    print("\nTest 6: LCA is the root (0, 9)")
    root6 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p6 = find_node(root6, 0)
    q6 = find_node(root6, 9)
    result6 = solution.lowestCommonAncestor(root6, p6, q6)
    print(f"Result: {result6.val if result6 else None}, Expected: 6")
    assert result6 and result6.val == 6, "Test 6 failed"

    # Test case 7: Adjacent nodes (parent-child)
    print("\nTest 7: Adjacent nodes (2, 0)")
    root7 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p7 = find_node(root7, 2)
    q7 = find_node(root7, 0)
    result7 = solution.lowestCommonAncestor(root7, p7, q7)
    print(f"Result: {result7.val if result7 else None}, Expected: 2")
    assert result7 and result7.val == 2, "Test 7 failed"

    # Test case 8: Root and child
    print("\nTest 8: Root and child (6, 8)")
    root8 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p8 = find_node(root8, 6)
    q8 = find_node(root8, 8)
    result8 = solution.lowestCommonAncestor(root8, p8, q8)
    print(f"Result: {result8.val if result8 else None}, Expected: 6")
    assert result8 and result8.val == 6, "Test 8 failed"

    # Test case 9: Deep nodes on same side
    print("\nTest 9: Deep nodes on same side (3, 4)")
    root9 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p9 = find_node(root9, 3)
    q9 = find_node(root9, 4)
    result9 = solution.lowestCommonAncestor(root9, p9, q9)
    print(f"Result: {result9.val if result9 else None}, Expected: 4")
    assert result9 and result9.val == 4, "Test 9 failed"

    # Test case 10: Reversed order (q, p instead of p, q)
    print("\nTest 10: Reversed order (8, 2)")
    root10 = build_bst([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    p10 = find_node(root10, 8)
    q10 = find_node(root10, 2)
    result10 = solution.lowestCommonAncestor(root10, p10, q10)
    print(f"Result: {result10.val if result10 else None}, Expected: 6")
    assert result10 and result10.val == 6, "Test 10 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    run_tests()
