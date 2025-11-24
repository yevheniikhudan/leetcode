import java.util.*;

public class BinaryPrefixDivisibleBy5 {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new ArrayList<>();
        int cur = 0;

        for (int num : nums) {
            cur = ((cur << 1) + num) % 5;
            ans.add(cur % 5 == 0);
        }

        return ans;
    }

    public static void main(String[] args) {
        BinaryPrefixDivisibleBy5 s = new BinaryPrefixDivisibleBy5();

        int[] nums1 = { 0, 1, 1 };
        System.out.println(s.prefixesDivBy5(nums1));

        int[] nums2 = { 1, 1, 1 };
        System.out.println(s.prefixesDivBy5(nums2));
    }
}
