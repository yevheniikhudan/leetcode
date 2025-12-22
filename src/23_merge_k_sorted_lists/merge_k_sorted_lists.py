"""
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Difficulty: Hard
"""

from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        Merge k sorted linked lists into one sorted linked list.

        Args:
            lists: Array of k linked-lists, each sorted in ascending order

        Returns:
            Head of the merged sorted linked list

        Time Complexity: O(N log k) where N is total nodes, k is number of lists
        Space Complexity: O(k) for the heap
        """
        n = len(lists)
        if n == 0:
            return None

        def mergeTwoListsRecursive(
            list1: Optional[ListNode], list2: Optional[ListNode]
        ):
            if not list1:
                return list2

            if not list2:
                return list1

            if list1.val < list2.val:
                list1.next = mergeTwoListsRecursive(list1.next, list2)
                return list1
            else:
                list2.next = mergeTwoListsRecursive(list1, list2.next)
                return list2

        while len(lists) > 1:
            merged = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i + 1] if i + 1 < len(lists) else None
                merged.append(mergeTwoListsRecursive(l1, l2))
            lists = merged

        return lists[-1]


# Helper functions for testing
def list_to_array(head: Optional[ListNode]) -> List[int]:
    """Convert linked list to array."""
    result = []
    curr = head
    while curr:
        result.append(curr.val)
        curr = curr.next
    return result


def array_to_list(arr: List[int]) -> Optional[ListNode]:
    """Convert array to linked list."""
    if not arr:
        return None
    head = ListNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head


def test_merge_k_lists():
    solution = Solution()

    # Test case 1: Example 1 - three lists
    lists1 = [array_to_list([1, 4, 5]), array_to_list([1, 3, 4]), array_to_list([2, 6])]
    result1 = solution.mergeKLists(lists1)
    print(f"Test 1: {list_to_array(result1)} (expected: [1, 1, 2, 3, 4, 4, 5, 6])")

    # Test case 2: Example 2 - empty list
    lists2 = []
    result2 = solution.mergeKLists(lists2)
    print(f"Test 2: {list_to_array(result2)} (expected: [])")

    # Test case 3: Example 3 - list with empty list
    lists3 = [array_to_list([])]
    result3 = solution.mergeKLists(lists3)
    print(f"Test 3: {list_to_array(result3)} (expected: [])")

    # Test case 4: Single list
    lists4 = [array_to_list([1, 2, 3])]
    result4 = solution.mergeKLists(lists4)
    print(f"Test 4: {list_to_array(result4)} (expected: [1, 2, 3])")

    # Test case 5: Two lists
    lists5 = [array_to_list([1, 3, 5]), array_to_list([2, 4, 6])]
    result5 = solution.mergeKLists(lists5)
    print(f"Test 5: {list_to_array(result5)} (expected: [1, 2, 3, 4, 5, 6])")

    # Test case 6: Lists with different lengths
    lists6 = [array_to_list([1]), array_to_list([1, 3, 4]), array_to_list([2, 6])]
    result6 = solution.mergeKLists(lists6)
    print(f"Test 6: {list_to_array(result6)} (expected: [1, 1, 2, 3, 4, 6])")

    # Test case 7: Negative values
    lists7 = [array_to_list([-2, -1, 0]), array_to_list([-3, 1, 2])]
    result7 = solution.mergeKLists(lists7)
    print(f"Test 7: {list_to_array(result7)} (expected: [-3, -2, -1, 0, 1, 2])")


if __name__ == "__main__":
    test_merge_k_lists()
