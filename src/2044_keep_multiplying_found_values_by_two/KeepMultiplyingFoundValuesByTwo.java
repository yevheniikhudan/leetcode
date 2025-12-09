import java.util.HashSet;
import java.util.Set;

public class KeepMultiplyingFoundValuesByTwo {
    public int findFinalValue(int[] nums, int original) {
        Set<Integer> numsSet = new HashSet<>();

        for (int num : nums) {
            numsSet.add(num);
        }

        while (numsSet.contains(original))
            original *= 2;

        return original;
    }

    public static void main(String[] args) {
        KeepMultiplyingFoundValuesByTwo s = new KeepMultiplyingFoundValuesByTwo();
        int[] nums1 = { 5, 3, 6, 1, 12 };
        int original1 = 3;
        System.out.println(s.findFinalValue(nums1, original1) + " 24");
        int[] nums2 = { 2, 7, 9 };
        int original2 = 4;
        System.out.println(s.findFinalValue(nums2, original2) + " 4");
    }
}
