"""
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.

Difficulty: Easy
"""

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        """
        Merge two sorted linked lists iteratively using dummy node.

        Args:
            list1: Head of first sorted linked list
            list2: Head of second sorted linked list

        Returns:
            Head of merged sorted linked list

        Time Complexity: O(n + m) - visit each node once
        Space Complexity: O(1) - only use a few pointers
        """
        dummy = ListNode()
        tail = dummy

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next

            tail = tail.next

        tail.next = list1 if list1 else list2

        return dummy.next

    def mergeTwoListsRecursive(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        """
        Merge two sorted linked lists recursively.

        Args:
            list1: Head of first sorted linked list
            list2: Head of second sorted linked list

        Returns:
            Head of merged sorted linked list

        Time Complexity: O(n + m) - visit each node once
        Space Complexity: O(n + m) - recursive call stack
        """
        if not list1:
            return list2

        if not list2:
            return list1

        if list1.val < list2.val:
            list1.next = self.mergeTwoListsRecursive(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoListsRecursive(list1, list2.next)
            return list2


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


def test_merge_two_sorted_lists():
    solution = Solution()

    # Test case 1: Example 1 - regular merge
    list1_1 = array_to_list([1, 2, 4])
    list2_1 = array_to_list([1, 3, 4])
    result1 = solution.mergeTwoLists(list1_1, list2_1)
    print(
        f"Test 1 (Iterative): {list_to_array(result1)} (expected: [1, 1, 2, 3, 4, 4])"
    )

    # Test case 2: Example 2 - both empty
    list1_2 = array_to_list([])
    list2_2 = array_to_list([])
    result2 = solution.mergeTwoLists(list1_2, list2_2)
    print(f"Test 2 (Iterative): {list_to_array(result2)} (expected: [])")

    # Test case 3: Example 3 - one empty
    list1_3 = array_to_list([])
    list2_3 = array_to_list([0])
    result3 = solution.mergeTwoLists(list1_3, list2_3)
    print(f"Test 3 (Iterative): {list_to_array(result3)} (expected: [0])")

    # Test case 4: First list empty
    list1_4 = array_to_list([])
    list2_4 = array_to_list([1, 2, 3])
    result4 = solution.mergeTwoLists(list1_4, list2_4)
    print(f"Test 4 (Iterative): {list_to_array(result4)} (expected: [1, 2, 3])")

    # Test case 5: Second list empty
    list1_5 = array_to_list([1, 2, 3])
    list2_5 = array_to_list([])
    result5 = solution.mergeTwoLists(list1_5, list2_5)
    print(f"Test 5 (Iterative): {list_to_array(result5)} (expected: [1, 2, 3])")

    # Test case 6: No overlap
    list1_6 = array_to_list([1, 2, 3])
    list2_6 = array_to_list([4, 5, 6])
    result6 = solution.mergeTwoLists(list1_6, list2_6)
    print(
        f"Test 6 (Iterative): {list_to_array(result6)} (expected: [1, 2, 3, 4, 5, 6])"
    )

    # Test case 7: Different lengths
    list1_7 = array_to_list([1, 3, 5, 7, 9])
    list2_7 = array_to_list([2, 4])
    result7 = solution.mergeTwoLists(list1_7, list2_7)
    print(
        f"Test 7 (Iterative): {list_to_array(result7)} (expected: [1, 2, 3, 4, 5, 7, 9])"
    )

    # Test case 8: All duplicates
    list1_8 = array_to_list([1, 1, 1])
    list2_8 = array_to_list([1, 1])
    result8 = solution.mergeTwoLists(list1_8, list2_8)
    print(f"Test 8 (Iterative): {list_to_array(result8)} (expected: [1, 1, 1, 1, 1])")

    print("\n--- Recursive Tests ---")

    # Test case 9: Recursive - regular merge
    list1_9 = array_to_list([1, 2, 4])
    list2_9 = array_to_list([1, 3, 4])
    result9 = solution.mergeTwoListsRecursive(list1_9, list2_9)
    print(
        f"Test 9 (Recursive): {list_to_array(result9)} (expected: [1, 1, 2, 3, 4, 4])"
    )

    # Test case 10: Recursive - both empty
    list1_10 = array_to_list([])
    list2_10 = array_to_list([])
    result10 = solution.mergeTwoListsRecursive(list1_10, list2_10)
    print(f"Test 10 (Recursive): {list_to_array(result10)} (expected: [])")

    # Test case 11: Recursive - one empty
    list1_11 = array_to_list([])
    list2_11 = array_to_list([0])
    result11 = solution.mergeTwoListsRecursive(list1_11, list2_11)
    print(f"Test 11 (Recursive): {list_to_array(result11)} (expected: [0])")

    # Test case 12: Recursive - different lengths
    list1_12 = array_to_list([1, 3, 5])
    list2_12 = array_to_list([2, 4, 6, 8, 10])
    result12 = solution.mergeTwoListsRecursive(list1_12, list2_12)
    print(
        f"Test 12 (Recursive): {list_to_array(result12)} (expected: [1, 2, 3, 4, 5, 6, 8, 10])"
    )


if __name__ == "__main__":
    test_merge_two_sorted_lists()
