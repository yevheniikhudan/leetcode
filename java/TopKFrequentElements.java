import java.util.*;

public class TopKFrequentElements {
    public int[] topKFrequent(int[] nums, int k) {
        // ...existing code...
        return new int[0];
    }

    public static void main(String[] args) {
        TopKFrequentElements s = new TopKFrequentElements();

        int[] nums1 = { 1, 1, 1, 2, 2, 3 };
        int k1 = 2;
        System.out.println(Arrays.toString(s.topKFrequent(nums1, k1)));

        int[] nums2 = { 1 };
        int k2 = 1;
        System.out.println(Arrays.toString(s.topKFrequent(nums2, k2)));
    }
}
