import java.util.Arrays;

public class TwoSumII {
    /**
     * Two Sum II - Input Array Is Sorted
     *
     * @param numbers Sorted list of integers (1-indexed)
     * @param target  Target sum
     * @return 1-indexed positions [index1, index2]
     */
    public int[] twoSum(int[] numbers, int target) {
        int left = 0, right = numbers.length - 1;

        while (left < right) {
            int cur = numbers[left] + numbers[right];

            if (cur == target) {
                return new int[] { left + 1, right + 1 };
            } else if (cur > target) {
                right -= 1;
            } else if (cur < target) {
                left += 1;
            }
        }

        return new int[] { -1, -1 };
    }

    public static void main(String[] args) {
        TwoSumII solution = new TwoSumII();

        // Test case 1
        int[] numbers1 = { 2, 7, 11, 15 };
        int target1 = 9;
        int[] result1 = solution.twoSum(numbers1, target1);
        System.out.println("Test 1: [2,7,11,15], target=9 -> " + Arrays.toString(result1));
        assert Arrays.equals(result1, new int[] { 1, 2 }) : "Expected [1,2], got " + Arrays.toString(result1);

        // Test case 2
        int[] numbers2 = { 2, 3, 4 };
        int target2 = 6;
        int[] result2 = solution.twoSum(numbers2, target2);
        System.out.println("Test 2: [2,3,4], target=6 -> " + Arrays.toString(result2));
        assert Arrays.equals(result2, new int[] { 1, 3 }) : "Expected [1,3], got " + Arrays.toString(result2);

        // Test case 3
        int[] numbers3 = { -1, 0 };
        int target3 = -1;
        int[] result3 = solution.twoSum(numbers3, target3);
        System.out.println("Test 3: [-1,0], target=-1 -> " + Arrays.toString(result3));
        assert Arrays.equals(result3, new int[] { 1, 2 }) : "Expected [1,2], got " + Arrays.toString(result3);

        // Test case 4: Larger array
        int[] numbers4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int target4 = 17;
        int[] result4 = solution.twoSum(numbers4, target4);
        System.out.println("Test 4: [1,2,3,4,5,6,7,8,9], target=17 -> " + Arrays.toString(result4));
        assert Arrays.equals(result4, new int[] { 8, 9 }) : "Expected [8,9], got " + Arrays.toString(result4);

        // Test case 5: Negative numbers
        int[] numbers5 = { -5, -3, -1, 0, 2, 4 };
        int target5 = -4;
        int[] result5 = solution.twoSum(numbers5, target5);
        System.out.println("Test 5: [-5,-3,-1,0,2,4], target=-4 -> " + Arrays.toString(result5));
        assert Arrays.equals(result5, new int[] { 2, 3 }) : "Expected [2,3], got " + Arrays.toString(result5);

        System.out.println("All test cases passed!");
    }
}
