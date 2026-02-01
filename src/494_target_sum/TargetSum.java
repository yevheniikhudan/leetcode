import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        Map<Integer, Integer> dp = new HashMap<>();
        dp.put(0, 1);

        for (int num : nums) {
            Map<Integer, Integer> nextDp = new HashMap<>();

            for (Map.Entry<Integer, Integer> entry : dp.entrySet()) {
                int total = entry.getKey();
                int count = entry.getValue();
                nextDp.put(total - num, nextDp.getOrDefault(total - num, 0) + count);
                nextDp.put(total + num, nextDp.getOrDefault(total + num, 0) + count);
            }

            dp = nextDp;
        }

        return dp.getOrDefault(target, 0);
    }
}

public class TargetSum {
    public static void main(String[] args) {
        Solution sol = new Solution();
        // Test case 1: Example 1
        System.out.println(sol.findTargetSumWays(new int[] { 1, 1, 1, 1, 1 }, 3) + " | 5");
        // Test case 2: Example 2
        System.out.println(sol.findTargetSumWays(new int[] { 1 }, 1) + " | 1");
        // Test case 3: No ways
        System.out.println(sol.findTargetSumWays(new int[] { 1 }, 2) + " | 0");
        // Test case 4: Target 0
        System.out.println(sol.findTargetSumWays(new int[] { 1, 1 }, 0) + " | 2");
        // Test case 5: Larger numbers
        System.out.println(sol.findTargetSumWays(new int[] { 1, 2, 3 }, 0) + " | 2");
        // Test case 6: All zeros
        System.out.println(sol.findTargetSumWays(new int[] { 0, 0 }, 0) + " | 4");
    }
}
