import java.util.*;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(nums, 0, res);
        return res;
    }

    private void backtrack(int[] nums, int i, List<List<Integer>> res) {
        if (i == nums.length) {
            List<Integer> perm = new ArrayList<>();
            for (int n : nums)
                perm.add(n);
            res.add(new ArrayList<>(perm));
            return;
        }
        for (int j = i; j < nums.length; ++j) {
            swap(nums, i, j);
            backtrack(nums, i + 1, res);
            swap(nums, i, j);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public List<List<Integer>> permuteIterative(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        for (int num : nums) {
            List<List<Integer>> nextPerms = new ArrayList<>();
            for (List<Integer> p : res) {
                for (int i = 0; i <= p.size(); ++i) {
                    List<Integer> pCopy = new ArrayList<>(p);
                    pCopy.add(i, num);
                    nextPerms.add(pCopy);
                }
            }
            res = nextPerms;
        }
        return res;
    }
}

public class Permutations {
    private static String formatResult(List<List<Integer>> result) {
        List<String> sorted = new ArrayList<>();
        for (List<Integer> perm : result) {
            Collections.sort(perm);
            sorted.add(perm.toString());
        }
        Collections.sort(sorted);
        return sorted.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        // Test case 1
        int[] nums1 = { 1, 2, 3 };
        List<List<Integer>> e1 = Arrays.asList(
                Arrays.asList(1, 2, 3), Arrays.asList(1, 3, 2), Arrays.asList(2, 1, 3), Arrays.asList(2, 3, 1),
                Arrays.asList(3, 1, 2), Arrays.asList(3, 2, 1));
        System.out.println(formatResult(sol.permute(nums1)) + " | " + formatResult(e1));
        // Test case 2
        int[] nums2 = { 0, 1 };
        List<List<Integer>> e2 = Arrays.asList(Arrays.asList(0, 1), Arrays.asList(1, 0));
        System.out.println(formatResult(sol.permute(nums2)) + " | " + formatResult(e2));
        // Test case 3
        int[] nums3 = { 1 };
        List<List<Integer>> e3 = Arrays.asList(Arrays.asList(1));
        System.out.println(formatResult(sol.permute(nums3)) + " | " + formatResult(e3));
        // Test case 4
        int[] nums4 = { 2, 1 };
        List<List<Integer>> e4 = Arrays.asList(Arrays.asList(2, 1), Arrays.asList(1, 2));
        System.out.println(formatResult(sol.permute(nums4)) + " | " + formatResult(e4));
        // Test case 5
        int[] nums5 = { 1, 2, 3, 4 };
        System.out.println((sol.permute(nums5) != null ? sol.permute(nums5).size() : 0) + " | " + 24);
    }
}
