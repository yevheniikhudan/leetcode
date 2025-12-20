"""
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Difficulty: Medium
"""

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        """
        Add two numbers represented as linked lists in reverse order.

        Approach:
        1. Traverse both lists simultaneously
        2. Add corresponding digits plus carry
        3. Create new node with sum % 10
        4. Update carry as sum // 10
        5. Handle remaining carry at the end

        Time Complexity: O(max(m, n)) where m, n are lengths of lists
        Space Complexity: O(max(m, n)) for the result list
        """

        def add(
            l1: Optional[ListNode], l2: Optional[ListNode], carry: int
        ) -> Optional[ListNode]:
            if not l1 and not l2 and carry == 0:
                return None

            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0

            val = l1_val + l2_val + carry
            carry = val // 10
            val %= 10

            next_node = add(l1.next if l1 else None, l2.next if l2 else None, carry)
            return ListNode(val, next_node)

        return add(l1, l2, 0)


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


def test_add_two_numbers():
    solution = Solution()

    # Test case 1: Example 1 - basic addition
    l1 = array_to_list([2, 4, 3])
    l2 = array_to_list([5, 6, 4])
    result1 = solution.addTwoNumbers(l1, l2)
    print(f"Test 1: {list_to_array(result1)} (expected: [7, 0, 8])")

    # Test case 2: Example 2 - both zero
    l1 = array_to_list([0])
    l2 = array_to_list([0])
    result2 = solution.addTwoNumbers(l1, l2)
    print(f"Test 2: {list_to_array(result2)} (expected: [0])")

    # Test case 3: Example 3 - different lengths with carry
    l1 = array_to_list([9, 9, 9, 9, 9, 9, 9])
    l2 = array_to_list([9, 9, 9, 9])
    result3 = solution.addTwoNumbers(l1, l2)
    print(f"Test 3: {list_to_array(result3)} (expected: [8, 9, 9, 9, 0, 0, 0, 1])")

    # Test case 4: Single digit with carry
    l1 = array_to_list([5])
    l2 = array_to_list([5])
    result4 = solution.addTwoNumbers(l1, l2)
    print(f"Test 4: {list_to_array(result4)} (expected: [0, 1])")

    # Test case 5: Different lengths
    l1 = array_to_list([9, 9])
    l2 = array_to_list([1])
    result5 = solution.addTwoNumbers(l1, l2)
    print(f"Test 5: {list_to_array(result5)} (expected: [0, 0, 1])")

    # Test case 6: No carry
    l1 = array_to_list([1, 2, 3])
    l2 = array_to_list([4, 5, 6])
    result6 = solution.addTwoNumbers(l1, l2)
    print(f"Test 6: {list_to_array(result6)} (expected: [5, 7, 9])")

    # Test case 7: One list longer
    l1 = array_to_list([1, 8])
    l2 = array_to_list([0])
    result7 = solution.addTwoNumbers(l1, l2)
    print(f"Test 7: {list_to_array(result7)} (expected: [1, 8])")


if __name__ == "__main__":
    test_add_two_numbers()
