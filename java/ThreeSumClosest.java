import java.util.Arrays;

class ThreeSumClosest {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int bestDistance = Integer.MAX_VALUE;
        int bestSum = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (currentSum == target) {
                    return currentSum;
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }

                int currentDistance = Math.abs(currentSum - target);
                if (currentDistance < bestDistance) {
                    bestSum = currentSum;
                    bestDistance = currentDistance;
                }
            }
        }

        return bestSum;
    }

    public static void main(String[] args) {
        ThreeSumClosest s = new ThreeSumClosest();

        int[] nums1 = { -1, 2, 1, -4 };
        int target1 = 1;
        System.out.println(s.threeSumClosest(nums1, target1) + " Expected: 2");

        int[] nums2 = { 0, 0, 0 };
        int target2 = 1;
        System.out.println(s.threeSumClosest(nums2, target2) + " Expected: 0");
    }
}
