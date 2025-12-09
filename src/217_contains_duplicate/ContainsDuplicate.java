import java.util.HashSet;
import java.util.Set;

public class ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();

        for (int num : nums) {
            if (seen.contains(num))
                return true;

            seen.add(num);
        }
        return false;
    }

    public static void main(String[] args) {
        ContainsDuplicate s = new ContainsDuplicate();
        int[] nums1 = { 1, 2, 3, 1 };
        System.out.println(s.containsDuplicate(nums1) + " true");
        int[] nums2 = { 1, 2, 3, 4 };
        System.out.println(s.containsDuplicate(nums2) + " false");
        int[] nums3 = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
        System.out.println(s.containsDuplicate(nums3) + " true");
    }
}
