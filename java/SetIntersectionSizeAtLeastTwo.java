import java.util.Arrays;

public class SetIntersectionSizeAtLeastTwo {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if (a[1] == b[1]) {
                return Integer.compare(b[0], a[0]);
            }

            return Integer.compare(a[1], b[1]);
        });

        int res = 0;
        int p1 = -1, p2 = -1;

        for (int[] interval : intervals) {
            int left = interval[0], right = interval[1];

            if (p2 < left) {
                res += 2;
                p2 = right;
                p1 = right - 1;
            } else if (p1 < left) {
                res += 1;
                p1 = p2;
                p2 = right;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        SetIntersectionSizeAtLeastTwo s = new SetIntersectionSizeAtLeastTwo();
        int[][] intervals1 = { { 1, 3 }, { 3, 7 }, { 8, 9 } };
        System.out.println(s.intersectionSizeTwo(intervals1) + " 5");
        int[][] intervals2 = { { 1, 3 }, { 1, 4 }, { 2, 5 }, { 3, 5 } };
        System.out.println(s.intersectionSizeTwo(intervals2) + " 3");
        int[][] intervals3 = { { 1, 2 }, { 2, 3 }, { 2, 4 }, { 4, 5 } };
        System.out.println(s.intersectionSizeTwo(intervals3) + " 5");
    }
}
