import java.util.*;

public class LargestDivisibleSubset {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> dp = new ArrayList<>();
        for (int num : nums)
            dp.add(new ArrayList<>(Arrays.asList(num)));
        List<Integer> res = new ArrayList<>();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    if (dp.get(j).size() + 1 > dp.get(i).size()) {
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[i]);
                        temp.addAll(dp.get(j));
                        dp.set(i, temp);
                    }
                }
            }
            if (dp.get(i).size() > res.size()) {
                res = dp.get(i);
            }
        }
        return res;
    }

    // Test scaffolding
    public static void main(String[] args) {
        LargestDivisibleSubset sol = new LargestDivisibleSubset();
        System.out.println(sol.largestDivisibleSubset(new int[] { 1, 2, 3 }) + " | [1,2] or [1,3]");
        System.out.println(sol.largestDivisibleSubset(new int[] { 1, 2, 4, 8 }) + " | [1,2,4,8]");
        System.out.println(sol.largestDivisibleSubset(new int[] { 4, 8, 10, 240 }) + " | [4,8,240] or [10,240]");
        System.out.println(sol.largestDivisibleSubset(new int[] { 2, 3, 4, 9, 8 }) + " | [2,4,8] or [3,9]");
        System.out.println(sol.largestDivisibleSubset(new int[] { 1 }) + " | [1]");
    }
}
