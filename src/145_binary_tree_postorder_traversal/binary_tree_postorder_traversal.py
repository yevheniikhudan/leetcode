from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = []
        stack.append((root, False))

        while stack:
            node, visited = stack.pop()
            if visited:
                res.append(node.val)
            elif node:
                stack.append((node, True))
                stack.append((node.right, False))
                stack.append((node.left, False))

        return res


# Test scaffolding
if __name__ == "__main__":

    def build_tree(lst):
        if not lst:
            return None
        nodes = [TreeNode(val) if val is not None else None for val in lst]
        kids = nodes[::-1]
        root = kids.pop()
        for node in nodes:
            if node:
                if kids:
                    node.left = kids.pop()
                if kids:
                    node.right = kids.pop()
        return root

    sol = Solution()
    tests = [
        ([1, None, 2, 3], [3, 2, 1]),
        ([], []),
        ([1], [1]),
        ([1, 2, 3], [2, 3, 1]),
        ([1, None, 2], [2, 1]),
    ]
    for i, (tree, expected) in enumerate(tests, 1):
        root = build_tree(tree)
        result = sol.postorderTraversal(root)
        print(f"Test {i}: {result} | {expected}")
