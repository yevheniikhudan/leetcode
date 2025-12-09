from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        best_distance = float("inf")
        best_sum = 0
        n = len(nums)

        for i in range(0, n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = n - 1
            while left < right:
                current_sum = nums[right] + nums[left] + nums[i]

                if current_sum == target:
                    return current_sum
                elif current_sum > target:
                    right -= 1
                else:
                    left += 1

                current_distance = abs(current_sum - target)
                if current_distance < best_distance:
                    best_distance = current_distance
                    best_sum = current_sum

        return best_sum


s = Solution()

nums = [-1, 2, 1, -4]
target = 1
print(s.threeSumClosest(nums, target), 2)

nums = [0, 0, 0]
target = 1
print(s.threeSumClosest(nums, target), 0)
