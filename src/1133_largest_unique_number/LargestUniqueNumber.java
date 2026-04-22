import java.util.*;

class Solution {

    public int largestUniqueNumber(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        int max = -1;

        for (int key : counts.keySet()) {
            if (counts.get(key) == 1) max = Math.max(max, key);
        }
        return max;
    }
}

public class LargestUniqueNumber {

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int[] nums1 = { 5, 7, 3, 9, 4, 9, 8, 3, 1 };
        int result1 = solution.largestUniqueNumber(nums1);
        int expected1 = 8;
        System.out.println(
            result1 +
                " | " +
                expected1 +
                " | " +
                (result1 == expected1 ? "PASS" : "FAIL")
        );

        // Test case 2
        int[] nums2 = { 9, 9, 8, 8 };
        int result2 = solution.largestUniqueNumber(nums2);
        int expected2 = -1;
        System.out.println(
            result2 +
                " | " +
                expected2 +
                " | " +
                (result2 == expected2 ? "PASS" : "FAIL")
        );

        // Test case 3
        int[] nums3 = { 1, 1, 1, 1, 2, 2, 2, 3 };
        int result3 = solution.largestUniqueNumber(nums3);
        int expected3 = 3;
        System.out.println(
            result3 +
                " | " +
                expected3 +
                " | " +
                (result3 == expected3 ? "PASS" : "FAIL")
        );

        // Test case 4
        int[] nums4 = { 5 };
        int result4 = solution.largestUniqueNumber(nums4);
        int expected4 = 5;
        System.out.println(
            result4 +
                " | " +
                expected4 +
                " | " +
                (result4 == expected4 ? "PASS" : "FAIL")
        );

        // Test case 5
        int[] nums5 = { 0, 1, 0, 2, 3, 3 };
        int result5 = solution.largestUniqueNumber(nums5);
        int expected5 = 2;
        System.out.println(
            result5 +
                " | " +
                expected5 +
                " | " +
                (result5 == expected5 ? "PASS" : "FAIL")
        );
    }
}
