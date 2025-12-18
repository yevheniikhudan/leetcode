"""
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Difficulty: Medium
"""

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """
        Remove nth node from end using two-pointer technique with dummy node.

        Approach:
        1. Use dummy node to handle edge case of removing head
        2. Use two pointers with n gap between them
        3. Move both until fast reaches end
        4. Remove the node after slow pointer

        Time Complexity: O(L) where L is the length of the list
        Space Complexity: O(1) - only using pointers
        """
        
        dummy = ListNode()
        dummy.next = head
        slow = dummy
        fast = dummy
        
        while n > 0:
            fast = fast.next
            n -= 1
            
        while fast.next:
            slow = slow.next
            fast = fast.next
            
        slow.next = slow.next.next
        
        return dummy.next


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


def test_remove_nth_from_end():
    solution = Solution()

    # Test case 1: Remove 2nd from end
    head1 = array_to_list([1, 2, 3, 4, 5])
    result1 = solution.removeNthFromEnd(head1, 2)
    print(f"Test 1: {list_to_array(result1)} (expected: [1, 2, 3, 5])")

    # Test case 2: Remove only node
    head2 = array_to_list([1])
    result2 = solution.removeNthFromEnd(head2, 1)
    print(f"Test 2: {list_to_array(result2)} (expected: [])")

    # Test case 3: Remove first of two nodes
    head3 = array_to_list([1, 2])
    result3 = solution.removeNthFromEnd(head3, 1)
    print(f"Test 3: {list_to_array(result3)} (expected: [1])")

    # Test case 4: Remove last node (head)
    head4 = array_to_list([1, 2])
    result4 = solution.removeNthFromEnd(head4, 2)
    print(f"Test 4: {list_to_array(result4)} (expected: [2])")

    # Test case 5: Remove from middle
    head5 = array_to_list([1, 2, 3, 4, 5])
    result5 = solution.removeNthFromEnd(head5, 3)
    print(f"Test 5: {list_to_array(result5)} (expected: [1, 2, 4, 5])")

    # Test case 6: Remove first node (last from end)
    head6 = array_to_list([1, 2, 3, 4, 5])
    result6 = solution.removeNthFromEnd(head6, 5)
    print(f"Test 6: {list_to_array(result6)} (expected: [2, 3, 4, 5])")

    # Test case 7: Remove last node
    head7 = array_to_list([1, 2, 3, 4, 5])
    result7 = solution.removeNthFromEnd(head7, 1)
    print(f"Test 7: {list_to_array(result7)} (expected: [1, 2, 3, 4])")


if __name__ == "__main__":
    test_remove_nth_from_end()
