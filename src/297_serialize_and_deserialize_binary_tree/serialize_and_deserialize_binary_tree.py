"""
297. Serialize and Deserialize Binary Tree

Design an algorithm to serialize and deserialize a binary tree.
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        """
        Encodes a tree to a single string.
        """
        res = []

        def dfs(root):
            if not root:
                res.append("N")
                return

            res.append(str(root.val))
            dfs(root.left)
            dfs(root.right)

        dfs(root)
        return ",".join(res)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """
        Decodes your encoded data to tree.
        """
        nodes = data.split(",")
        idX = 0

        def dfs():
            nonlocal idX

            if nodes[idX] == "N":
                idX += 1
                return None

            root = TreeNode(int(nodes[idX]))
            idX += 1
            root.left = dfs()
            root.right = dfs()

            return root

        return dfs()


# Helper functions for testing


def build_tree(values: list) -> Optional[TreeNode]:
    """Build a binary tree from level-order list."""
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


def tree_to_list(root: Optional[TreeNode]) -> list:
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


def test_codec():
    codec = Codec()
    # Test case 1: Example tree
    print("Test 1: root = [1,2,3,null,null,4,5]")
    root1 = build_tree([1, 2, 3, None, None, 4, 5])
    data1 = codec.serialize(root1)
    result1 = codec.deserialize(data1)
    result_list1 = tree_to_list(result1)
    expected1 = [1, 2, 3, None, None, 4, 5]
    print(f"Result: {result_list1}")
    print(f"Expected: {expected1}")
    assert result_list1 == expected1, f"Test 1 failed"
    # Test case 2: Empty tree
    print("\nTest 2: root = []")
    root2 = build_tree([])
    data2 = codec.serialize(root2)
    result2 = codec.deserialize(data2)
    result_list2 = tree_to_list(result2)
    expected2 = []
    print(f"Result: {result_list2}")
    print(f"Expected: {expected2}")
    assert result_list2 == expected2, f"Test 2 failed"
    # Test case 3: Single node
    print("\nTest 3: root = [42]")
    root3 = build_tree([42])
    data3 = codec.serialize(root3)
    result3 = codec.deserialize(data3)
    result_list3 = tree_to_list(result3)
    expected3 = [42]
    print(f"Result: {result_list3}")
    print(f"Expected: {expected3}")
    assert result_list3 == expected3, f"Test 3 failed"
    # Test case 4: Left-skewed tree
    print("\nTest 4: root = [1,2,None,3,None,4]")
    root4 = build_tree([1, 2, None, 3, None, 4])
    data4 = codec.serialize(root4)
    result4 = codec.deserialize(data4)
    result_list4 = tree_to_list(result4)
    expected4 = [1, 2, None, 3, None, 4]
    print(f"Result: {result_list4}")
    print(f"Expected: {expected4}")
    assert result_list4 == expected4, f"Test 4 failed"
    # Test case 5: Right-skewed tree
    print("\nTest 5: root = [1,None,2,None,3,None,4]")
    root5 = build_tree([1, None, 2, None, 3, None, 4])
    data5 = codec.serialize(root5)
    result5 = codec.deserialize(data5)
    result_list5 = tree_to_list(result5)
    expected5 = [1, None, 2, None, 3, None, 4]
    print(f"Result: {result_list5}")
    print(f"Expected: {expected5}")
    assert result_list5 == expected5, f"Test 5 failed"
    print("\n✅ All tests passed!")


if __name__ == "__main__":
    test_codec()
