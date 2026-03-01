import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        List<int[]> res = new ArrayList<>();

        for (int[] interval : intervals) {
            if (res.size() == 0 || interval[0] > res.get(res.size() - 1)[1]) {
                res.add(interval);
            } else {
                int[] last = res.removeLast();
                last[1] = Math.max(last[1], interval[1]);
                res.add(last);
            }
        }
        return res.toArray(new int[res.size()][]);
    }
}

class MergeIntervals {
    public static void main(String[] args) {
        runTests();
    }

    private static void runTests() {
        Solution sol = new Solution();
        List<int[][]> inputs = Arrays.asList(
                new int[][] { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } },
                new int[][] { { 1, 4 }, { 4, 5 } },
                new int[][] { { 4, 7 }, { 1, 4 } },
                new int[][] { { 1, 3 } },
                new int[][] { { 1, 2 }, { 3, 4 }, { 5, 6 } },
                new int[][] { { 1, 10 }, { 2, 3 }, { 4, 5 }, { 6, 7 } });
        List<int[][]> expecteds = Arrays.asList(
                new int[][] { { 1, 6 }, { 8, 10 }, { 15, 18 } },
                new int[][] { { 1, 5 } },
                new int[][] { { 1, 7 } },
                new int[][] { { 1, 3 } },
                new int[][] { { 1, 2 }, { 3, 4 }, { 5, 6 } },
                new int[][] { { 1, 10 } });

        for (int i = 0; i < inputs.size(); i++) {
            int[][] actual = sol.merge(inputs.get(i));
            System.out.println(Arrays.deepToString(actual) + " | " + Arrays.deepToString(expecteds.get(i)));
        }
    }
}
