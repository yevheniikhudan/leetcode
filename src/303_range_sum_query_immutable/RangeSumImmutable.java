import java.util.*;

public class RangeSumImmutable {
    private int[] prefix;

    public RangeSumImmutable(int[] nums) {
        prefix = new int[nums.length];
        prefix[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    public int sumRange(int left, int right) {
        int sum = prefix[right];
        if (left > 0)
            sum -= prefix[left - 1];
        return sum;
    }

    // Test scaffolding
    public static void main(String[] args) {
        RangeSumImmutable numArray = new RangeSumImmutable(new int[] { -2, 0, 3, -5, 2, -1 });
        int[][] queries = {
                { 0, 2 },
                { 2, 5 },
                { 0, 5 },
                { 3, 3 },
                { 1, 1 }
        };
        int[] expected = { 1, -1, -3, -5, 0 };
        for (int i = 0; i < queries.length; i++) {
            int actual = numArray.sumRange(queries[i][0], queries[i][1]);
            System.out.println(actual + " | " + expected[i]);
        }
    }
}
