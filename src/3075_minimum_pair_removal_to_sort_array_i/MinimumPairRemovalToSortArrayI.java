import java.util.*;

public class MinimumPairRemovalToSortArrayI {
    public int minimumPairRemoval(int[] nums) {
        List<Integer> arr = new ArrayList<>();
        for (int num : nums)
            arr.add(num);
        int count = 0;
        while (true) {
            int n = arr.size();
            if (n <= 1)
                break;
            boolean sorted = true;
            for (int i = 0; i < n - 1; i++) {
                if (arr.get(i) > arr.get(i + 1)) {
                    sorted = false;
                    break;
                }
            }
            if (sorted)
                break;
            int minSum = Integer.MAX_VALUE, minIdx = -1;
            for (int i = 0; i < n - 1; i++) {
                int pairSum = arr.get(i) + arr.get(i + 1);
                if (pairSum < minSum) {
                    minSum = pairSum;
                    minIdx = i;
                }
            }
            arr.set(minIdx, arr.get(minIdx) + arr.get(minIdx + 1));
            arr.remove(minIdx + 1);
            count++;
        }
        return count;
    }

    // Test scaffolding
    public static void main(String[] args) {
        MinimumPairRemovalToSortArrayI sol = new MinimumPairRemovalToSortArrayI();
        System.out.println(sol.minimumPairRemoval(new int[] { 5, 2, 3, 1 }) + " | 2");
        System.out.println(sol.minimumPairRemoval(new int[] { 1, 2, 2 }) + " | 0");
        System.out.println(sol.minimumPairRemoval(new int[] { 1 }) + " | 0");
        System.out.println(sol.minimumPairRemoval(new int[] { 2, 1 }) + " | 1");
        System.out.println(sol.minimumPairRemoval(new int[] { 3, 1, 2 }) + " | 1");
    }
}
