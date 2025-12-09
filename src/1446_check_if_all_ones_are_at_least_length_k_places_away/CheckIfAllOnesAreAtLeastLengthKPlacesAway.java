public class CheckIfAllOnesAreAtLeastLengthKPlacesAway {
    public boolean kLengthApart(int[] nums, int k) {
        int previousId = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                if (previousId != -1 && i - previousId - 1 < k)
                    return false;

                previousId = i;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        CheckIfAllOnesAreAtLeastLengthKPlacesAway s = new CheckIfAllOnesAreAtLeastLengthKPlacesAway();
        int[] nums1 = { 1, 0, 0, 0, 1, 0, 0, 1 };
        int k1 = 2;
        System.out.println(s.kLengthApart(nums1, k1) + " true");
        int[] nums2 = { 1, 0, 0, 1, 0, 1 };
        int k2 = 2;
        System.out.println(s.kLengthApart(nums2, k2) + " false");
    }
}
