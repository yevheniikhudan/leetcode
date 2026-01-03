from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        return slow


def build_list(arr: List[int]) -> Optional[ListNode]:
    dummy = ListNode(0)
    curr = dummy
    for x in arr:
        curr.next = ListNode(x)
        curr = curr.next
    return dummy.next


def list_to_array(head: Optional[ListNode]) -> List[int]:
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res


# Test scaffolding
if __name__ == "__main__":
    tests = [
        ([1, 2, 3, 4, 5], [3, 4, 5]),
        ([1, 2, 3, 4, 5, 6], [4, 5, 6]),
        ([1], [1]),
        ([1, 2], [2]),
        ([1, 2, 3], [2, 3]),
    ]
    sol = Solution()
    for arr, expected in tests:
        head = build_list(arr)
        actual = list_to_array(sol.middleNode(head))
        print(f"{actual} | {expected}")
