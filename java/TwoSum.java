import java.util.Arrays;
import java.util.HashMap;

class Solution {

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int x = target - num;

            if (seen.containsKey(x)) {
                return new int[] { seen.get(x), i };
            }
            seen.put(num, i);
        }

        return new int[] { -1, -1 };
    }
}

public class TwoSum {
    public static void main(String[] args) {
        Solution s = new Solution();

        int[] nums1 = { 2, 7, 11, 15 };
        int target1 = 9;
        System.out.println(Arrays.toString(s.twoSum(nums1, target1)) + " [0, 1]");

        int[] nums2 = { 3, 2, 4 };
        int target2 = 6;
        System.out.println(Arrays.toString(s.twoSum(nums2, target2)) + " [1, 2]");

        int[] nums3 = { 3, 3 };
        int target3 = 6;
        System.out.println(Arrays.toString(s.twoSum(nums3, target3)) + " [0, 1]");
    }
}
