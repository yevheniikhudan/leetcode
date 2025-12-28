"""
105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder
traversal of a binary tree and inorder is the inorder traversal of the same tree,
construct and return the binary tree.
"""

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
        Construct binary tree from preorder and inorder traversals.

        Args:
            preorder: Preorder traversal of the tree
            inorder: Inorder traversal of the tree

        Returns:
            Root of the constructed binary tree
        """
        indices = {val: index for index, val in enumerate(inorder)}
        preId = 0

        def dfs(left, right):
            nonlocal preId
            if left > right:
                return None

            root = TreeNode(preorder[preId])
            mid = indices[root.val]
            preId += 1

            root.left = dfs(left, mid - 1)
            root.right = dfs(mid + 1, right)

            return root

        return dfs(0, len(inorder) - 1)


def tree_to_list(root: Optional[TreeNode]) -> List[Optional[int]]:
    """Convert tree to level-order list representation."""
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        node = queue.pop(0)
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


def test_build_tree():
    """Test cases for buildTree."""
    solution = Solution()

    # Test case 1: Example tree
    print("Test 1: preorder=[3,9,20,15,7], inorder=[9,3,15,20,7]")
    preorder1 = [3, 9, 20, 15, 7]
    inorder1 = [9, 3, 15, 20, 7]
    result1 = solution.buildTree(preorder1, inorder1)
    result_list1 = tree_to_list(result1)
    expected1 = [3, 9, 20, None, None, 15, 7]
    print(f"Result: {result_list1}")
    print(f"Expected: {expected1}")
    assert result_list1 == expected1, f"Test 1 failed"

    # Test case 2: Single node
    print("\nTest 2: preorder=[-1], inorder=[-1]")
    preorder2 = [-1]
    inorder2 = [-1]
    result2 = solution.buildTree(preorder2, inorder2)
    result_list2 = tree_to_list(result2)
    expected2 = [-1]
    print(f"Result: {result_list2}")
    print(f"Expected: {expected2}")
    assert result_list2 == expected2, f"Test 2 failed"

    # Test case 3: Left-skewed tree
    print("\nTest 3: preorder=[1,2,3], inorder=[3,2,1]")
    preorder3 = [1, 2, 3]
    inorder3 = [3, 2, 1]
    result3 = solution.buildTree(preorder3, inorder3)
    result_list3 = tree_to_list(result3)
    expected3 = [1, 2, None, 3]
    print(f"Result: {result_list3}")
    print(f"Expected: {expected3}")
    assert result_list3 == expected3, f"Test 3 failed"

    # Test case 4: Right-skewed tree
    print("\nTest 4: preorder=[1,2,3], inorder=[1,2,3]")
    preorder4 = [1, 2, 3]
    inorder4 = [1, 2, 3]
    result4 = solution.buildTree(preorder4, inorder4)
    result_list4 = tree_to_list(result4)
    expected4 = [1, None, 2, None, 3]
    print(f"Result: {result_list4}")
    print(f"Expected: {expected4}")
    assert result_list4 == expected4, f"Test 4 failed"

    # Test case 5: Balanced tree
    print("\nTest 5: preorder=[1,2,4,5,3,6,7], inorder=[4,2,5,1,6,3,7]")
    preorder5 = [1, 2, 4, 5, 3, 6, 7]
    inorder5 = [4, 2, 5, 1, 6, 3, 7]
    result5 = solution.buildTree(preorder5, inorder5)
    result_list5 = tree_to_list(result5)
    expected5 = [1, 2, 3, 4, 5, 6, 7]
    print(f"Result: {result_list5}")
    print(f"Expected: {expected5}")
    assert result_list5 == expected5, f"Test 5 failed"

    # Test case 6: Two nodes (left child)
    print("\nTest 6: preorder=[1,2], inorder=[2,1]")
    preorder6 = [1, 2]
    inorder6 = [2, 1]
    result6 = solution.buildTree(preorder6, inorder6)
    result_list6 = tree_to_list(result6)
    expected6 = [1, 2]
    print(f"Result: {result_list6}")
    print(f"Expected: {expected6}")
    assert result_list6 == expected6, f"Test 6 failed"

    # Test case 7: Two nodes (right child)
    print("\nTest 7: preorder=[1,2], inorder=[1,2]")
    preorder7 = [1, 2]
    inorder7 = [1, 2]
    result7 = solution.buildTree(preorder7, inorder7)
    result_list7 = tree_to_list(result7)
    expected7 = [1, None, 2]
    print(f"Result: {result_list7}")
    print(f"Expected: {expected7}")
    assert result_list7 == expected7, f"Test 7 failed"

    # Test case 8: Larger unbalanced tree
    print("\nTest 8: preorder=[3,9,8,5,20,15,7], inorder=[8,9,5,3,15,20,7]")
    preorder8 = [3, 9, 8, 5, 20, 15, 7]
    inorder8 = [8, 9, 5, 3, 15, 20, 7]
    result8 = solution.buildTree(preorder8, inorder8)
    result_list8 = tree_to_list(result8)
    expected8 = [3, 9, 20, 8, 5, 15, 7]
    print(f"Result: {result_list8}")
    print(f"Expected: {expected8}")
    assert result_list8 == expected8, f"Test 8 failed"

    print("\n✅ All tests passed!")


if __name__ == "__main__":
    test_build_tree()
