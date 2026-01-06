import java.util.*;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(0, new ArrayList<>(), nums, res);
        return res;
    }

    private void backtrack(int first, List<Integer> curr, int[] nums, List<List<Integer>> res) {
        res.add(new ArrayList<>(curr));
        for (int i = first; i < nums.length; i++) {
            curr.add(nums[i]);
            backtrack(i + 1, curr, nums, res);
            curr.remove(curr.size() - 1);
        }
    }
}

public class Subsets {
    // Helper method to sort and compare lists of lists
    private static String formatResult(List<List<Integer>> result) {
        List<String> sorted = new ArrayList<>();
        for (List<Integer> subset : result) {
            Collections.sort(subset);
            sorted.add(subset.toString());
        }
        Collections.sort(sorted);
        return sorted.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test case 1
        int[] nums1 = { 1, 2, 3 };
        List<List<Integer>> result1 = sol.subsets(nums1);
        List<List<Integer>> expected1 = Arrays.asList(
                Arrays.asList(),
                Arrays.asList(1),
                Arrays.asList(2),
                Arrays.asList(1, 2),
                Arrays.asList(3),
                Arrays.asList(1, 3),
                Arrays.asList(2, 3),
                Arrays.asList(1, 2, 3));
        System.out.println(formatResult(result1) + " | " + formatResult(expected1));

        // Test case 2
        int[] nums2 = { 0 };
        List<List<Integer>> result2 = sol.subsets(nums2);
        List<List<Integer>> expected2 = Arrays.asList(
                Arrays.asList(),
                Arrays.asList(0));
        System.out.println(formatResult(result2) + " | " + formatResult(expected2));

        // Test case 3
        int[] nums3 = { 1 };
        List<List<Integer>> result3 = sol.subsets(nums3);
        List<List<Integer>> expected3 = Arrays.asList(
                Arrays.asList(),
                Arrays.asList(1));
        System.out.println(formatResult(result3) + " | " + formatResult(expected3));

        // Test case 4
        int[] nums4 = { 1, 2 };
        List<List<Integer>> result4 = sol.subsets(nums4);
        List<List<Integer>> expected4 = Arrays.asList(
                Arrays.asList(),
                Arrays.asList(1),
                Arrays.asList(2),
                Arrays.asList(1, 2));
        System.out.println(formatResult(result4) + " | " + formatResult(expected4));

        // Test case 5
        int[] nums5 = { 9, 0, 3, 5, 7 };
        List<List<Integer>> result5 = sol.subsets(nums5);
        int expectedLen = (int) Math.pow(2, 5); // 32 subsets
        System.out.println((result5 != null ? result5.size() : 0) + " | " + expectedLen);
    }
}
