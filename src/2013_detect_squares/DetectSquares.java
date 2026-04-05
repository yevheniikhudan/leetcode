import java.util.HashMap;
import java.util.Map;

/**
 * DetectSquares implementation using an immutable PointKey as map key.
 *
 * - Count of points is stored in a nested map: x -> (y -> count)
 * - For a query (x,y), iterate over all existing y2 with same x.
 *   side = |y2 - y|
 *   check columns x+side and x-side for the complementary corners and multiply frequencies:
 *     freq_vertical * freq_corner1 * freq_corner2
 *
 * This file replaces java.awt.Point usage with an immutable PointKey and
 * provides DetectSquaresDS as the data structure. The public class DetectSquares
 * contains a main() with test scaffolding that prints results in the project's
 * required format: actual | expected | PASS/FAIL
 */
final class PointKey {

    private final int x;
    private final int y;

    PointKey(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int x() {
        return x;
    }

    int y() {
        return y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof PointKey)) return false;
        PointKey p = (PointKey) o;
        return x == p.x && y == p.y;
    }

    @Override
    public int hashCode() {
        // simple but effective hash for pair of ints
        return 31 * x + y;
    }

    @Override
    public String toString() {
        return "[" + x + "," + y + "]";
    }
}

/**
 * DetectSquaresDS - data structure for adding points and counting axis-aligned squares.
 */
class DetectSquaresDS {

    // x -> (y -> count)
    private final Map<Integer, Map<Integer, Integer>> cols;

    DetectSquaresDS() {
        this.cols = new HashMap<>();
    }

    /**
     * Add a point. Duplicates increment frequency.
     * @param point int[2] {x, y}
     */
    public void add(int[] point) {
        int x = point[0];
        int y = point[1];
        cols.computeIfAbsent(x, k -> new HashMap<>());
        Map<Integer, Integer> col = cols.get(x);
        col.put(y, col.getOrDefault(y, 0) + 1);
    }

    /**
     * Count squares that have the given point as one corner.
     * @param point int[2] {x, y}
     * @return number of squares (taking multiplicities into account)
     */
    public int count(int[] point) {
        int x = point[0];
        int y = point[1];

        Map<Integer, Integer> sameX = cols.get(x);
        if (sameX == null) return 0;

        int result = 0;

        // For every point (x, y2) that shares the same x (vertical partner)
        for (Map.Entry<Integer, Integer> entry : sameX.entrySet()) {
            int y2 = entry.getKey();
            int freqVertical = entry.getValue(); // number of points at (x, y2)

            if (y2 == y) continue; // same point, skip

            int side = Math.abs(y2 - y);
            int xRight = x + side;
            int xLeft = x - side;

            // Check right column (x + side)
            Map<Integer, Integer> rightCol = cols.get(xRight);
            if (rightCol != null) {
                int freqA = rightCol.getOrDefault(y, 0); // (x+side, y)
                int freqB = rightCol.getOrDefault(y2, 0); // (x+side, y2)
                if (freqA > 0 && freqB > 0) {
                    result += freqVertical * freqA * freqB;
                }
            }

            // Check left column (x - side)
            Map<Integer, Integer> leftCol = cols.get(xLeft);
            if (leftCol != null) {
                int freqA = leftCol.getOrDefault(y, 0); // (x-side, y)
                int freqB = leftCol.getOrDefault(y2, 0); // (x-side, y2)
                if (freqA > 0 && freqB > 0) {
                    result += freqVertical * freqA * freqB;
                }
            }
        }

        return result;
    }
}

/**
 * Public test harness for DetectSquares.
 * Prints results in the format: actual | expected | PASS/FAIL
 */
public class DetectSquares {

    private static void printResult(int actual, int expected) {
        System.out.println(
            actual +
                " | " +
                expected +
                " | " +
                (actual == expected ? "PASS" : "FAIL")
        );
    }

    public static void main(String[] args) {
        // Example test: the previously failing sequence
        {
            DetectSquaresDS ds = new DetectSquaresDS();
            ds.add(new int[] { 3, 10 });
            ds.add(new int[] { 11, 2 });
            ds.add(new int[] { 3, 2 });
            int r1 = ds.count(new int[] { 11, 10 }); // expect 1
            printResult(r1, 1);

            int r2 = ds.count(new int[] { 14, 8 }); // expect 0
            printResult(r2, 0);

            ds.add(new int[] { 11, 2 }); // duplicate
            int r3 = ds.count(new int[] { 11, 10 }); // expect 2 (because (11,2) has count 2)
            printResult(r3, 2);
        }

        // Additional sanity tests

        // Test 1: Basic square detection
        {
            DetectSquaresDS ds1 = new DetectSquaresDS();
            ds1.add(new int[] { 4, 6 });
            ds1.add(new int[] { 9, 6 });
            ds1.add(new int[] { 4, 2 });
            ds1.add(new int[] { 9, 2 });
            int result1 = ds1.count(new int[] { 4, 6 });
            printResult(result1, 1);
        }

        // Test 2: No square exists (query a point not present)
        {
            DetectSquaresDS ds1 = new DetectSquaresDS();
            ds1.add(new int[] { 4, 6 });
            ds1.add(new int[] { 9, 6 });
            int result2 = ds1.count(new int[] { 0, 0 });
            printResult(result2, 0);
        }

        // Test 3: Duplicate points create multiple squares
        {
            DetectSquaresDS ds2 = new DetectSquaresDS();
            ds2.add(new int[] { 9, 9 });
            ds2.add(new int[] { 9, -1 });
            ds2.add(new int[] { 1, 9 });
            ds2.add(new int[] { 1, -1 });
            int result4 = ds2.count(new int[] { 9, 9 });
            printResult(result4, 1);

            ds2.add(new int[] { 9, -1 }); // duplicate
            int result5 = ds2.count(new int[] { 9, 9 });
            printResult(result5, 2);
        }

        // Test 4: Unit square
        {
            DetectSquaresDS ds3 = new DetectSquaresDS();
            ds3.add(new int[] { 0, 0 });
            ds3.add(new int[] { 1, 0 });
            ds3.add(new int[] { 0, 1 });
            ds3.add(new int[] { 1, 1 });
            int result6 = ds3.count(new int[] { 0, 0 });
            printResult(result6, 1);
        }
    }
}
