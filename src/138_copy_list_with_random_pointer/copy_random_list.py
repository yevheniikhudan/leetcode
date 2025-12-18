"""
138. Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer,
which could point to any node in the list, or null.

Construct a deep copy of the list.

Difficulty: Medium
"""

from typing import Optional


# Definition for a Node.
class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node], cache = {}) -> Optional[Node]:
        """
        Create a deep copy of a linked list with random pointers.

        Approach: Use a hash map to track old -> new node mappings
        1. First pass: Create all new nodes and map old -> new
        2. Second pass: Set next and random pointers using the map

        Time Complexity: O(n) - two passes through the list
        Space Complexity: O(n) - hash map to store node mappings
        """
        if head == None:
            return None
        
        if head in cache:
            return cache[head]
        
        copy = Node(head.val)
        cache[head] = copy
        copy.next = self.copyRandomList(head.next, cache)
        copy.random = cache[head.random] if head.random in cache else None
        
        return copy


# Helper functions for testing
def create_list_with_random(values: list) -> Optional[Node]:
    """
    Create a linked list with random pointers.
    values is a list of [val, random_index] pairs.
    """
    if not values:
        return None

    # Create all nodes first
    nodes = [Node(val) for val, _ in values]

    # Set next pointers
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]

    # Set random pointers
    for i, (_, random_idx) in enumerate(values):
        if random_idx is not None:
            nodes[i].random = nodes[random_idx]

    return nodes[0]


def list_to_array(head: Optional[Node]) -> list:
    """Convert linked list with random pointers to array representation."""
    if not head:
        return []

    # Map nodes to indices
    node_to_index = {}
    curr = head
    index = 0
    while curr:
        node_to_index[curr] = index
        curr = curr.next
        index += 1

    # Build result array
    result = []
    curr = head
    while curr:
        random_idx = node_to_index.get(curr.random) if curr.random else None
        result.append([curr.val, random_idx])
        curr = curr.next

    return result


def verify_deep_copy(original: Optional[Node], copied: Optional[Node]) -> bool:
    """Verify that the copy is a deep copy (no shared nodes)."""
    if original is None and copied is None:
        return True
    if original is None or copied is None:
        return False

    # Check that no nodes are shared
    original_nodes = set()
    curr = original
    while curr:
        original_nodes.add(id(curr))
        curr = curr.next

    curr = copied
    while curr:
        if id(curr) in original_nodes:
            return False
        curr = curr.next

    return True


def test_copy_random_list():
    solution = Solution()

    # Test case 1: Example 1 - complex random pointers
    head1 = create_list_with_random([[7, None], [13, 0], [11, 4], [10, 2], [1, 0]])
    result1 = solution.copyRandomList(head1)
    print(f"Test 1: {list_to_array(result1)}")
    print(f"  Expected: [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]]")
    print(f"  Deep copy: {verify_deep_copy(head1, result1)}")

    # Test case 2: Example 2 - simple case
    head2 = create_list_with_random([[1, 1], [2, 1]])
    result2 = solution.copyRandomList(head2)
    print(f"\nTest 2: {list_to_array(result2)}")
    print(f"  Expected: [[1, 1], [2, 1]]")
    print(f"  Deep copy: {verify_deep_copy(head2, result2)}")

    # Test case 3: Example 3 - some null random pointers
    head3 = create_list_with_random([[3, None], [3, 0], [3, None]])
    result3 = solution.copyRandomList(head3)
    print(f"\nTest 3: {list_to_array(result3)}")
    print(f"  Expected: [[3, None], [3, 0], [3, None]]")
    print(f"  Deep copy: {verify_deep_copy(head3, result3)}")

    # Test case 4: Empty list
    head4 = None
    result4 = solution.copyRandomList(head4)
    print(f"\nTest 4: {list_to_array(result4)}")
    print(f"  Expected: []")

    # Test case 5: Single node
    head5 = create_list_with_random([[1, None]])
    result5 = solution.copyRandomList(head5)
    print(f"\nTest 5: {list_to_array(result5)}")
    print(f"  Expected: [[1, None]]")
    print(f"  Deep copy: {verify_deep_copy(head5, result5)}")

    # Test case 6: Self-referencing random pointer
    head6 = create_list_with_random([[1, 0], [2, 1]])
    result6 = solution.copyRandomList(head6)
    print(f"\nTest 6: {list_to_array(result6)}")
    print(f"  Expected: [[1, 0], [2, 1]]")
    print(f"  Deep copy: {verify_deep_copy(head6, result6)}")


if __name__ == "__main__":
    test_copy_random_list()
