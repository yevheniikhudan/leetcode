import java.util.*;

class Solution {
    public List<Integer> partitionLabels(String S) {
        Map<Character, Integer> lastIndex = new HashMap<>();
        int n = S.length();

        for (int i = 0; i < n; i++) {
            lastIndex.put(S.charAt(i), i);
        }

        int start = 0, end = 0;
        List<Integer> partitions = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            end = Math.max(end, lastIndex.get(S.charAt(i)));

            if (i == end) {
                partitions.add(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
    }
}

public class PartitionLabels {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String s1 = "ababcbacadefegdehijhklij";
        System.out.println(sol.partitionLabels(s1) + " | " + Arrays.toString(new Integer[] { 9, 7, 8 }));

        String s2 = "eccbbbbdec";
        System.out.println(sol.partitionLabels(s2) + " | " + Arrays.toString(new Integer[] { 10 }));

        String s3 = "qwerty";
        System.out.println(sol.partitionLabels(s3) + " | " + Arrays.toString(new Integer[] { 1, 1, 1, 1, 1, 1 }));

        String s4 = "abca";
        System.out.println(sol.partitionLabels(s4) + " | " + Arrays.toString(new Integer[] { 4 }));

        String s5 = "";
        System.out.println(sol.partitionLabels(s5) + " | " + Arrays.toString(new Integer[] {}));
    }
}
