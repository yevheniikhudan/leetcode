import random
from typing import List
import heapq


class Solution:

    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition3way(left, right):
            pivot_index = random.randint(left, right)
            pivot = nums[pivot_index]
            nums[pivot_index], nums[right] = nums[right], nums[pivot_index]

            # 3-way partition: lt marks start of equal section, gt marks end
            lt = left  # Everything before lt is > pivot
            gt = right  # Everything after gt is < pivot
            i = left

            while i <= gt:
                if nums[i] > pivot:
                    nums[lt], nums[i] = nums[i], nums[lt]
                    lt += 1
                    i += 1
                elif nums[i] < pivot:
                    nums[gt], nums[i] = nums[i], nums[gt]
                    gt -= 1
                else:  # nums[i] == pivot
                    i += 1

            return lt, gt  # [left, lt) > pivot, [lt, gt] == pivot, (gt, right] < pivot

        target = k - 1
        left, right = 0, len(nums) - 1

        while left <= right:
            lt, gt = partition3way(left, right)
            if target < lt:
                right = lt - 1
            elif target > gt:
                left = gt + 1
            else:
                return nums[target]

    def findKthLargestHeap(self, nums: List[int], k: int) -> int:
        h = []

        for num in nums:
            heapq.heappush(h, num)

            if len(h) > k:
                heapq.heappop(h)

        return heapq.heappop(h)


# Test scaffolding
if __name__ == "__main__":
    tests = [
        (([3, 2, 1, 5, 6, 4], 2), 5),
        (([3, 2, 3, 1, 2, 4, 5, 5, 6], 4), 4),
        (([1], 1), 1),
        (([2, 1], 2), 1),
        (([7, 6, 5, 4, 3, 2, 1], 5), 3),
    ]
    sol = Solution()
    for (nums, k), expected in tests:
        actual = sol.findKthLargest(nums, k)
        print(f"{actual} | {expected}")
