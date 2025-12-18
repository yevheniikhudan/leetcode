"""
143. Reorder List

You are given the head of a singly linked-list. Reorder the list to be in the form:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Difficulty: Medium
"""

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Reorder list in-place using three-step approach:
        1. Find middle
        2. Reverse second half
        3. Merge two halves

        Do not return anything, modify head in-place instead.

        Time Complexity: O(n) - three passes through the list
        Space Complexity: O(1) - only using pointers
        """
        slow, fast = head, head.next # initiate slow and fast pointers to find mid
        
        while fast and fast.next: # find mid
            slow = slow.next
            fast = fast.next.next
        
        prev = None # initiate head of the second reversed part
        curr = slow.next # initiate pointer to reverse second part
        slow.next = None # remove pointer to the second part
        
        while curr: # reverse second part
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        
        first, second = head, prev
        while second: # join 2 parts together
            next1, next2 = first.next, second.next
            first.next = second
            second.next = next1
            first, second = next1, next2


# Helper functions for testing
def list_to_array(head: Optional[ListNode]) -> list:
    """Convert linked list to array for easy comparison."""
    result = []
    curr = head
    while curr:
        result.append(curr.val)
        curr = curr.next
    return result


def array_to_list(arr: list) -> Optional[ListNode]:
    """Convert array to linked list for testing."""
    if not arr:
        return None
    head = ListNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head


def test_reorder_list():
    solution = Solution()

    # Test case 1: Example 1 - even length
    head1 = array_to_list([1, 2, 3, 4])
    solution.reorderList(head1)
    print(f"Test 1: {list_to_array(head1)} (expected: [1, 4, 2, 3])")

    # Test case 2: Example 2 - odd length
    head2 = array_to_list([1, 2, 3, 4, 5])
    solution.reorderList(head2)
    print(f"Test 2: {list_to_array(head2)} (expected: [1, 5, 2, 4, 3])")

    # Test case 3: Single node
    head3 = array_to_list([1])
    solution.reorderList(head3)
    print(f"Test 3: {list_to_array(head3)} (expected: [1])")

    # Test case 4: Two nodes
    head4 = array_to_list([1, 2])
    solution.reorderList(head4)
    print(f"Test 4: {list_to_array(head4)} (expected: [1, 2])")

    # Test case 5: Three nodes
    head5 = array_to_list([1, 2, 3])
    solution.reorderList(head5)
    print(f"Test 5: {list_to_array(head5)} (expected: [1, 3, 2])")

    # Test case 6: Six nodes
    head6 = array_to_list([1, 2, 3, 4, 5, 6])
    solution.reorderList(head6)
    print(f"Test 6: {list_to_array(head6)} (expected: [1, 6, 2, 5, 3, 4])")

    # Test case 7: Seven nodes
    head7 = array_to_list([1, 2, 3, 4, 5, 6, 7])
    solution.reorderList(head7)
    print(f"Test 7: {list_to_array(head7)} (expected: [1, 7, 2, 6, 3, 5, 4])")

    # Test case 8: Large even list
    head8 = array_to_list([1, 2, 3, 4, 5, 6, 7, 8])
    solution.reorderList(head8)
    print(f"Test 8: {list_to_array(head8)} (expected: [1, 8, 2, 7, 3, 6, 4, 5])")


if __name__ == "__main__":
    test_reorder_list()
