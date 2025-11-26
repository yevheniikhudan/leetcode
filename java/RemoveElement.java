import java.util.Arrays;

public class RemoveElement {
    /**
     * Remove Element
     *
     * @param nums List of integers
     * @param val  Value to remove
     * @return Number of elements not equal to val
     */
    public int removeElement(int[] nums, int val) {
        int i = 0, j = nums.length - 1;
        while (i <= j) {
            while (nums[j] == val && j > i)
                j--;
            if (nums[i] == val) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            }

            i++;
        }
        return j + 1;
    }

    public static void main(String[] args) {
        RemoveElement solution = new RemoveElement();

        // Test case 1
        int[] nums1 = { 3, 2, 2, 3 };
        int val1 = 3;
        int k1 = solution.removeElement(nums1, val1);
        System.out.println("Test 1: " + Arrays.toString(nums1) + ", val = " + val1 + ", k = " + k1);
        int[] expected1 = { 2, 2 };
        Arrays.sort(nums1, 0, k1);
        assert k1 == 2 && Arrays.equals(Arrays.copyOf(nums1, k1), expected1)
                : "Expected k=2, nums=[2,2], got k=" + k1 + ", nums=" + Arrays.toString(Arrays.copyOf(nums1, k1));

        // Test case 2
        int[] nums2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
        int val2 = 2;
        int k2 = solution.removeElement(nums2, val2);
        System.out.println("Test 2: " + Arrays.toString(nums2) + ", val = " + val2 + ", k = " + k2);
        int[] expected2 = { 0, 0, 1, 3, 4 };
        Arrays.sort(nums2, 0, k2);
        assert k2 == 5 && Arrays.equals(Arrays.copyOf(nums2, k2), expected2)
                : "Expected k=5, nums=[0,0,1,3,4], got k=" + k2 + ", nums=" + Arrays.toString(Arrays.copyOf(nums2, k2));

        // Test case 3: All elements are val
        int[] nums3 = { 2, 2, 2, 2, 2 };
        int val3 = 2;
        int k3 = solution.removeElement(nums3, val3);
        System.out.println("Test 3: " + Arrays.toString(nums3) + ", val = " + val3 + ", k = " + k3);
        assert k3 == 0 : "Expected k=0, got k=" + k3;

        // Test case 4: No elements are val
        int[] nums4 = { 1, 2, 3, 4, 5 };
        int val4 = 6;
        int k4 = solution.removeElement(nums4, val4);
        System.out.println("Test 4: " + Arrays.toString(nums4) + ", val = " + val4 + ", k = " + k4);
        int[] expected4 = { 1, 2, 3, 4, 5 };
        Arrays.sort(nums4, 0, k4);
        assert k4 == 5 && Arrays.equals(Arrays.copyOf(nums4, k4), expected4)
                : "Expected k=5, nums=[1,2,3,4,5], got k=" + k4 + ", nums=" + Arrays.toString(Arrays.copyOf(nums4, k4));

        System.out.println("All test cases passed!");
    }
}
