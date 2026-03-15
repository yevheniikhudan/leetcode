import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    class PQElement {
        int intervalSize;
        int rightIndex;

        public PQElement(int intervalSize, int rightIndex) {
            this.intervalSize = intervalSize;
            this.rightIndex = rightIndex;
        }
    }

    public int[] minInterval(int[][] intervals, int[] queries) {
        Arrays.sort(intervals, Comparator.comparingInt(x -> x[0]));
        int[] sortedQueries = Arrays.copyOf(queries, queries.length);
        Arrays.sort(sortedQueries);

        Map<Integer, Integer> minIntervals = new HashMap<>();
        PriorityQueue<PQElement> pq = new PriorityQueue<>((a, b) -> a.intervalSize - b.intervalSize);
        int i = 0;
        for (int query : sortedQueries) {
            while (i < intervals.length && intervals[i][0] <= query) {
                pq.offer(new PQElement(intervalSize(intervals[i]), intervals[i][1]));
                i++;
            }
            while (pq.size() > 0 && pq.peek().rightIndex < query) {
                pq.poll();
            }
            minIntervals.put(query, pq.size() > 0 ? pq.peek().intervalSize : -1);
        }

        int[] res = new int[queries.length];
        for (int j = 0; j < queries.length; j++) {
            res[j] = minIntervals.get(queries[j]);
        }
        return res;
    }

    private int intervalSize(int[] interval) {
        return interval[1] - interval[0] + 1;
    }
}

public class MinimumIntervalToIncludeEachQuery {
    private static int[][] copy2D(int[][] source) {
        int[][] copy = new int[source.length][];
        for (int i = 0; i < source.length; i++) {
            copy[i] = Arrays.copyOf(source[i], source[i].length);
        }
        return copy;
    }

    private static String arrayToString(int[] values) {
        return Arrays.toString(values);
    }

    private static void runTests() {
        Solution sol = new Solution();
        int[][][] intervalInputs = {
                { { 1, 4 }, { 2, 4 }, { 3, 6 }, { 4, 4 } },
                { { 2, 3 }, { 2, 5 }, { 1, 8 }, { 20, 25 } },
                { { 1, 2 } },
                { { 5, 10 }, { 1, 3 } },
                { { 1, 1 }, { 2, 2 }, { 3, 3 } },
                { { 1, 10000000 } }
        };
        int[][] queryInputs = {
                { 2, 3, 4, 5 },
                { 2, 19, 5, 22 },
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 1, 2, 3 },
                { 1, 5000000, 10000000 }
        };
        int[][] expecteds = {
                { 3, 3, 1, 4 },
                { 2, -1, 4, 6 },
                { 2, 2, -1 },
                { -1, 6, 6 },
                { 1, 1, 1 },
                { 10000000, 10000000, 10000000 }
        };

        for (int i = 0; i < intervalInputs.length; i++) {
            int[] actual = sol.minInterval(copy2D(intervalInputs[i]),
                    Arrays.copyOf(queryInputs[i], queryInputs[i].length));
            System.out.println(arrayToString(actual) + " | " + arrayToString(expecteds[i]));
        }
    }

    public static void main(String[] args) {
        runTests();
    }
}
