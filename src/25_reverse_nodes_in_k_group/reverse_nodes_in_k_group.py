"""
25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end,
should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Difficulty: Hard
"""

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """
        Reverse the nodes of the list k at a time.

        Args:
            head: Head of the linked list
            k: Number of nodes to reverse in each group

        Returns:
            Head of the modified list

        Time Complexity: O(n) where n is number of nodes
        Space Complexity: O(1) for iterative, O(n/k) for recursive
        """
        dummy = ListNode()
        dummy.next = head
        prev_segment_end = dummy

        while True:
            end = self.findKth(prev_segment_end, k)
            if not end:
                return dummy.next

            next_segment_head = end.next
            segment_head = prev_segment_end.next
            self.reverseSegment(segment_head, next_segment_head)
            segment_head.next = next_segment_head
            prev_segment_end.next = end
            prev_segment_end = segment_head

    def findKth(self, node: Optional[ListNode], k: int):
        while node and k > 0:
            node = node.next
            k -= 1

        return node

    def reverseSegment(self, curr: ListNode, next_segment: ListNode):
        prev = None
        while curr != next_segment:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next

        return prev


# Helper functions for testing
def list_to_array(head: Optional[ListNode]) -> list:
    """Convert linked list to array."""
    result = []
    curr = head
    while curr:
        result.append(curr.val)
        curr = curr.next
    return result


def array_to_list(arr: list) -> Optional[ListNode]:
    """Convert array to linked list."""
    if not arr:
        return None
    head = ListNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head


def test_reverse_k_group():
    solution = Solution()

    # Test case 1: Example 1 - k=2
    head1 = array_to_list([1, 2, 3, 4, 5])
    result1 = solution.reverseKGroup(head1, 2)
    print(f"Test 1: {list_to_array(result1)} (expected: [2, 1, 4, 3, 5])")

    # Test case 2: Example 2 - k=3
    head2 = array_to_list([1, 2, 3, 4, 5])
    result2 = solution.reverseKGroup(head2, 3)
    print(f"Test 2: {list_to_array(result2)} (expected: [3, 2, 1, 4, 5])")

    # Test case 3: k=1 (no change)
    head3 = array_to_list([1, 2, 3])
    result3 = solution.reverseKGroup(head3, 1)
    print(f"Test 3: {list_to_array(result3)} (expected: [1, 2, 3])")

    # Test case 4: k equals list length
    head4 = array_to_list([1, 2, 3])
    result4 = solution.reverseKGroup(head4, 3)
    print(f"Test 4: {list_to_array(result4)} (expected: [3, 2, 1])")

    # Test case 5: Single node
    head5 = array_to_list([1])
    result5 = solution.reverseKGroup(head5, 1)
    print(f"Test 5: {list_to_array(result5)} (expected: [1])")

    # Test case 6: Two nodes, k=2
    head6 = array_to_list([1, 2])
    result6 = solution.reverseKGroup(head6, 2)
    print(f"Test 6: {list_to_array(result6)} (expected: [2, 1])")

    # Test case 7: Exact multiple of k
    head7 = array_to_list([1, 2, 3, 4, 5, 6])
    result7 = solution.reverseKGroup(head7, 3)
    print(f"Test 7: {list_to_array(result7)} (expected: [3, 2, 1, 6, 5, 4])")

    # Test case 8: Large k
    head8 = array_to_list([1, 2, 3])
    result8 = solution.reverseKGroup(head8, 10)
    print(f"Test 8: {list_to_array(result8)} (expected: [1, 2, 3])")


if __name__ == "__main__":
    test_reverse_k_group()
