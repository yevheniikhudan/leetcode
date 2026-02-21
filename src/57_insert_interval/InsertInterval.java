import java.util.*;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        java.util.List<int[]> res = new java.util.ArrayList<>();
        int n = intervals.length;
        for (int i = 0; i < n; ++i) {
            if (newInterval[1] < intervals[i][0]) {
                res.add(newInterval);
                while (i < n)
                    res.add(intervals[i++]);
                return res.toArray(new int[res.size()][]);
            } else if (newInterval[0] > intervals[i][1]) {
                res.add(intervals[i]);
            } else {
                newInterval = new int[] {
                        Math.min(newInterval[0], intervals[i][0]),
                        Math.max(newInterval[1], intervals[i][1])
                };
            }
        }
        res.add(newInterval);
        return res.toArray(new int[res.size()][]);
    }
}

public class InsertInterval {
    public static void main(String[] args) {
        Solution sol = new Solution();

        List<int[]> in1 = Arrays.asList(new int[] { 1, 3 }, new int[] { 6, 9 });
        System.out.println(sol.insert(in1, new int[] { 2, 5 }) + " | [[1,5],[6,9]]");

        List<int[]> in2 = Arrays.asList(new int[] { 1, 2 }, new int[] { 3, 5 }, new int[] { 6, 7 }, new int[] { 8, 10 },
                new int[] { 12, 16 });
        System.out.println(sol.insert(in2, new int[] { 4, 8 }) + " | [[1,2],[3,10],[12,16]]");

        List<int[]> in3 = new ArrayList<>();
        System.out.println(sol.insert(in3, new int[] { 5, 7 }) + " | [[5,7]]");

        List<int[]> in4 = Arrays.asList(new int[] { 1, 5 });
        System.out.println(sol.insert(in4, new int[] { 2, 3 }) + " | [[1,5]]");

        List<int[]> in5 = Arrays.asList(new int[] { 1, 2 }, new int[] { 3, 4 });
        System.out.println(sol.insert(in5, new int[] { 5, 6 }) + " | [[1,2],[3,4],[5,6]]");
    }
}
