import java.util.*;

class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> ans = new HashSet<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            int numI = nums[i];

            if (i > 0 && numI == nums[i - 1]) {
                continue;
            }

            Set<Integer> seen = new HashSet<>();
            for (int j = i + 1; j < nums.length; j++) {
                int numJ = nums[j];
                int target = -(numI + numJ);

                if (seen.contains(target)) {
                    ans.add(Arrays.asList(numI, numJ, target));
                }

                seen.add(numJ);
            }
        }

        return new ArrayList<List<Integer>>(ans);
    }

    public static void main(String[] args) {
        ThreeSum s = new ThreeSum();

        int[] nums1 = { -1, 0, 1, 2, -1, -4 };
        System.out.println(s.threeSum(nums1) + " Expected: [[-1, -1, 2], [-1, 0, 1]]");

        int[] nums2 = { 0, 1, 1 };
        System.out.println(s.threeSum(nums2) + " Expected: []");

        int[] nums3 = { 0, 0, 0 };
        System.out.println(s.threeSum(nums3) + " Expected: [[0, 0, 0]]");
    }
}
