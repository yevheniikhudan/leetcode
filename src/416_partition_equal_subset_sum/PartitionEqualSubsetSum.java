import java.util.*;

class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
}

class PartitionEqualSubsetSum {
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        // Test cases
        testCase(sol, new int[]{1,5,11,5}, true);
        testCase(sol, new int[]{1,2,3,5}, false);
        testCase(sol, new int[]{1,1}, true);
        testCase(sol, new int[]{1}, false);
        testCase(sol, new int[]{0,0}, true);
        testCase(sol, new int[]{2,2,2,2}, true);
    }
    
    private static void testCase(Solution sol, int[] nums, boolean expected) {
        boolean actual = sol.canPartition(nums);
        System.out.println(actual + " | " + expected);
    }
}
