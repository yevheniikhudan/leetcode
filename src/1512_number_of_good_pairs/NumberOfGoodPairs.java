import java.util.*;

public class NumberOfGoodPairs {
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        int res = 0;
        for (int num : nums) {
            res += count.getOrDefault(num, 0);
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        return res;
    }

    public static void main(String[] args) {
        NumberOfGoodPairs sol = new NumberOfGoodPairs();
        System.out.println(sol.numIdenticalPairs(new int[] { 1, 2, 3, 1, 1, 3 }) + " | 4");
        System.out.println(sol.numIdenticalPairs(new int[] { 1, 1, 1, 1 }) + " | 6");
        System.out.println(sol.numIdenticalPairs(new int[] { 1, 2, 3 }) + " | 0");
        System.out.println(sol.numIdenticalPairs(new int[] {}) + " | 0");
        System.out.println(sol.numIdenticalPairs(new int[] { 2, 2, 2, 2, 2 }) + " | 10");
    }
}
