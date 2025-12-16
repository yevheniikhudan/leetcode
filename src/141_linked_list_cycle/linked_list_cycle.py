"""
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

Return true if there is a cycle in the linked list. Otherwise, return false.

Difficulty: Easy
"""

# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Detect cycle in linked list using Floyd's Cycle Detection (Two Pointers).

        Args:
            head: Head of the linked list

        Returns:
            True if cycle exists, False otherwise

        Time Complexity: O(n) - visit each node at most once
        Space Complexity: O(1) - only two pointers
        """
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True

        return False

    def hasCycleHashSet(self, head: Optional[ListNode]) -> bool:
        """
        Detect cycle in linked list using hash set.

        Args:
            head: Head of the linked list

        Returns:
            True if cycle exists, False otherwise

        Time Complexity: O(n) - visit each node once
        Space Complexity: O(n) - store all visited nodes
        """
        seen = set()

        while head and head.next:
            if head.val in seen:
                return True

            seen.add(head.val)
            head = head.next

        return False


# Helper functions for testing
def create_cycle_list(values: list, pos: int) -> Optional[ListNode]:
    """
    Create a linked list with a cycle.
    pos: index where tail connects to (-1 for no cycle)
    """
    if not values:
        return None

    head = ListNode(values[0])
    curr = head
    cycle_node = head if pos == 0 else None

    for i in range(1, len(values)):
        curr.next = ListNode(values[i])
        curr = curr.next
        if i == pos:
            cycle_node = curr

    # Create cycle if pos is valid
    if pos >= 0 and cycle_node:
        curr.next = cycle_node

    return head


def test_linked_list_cycle():
    solution = Solution()

    # Test case 1: Example 1 - cycle at position 1
    head1 = create_cycle_list([3, 2, 0, -4], 1)
    result1 = solution.hasCycle(head1)
    print(f"Test 1 (Two Pointers): {result1} (expected: True)")

    # Test case 2: Example 2 - cycle at position 0
    head2 = create_cycle_list([1, 2], 0)
    result2 = solution.hasCycle(head2)
    print(f"Test 2 (Two Pointers): {result2} (expected: True)")

    # Test case 3: Example 3 - no cycle
    head3 = create_cycle_list([1], -1)
    result3 = solution.hasCycle(head3)
    print(f"Test 3 (Two Pointers): {result3} (expected: False)")

    # Test case 4: Empty list
    head4 = create_cycle_list([], -1)
    result4 = solution.hasCycle(head4)
    print(f"Test 4 (Two Pointers): {result4} (expected: False)")

    # Test case 5: Two nodes, no cycle
    head5 = create_cycle_list([1, 2], -1)
    result5 = solution.hasCycle(head5)
    print(f"Test 5 (Two Pointers): {result5} (expected: False)")

    # Test case 6: Single node with self-loop
    head6 = create_cycle_list([1], 0)
    result6 = solution.hasCycle(head6)
    print(f"Test 6 (Two Pointers): {result6} (expected: True)")

    # Test case 7: Large cycle
    head7 = create_cycle_list([1, 2, 3, 4, 5, 6], 2)
    result7 = solution.hasCycle(head7)
    print(f"Test 7 (Two Pointers): {result7} (expected: True)")

    # Test case 8: Cycle at end
    head8 = create_cycle_list([1, 2, 3, 4], 3)
    result8 = solution.hasCycle(head8)
    print(f"Test 8 (Two Pointers): {result8} (expected: True)")

    print("\n--- Hash Set Tests ---")

    # Test case 9: Hash set - cycle exists
    head9 = create_cycle_list([3, 2, 0, -4], 1)
    result9 = solution.hasCycleHashSet(head9)
    print(f"Test 9 (Hash Set): {result9} (expected: True)")

    # Test case 10: Hash set - no cycle
    head10 = create_cycle_list([1, 2, 3], -1)
    result10 = solution.hasCycleHashSet(head10)
    print(f"Test 10 (Hash Set): {result10} (expected: False)")

    # Test case 11: Hash set - empty list
    head11 = create_cycle_list([], -1)
    result11 = solution.hasCycleHashSet(head11)
    print(f"Test 11 (Hash Set): {result11} (expected: False)")

    # Test case 12: Hash set - single node with cycle
    head12 = create_cycle_list([1], 0)
    result12 = solution.hasCycleHashSet(head12)
    print(f"Test 12 (Hash Set): {result12} (expected: True)")


if __name__ == "__main__":
    test_linked_list_cycle()
