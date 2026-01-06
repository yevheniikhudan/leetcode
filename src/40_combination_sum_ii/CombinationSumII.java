import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(0, new ArrayList<>(), 0, candidates, target, res);
        return res;
    }

    private void backtrack(int start, List<Integer> curr, int total, int[] candidates, int target,
            List<List<Integer>> res) {
        if (total == target) {
            res.add(new ArrayList<>(curr));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (total + candidates[i] > target)
                break;
            curr.add(candidates[i]);
            backtrack(i + 1, curr, total + candidates[i], candidates, target, res);
            curr.remove(curr.size() - 1);
        }
    }
}

public class CombinationSumII {
    private static String formatResult(List<List<Integer>> result) {
        List<String> sorted = new ArrayList<>();
        for (List<Integer> comb : result) {
            Collections.sort(comb);
            sorted.add(comb.toString());
        }
        Collections.sort(sorted);
        return sorted.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        // Test case 1
        int[] c1 = { 10, 1, 2, 7, 6, 1, 5 };
        int t1 = 8;
        List<List<Integer>> e1 = Arrays.asList(Arrays.asList(1, 1, 6), Arrays.asList(1, 2, 5), Arrays.asList(1, 7),
                Arrays.asList(2, 6));
        System.out.println(formatResult(sol.combinationSum2(c1, t1)) + " | " + formatResult(e1));
        // Test case 2
        int[] c2 = { 2, 5, 2, 1, 2 };
        int t2 = 5;
        List<List<Integer>> e2 = Arrays.asList(Arrays.asList(1, 2, 2), Arrays.asList(5));
        System.out.println(formatResult(sol.combinationSum2(c2, t2)) + " | " + formatResult(e2));
        // Test case 3
        int[] c3 = { 2 };
        int t3 = 1;
        List<List<Integer>> e3 = Arrays.asList();
        System.out.println(formatResult(sol.combinationSum2(c3, t3)) + " | " + formatResult(e3));
        // Test case 4
        int[] c4 = { 1 };
        int t4 = 1;
        List<List<Integer>> e4 = Arrays.asList(Arrays.asList(1));
        System.out.println(formatResult(sol.combinationSum2(c4, t4)) + " | " + formatResult(e4));
        // Test case 5
        int[] c5 = { 1 };
        int t5 = 2;
        List<List<Integer>> e5 = Arrays.asList();
        System.out.println(formatResult(sol.combinationSum2(c5, t5)) + " | " + formatResult(e5));
    }
}
