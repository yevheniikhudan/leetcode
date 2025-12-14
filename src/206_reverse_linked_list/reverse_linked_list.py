"""
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Difficulty: Easy
"""

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Reverse a singly linked list iteratively.

        Args:
            head: Head of the linked list

        Returns:
            Head of the reversed linked list

        Time Complexity: O(n) - visit each node once
        Space Complexity: O(1) - only use three pointers
        """
        prev = None
        curr = head
        
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        
        return prev

    def reverseListRecursive(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Reverse a singly linked list recursively.

        Args:
            head: Head of the linked list

        Returns:
            Head of the reversed linked list

        Time Complexity: O(n) - visit each node once
        Space Complexity: O(n) - recursive call stack
        """
        if not head or not head.next:
            return head
        
        new_head = self.reverseListRecursive(head.next)
        
        head.next.next = head
        head.next = None
        
        return new_head


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


def test_reverse_linked_list():
    solution = Solution()

    # Test case 1: Example 1 - regular list
    head1 = array_to_list([1, 2, 3, 4, 5])
    result1 = solution.reverseList(head1)
    print(f"Test 1 (Iterative): {list_to_array(result1)} (expected: [5, 4, 3, 2, 1])")

    # Test case 2: Example 2 - two nodes
    head2 = array_to_list([1, 2])
    result2 = solution.reverseList(head2)
    print(f"Test 2 (Iterative): {list_to_array(result2)} (expected: [2, 1])")

    # Test case 3: Example 3 - empty list
    head3 = array_to_list([])
    result3 = solution.reverseList(head3)
    print(f"Test 3 (Iterative): {list_to_array(result3)} (expected: [])")

    # Test case 4: Single node
    head4 = array_to_list([1])
    result4 = solution.reverseList(head4)
    print(f"Test 4 (Iterative): {list_to_array(result4)} (expected: [1])")

    # Test case 5: Three nodes
    head5 = array_to_list([1, 2, 3])
    result5 = solution.reverseList(head5)
    print(f"Test 5 (Iterative): {list_to_array(result5)} (expected: [3, 2, 1])")

    print("\n--- Recursive Tests ---")

    # Test case 6: Recursive - regular list
    head6 = array_to_list([1, 2, 3, 4, 5])
    result6 = solution.reverseListRecursive(head6)
    print(f"Test 6 (Recursive): {list_to_array(result6)} (expected: [5, 4, 3, 2, 1])")

    # Test case 7: Recursive - two nodes
    head7 = array_to_list([1, 2])
    result7 = solution.reverseListRecursive(head7)
    print(f"Test 7 (Recursive): {list_to_array(result7)} (expected: [2, 1])")

    # Test case 8: Recursive - empty list
    head8 = array_to_list([])
    result8 = solution.reverseListRecursive(head8)
    print(f"Test 8 (Recursive): {list_to_array(result8)} (expected: [])")

    # Test case 9: Recursive - single node
    head9 = array_to_list([1])
    result9 = solution.reverseListRecursive(head9)
    print(f"Test 9 (Recursive): {list_to_array(result9)} (expected: [1])")

    # Test case 10: Recursive - three nodes
    head10 = array_to_list([1, 2, 3])
    result10 = solution.reverseListRecursive(head10)
    print(f"Test 10 (Recursive): {list_to_array(result10)} (expected: [3, 2, 1])")


if __name__ == "__main__":
    test_reverse_linked_list()
