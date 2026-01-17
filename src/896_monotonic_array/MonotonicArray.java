import java.util.*;

public class MonotonicArray {
    public boolean isMonotonic(int[] nums) {
        boolean inc = true, dec = true;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1])
                dec = false;
            if (nums[i] < nums[i - 1])
                inc = false;
        }
        return inc || dec;
    }

    public static void main(String[] args) {
        MonotonicArray sol = new MonotonicArray();
        System.out.println(sol.isMonotonic(new int[] { 1, 2, 2, 3 }) + " | True");
        System.out.println(sol.isMonotonic(new int[] { 6, 5, 4, 4 }) + " | True");
        System.out.println(sol.isMonotonic(new int[] { 1, 3, 2 }) + " | False");
        System.out.println(sol.isMonotonic(new int[] { 1, 1, 1 }) + " | True");
        System.out.println(sol.isMonotonic(new int[] { 1 }) + " | True");
        System.out.println(sol.isMonotonic(new int[] {}) + " | True");
    }
}
