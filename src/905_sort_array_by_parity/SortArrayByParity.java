import java.util.*;

public class SortArrayByParity {
    public int[] sortArrayByParity(int[] nums) {
        int insertIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) {
                int temp = nums[insertIndex];
                nums[insertIndex] = nums[i];
                nums[i] = temp;
                insertIndex++;
            }
        }
        return nums;
    }

    public static void main(String[] args) {
        SortArrayByParity sol = new SortArrayByParity();
        System.out.println(Arrays.toString(sol.sortArrayByParity(new int[] { 3, 1, 2, 4 })) + " | [2, 4, 3, 1]");
        System.out.println(Arrays.toString(sol.sortArrayByParity(new int[] { 0 })) + " | [0]");
        System.out.println(
                Arrays.toString(sol.sortArrayByParity(new int[] { 1, 2, 3, 4, 5, 6 })) + " | [2, 4, 6, 1, 3, 5]");
        System.out.println(Arrays.toString(sol.sortArrayByParity(new int[] { 2, 4, 6, 8 })) + " | [2, 4, 6, 8]");
        System.out.println(Arrays.toString(sol.sortArrayByParity(new int[] { 1, 3, 5, 7 })) + " | [1, 3, 5, 7]");
    }
}
