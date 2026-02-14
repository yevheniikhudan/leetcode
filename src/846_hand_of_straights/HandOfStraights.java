import java.util.*;

class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0)
            return false;
        TreeMap<Integer, Integer> count = new TreeMap<>();
        for (int h : hand)
            count.put(h, count.getOrDefault(h, 0) + 1);
        while (!count.isEmpty()) {
            int start = count.firstKey();
            int cnt = count.get(start);
            for (int i = 0; i < groupSize; ++i) {
                int key = start + i;
                if (!count.containsKey(key))
                    return false;
                int val = count.get(key);
                if (val < cnt)
                    return false;
                if (val == cnt)
                    count.remove(key);
                else
                    count.put(key, val - cnt);
            }
        }
        return true;
    }
}

public class HandOfStraights {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.isNStraightHand(new int[] { 1, 2, 3, 6, 2, 3, 4, 7, 8 }, 3) + " | True");
        System.out.println(sol.isNStraightHand(new int[] { 1, 2, 3, 4, 5 }, 4) + " | False");
        System.out.println(sol.isNStraightHand(new int[] { 1, 1, 2, 2, 3, 3 }, 3) + " | True");
        System.out.println(sol.isNStraightHand(new int[] { 1, 2, 3, 4 }, 2) + " | True");
        System.out.println(sol.isNStraightHand(new int[] { 1 }, 1) + " | True");
    }
}
