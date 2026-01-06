import java.util.*;

// Solution class for logic
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        backtrack(nums, 0, new ArrayList<>(), res);
        return res;
    }

    private void backtrack(int[] nums, int start, List<Integer> path, List<List<Integer>> res) {
        res.add(new ArrayList<>(path));
        for (int i = start; i < nums.length; ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.add(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.remove(path.size() - 1);
        }
    }
}

// Main/test class
public class SubsetsII {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = { 1, 2, 2 };
        System.out.println(sol.subsetsWithDup(nums1));
        int[] nums2 = { 0 };
        System.out.println(sol.subsetsWithDup(nums2));
        int[] nums3 = { 4, 4, 4, 1, 4 };
        System.out.println(sol.subsetsWithDup(nums3));
    }
}
