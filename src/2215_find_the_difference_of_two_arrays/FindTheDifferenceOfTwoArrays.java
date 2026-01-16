import java.util.*;

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for (int n : nums1)
            set1.add(n);
        for (int n : nums2)
            set2.add(n);
        List<Integer> diff1 = new ArrayList<>();
        List<Integer> diff2 = new ArrayList<>();
        for (int n : set1)
            if (!set2.contains(n))
                diff1.add(n);
        for (int n : set2)
            if (!set1.contains(n))
                diff2.add(n);
        List<List<Integer>> res = new ArrayList<>();
        res.add(diff1);
        res.add(diff2);
        return res;
    }
}

public class FindTheDifferenceOfTwoArrays {
    public static void main(String[] args) {
        int[][][] tests = {
                { { 1, 2, 3 }, { 2, 4, 6 } },
                { { 1, 2, 3, 3 }, { 1, 1, 2, 2 } },
                { { 1, 2, 3 }, { 4, 5, 6 } },
                { { 1, 2, 2, 3 }, { 3, 4, 4, 5 } },
                { { 1 }, { 1 } }
        };
        List<List<List<Integer>>> expected = Arrays.asList(
                Arrays.asList(Arrays.asList(1, 3), Arrays.asList(4, 6)),
                Arrays.asList(Arrays.asList(3), Arrays.asList()),
                Arrays.asList(Arrays.asList(1, 2, 3), Arrays.asList(4, 5, 6)),
                Arrays.asList(Arrays.asList(1, 2), Arrays.asList(4, 5)),
                Arrays.asList(Arrays.asList(), Arrays.asList()));
        Solution sol = new Solution();
        for (int i = 0; i < tests.length; ++i) {
            int[] nums1 = tests[i][0];
            int[] nums2 = tests[i][1];
            List<List<Integer>> actual = sol.findDifference(nums1, nums2);
            System.out.println(actual + " | " + expected.get(i));
        }
    }
}
