import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence {
    /**
     * Longest Consecutive Sequence
     *
     * @param nums List of integers
     * @return Length of longest consecutive sequence
     */
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        Set<Integer> cache = new HashSet<>();
        for (int num : nums) {
            cache.add(num);
        }

        int result = 0;

        for (int num : cache) {
            if (cache.contains(num - 1)) {
                continue;
            }

            int cur = 1;
            while(cache.contains(num + cur)) {
                cur += 1;
            }
            result = Math.max(result, cur);
        }

        return result;
    }

    public static void main(String[] args) {
        LongestConsecutiveSequence solution = new LongestConsecutiveSequence();

        // Test case 1
        int[] nums1 = { 100, 4, 200, 1, 3, 2 };
        int result1 = solution.longestConsecutive(nums1);
        System.out.println("Test 1: [100,4,200,1,3,2] -> " + result1);
        assert result1 == 4 : "Expected 4, got " + result1;

        // Test case 2
        int[] nums2 = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
        int result2 = solution.longestConsecutive(nums2);
        System.out.println("Test 2: [0,3,7,2,5,8,4,6,0,1] -> " + result2);
        assert result2 == 9 : "Expected 9, got " + result2;

        // Test case 3
        int[] nums3 = { 1, 0, 1, 2 };
        int result3 = solution.longestConsecutive(nums3);
        System.out.println("Test 3: [1,0,1,2] -> " + result3);
        assert result3 == 3 : "Expected 3, got " + result3;

        // Test case 4: Empty array
        int[] nums4 = {};
        int result4 = solution.longestConsecutive(nums4);
        System.out.println("Test 4: [] -> " + result4);
        assert result4 == 0 : "Expected 0, got " + result4;

        // Test case 5: Single element
        int[] nums5 = { 1 };
        int result5 = solution.longestConsecutive(nums5);
        System.out.println("Test 5: [1] -> " + result5);
        assert result5 == 1 : "Expected 1, got " + result5;

        // Test case 6: No consecutive
        int[] nums6 = { 1, 3, 5, 7, 9 };
        int result6 = solution.longestConsecutive(nums6);
        System.out.println("Test 6: [1,3,5,7,9] -> " + result6);
        assert result6 == 1 : "Expected 1, got " + result6;

        System.out.println("All test cases passed!");
    }
}
