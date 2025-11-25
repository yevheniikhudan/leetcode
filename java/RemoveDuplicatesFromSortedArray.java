import java.util.Arrays;

public class RemoveDuplicatesFromSortedArray {
        /**
         * Remove Duplicates from Sorted Array
         *
         * @param nums List of sorted integers
         * @return Number of unique elements after removing duplicates
         */
        public int removeDuplicates(int[] nums) {
                if (nums.length == 0) {
                        return 0;
                }

                int k = 0;
                for (int i = 1; i < nums.length; i++) {
                        if (nums[i] != nums[k]) {
                                nums[++k] = nums[i];
                        }
                }

                return k + 1;
        }

        public static void main(String[] args) {
                RemoveDuplicatesFromSortedArray solution = new RemoveDuplicatesFromSortedArray();

                // Test case 1
                int[] nums1 = { 1, 1, 2 };
                int k1 = solution.removeDuplicates(nums1);
                System.out.println("Test 1: " + Arrays.toString(nums1) + ", k = " + k1);
                assert k1 == 2 && Arrays.equals(Arrays.copyOf(nums1, k1), new int[] { 1, 2 })
                                : "Expected k=2, nums=[1,2], got k=" + k1 + ", nums="
                                                + Arrays.toString(Arrays.copyOf(nums1, k1));

                // Test case 2
                int[] nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
                int k2 = solution.removeDuplicates(nums2);
                System.out.println("Test 2: " + Arrays.toString(nums2) + ", k = " + k2);
                assert k2 == 5 && Arrays.equals(Arrays.copyOf(nums2, k2), new int[] { 0, 1, 2, 3, 4 })
                                : "Expected k=5, nums=[0,1,2,3,4], got k=" + k2 + ", nums="
                                                + Arrays.toString(Arrays.copyOf(nums2, k2));

                // Test case 3: All elements same
                int[] nums3 = { 2, 2, 2, 2, 2 };
                int k3 = solution.removeDuplicates(nums3);
                System.out.println("Test 3: " + Arrays.toString(nums3) + ", k = " + k3);
                assert k3 == 1 && Arrays.equals(Arrays.copyOf(nums3, k3), new int[] { 2 })
                                : "Expected k=1, nums=[2], got k=" + k3 + ", nums="
                                                + Arrays.toString(Arrays.copyOf(nums3, k3));

                // Test case 4: No duplicates
                int[] nums4 = { 1, 2, 3, 4, 5 };
                int k4 = solution.removeDuplicates(nums4);
                System.out.println("Test 4: " + Arrays.toString(nums4) + ", k = " + k4);
                assert k4 == 5 && Arrays.equals(Arrays.copyOf(nums4, k4), new int[] { 1, 2, 3, 4, 5 })
                                : "Expected k=5, nums=[1,2,3,4,5], got k=" + k4 + ", nums="
                                                + Arrays.toString(Arrays.copyOf(nums4, k4));

                System.out.println("All test cases passed!");
        }
}
