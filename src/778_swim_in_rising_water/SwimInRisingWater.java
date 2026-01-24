import java.util.*;

class Solution {
    public int swimInWater(int[][] grid) {
        // TODO: Implement the solution
        return -1;
    }
}

public class SwimInRisingWater {
    public static void main(String[] args) {
        testSwimInWater();
    }

    // Test helper
    public static void testSwimInWater() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int[][] grid1 = { { 0, 2 }, { 1, 3 } };
        int expected1 = 3;
        int actual1 = solution.swimInWater(grid1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int[][] grid2 = {
                { 0, 1, 2, 3, 4 },
                { 24, 23, 22, 21, 5 },
                { 12, 13, 14, 15, 16 },
                { 11, 17, 18, 19, 20 },
                { 10, 9, 8, 7, 6 }
        };
        int expected2 = 16;
        int actual2 = solution.swimInWater(grid2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: n=1
        int[][] grid3 = { { 5 } };
        int expected3 = 5;
        int actual3 = solution.swimInWater(grid3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: 2x2 simple
        int[][] grid4 = { { 0, 1 }, { 2, 3 } };
        int expected4 = 3;
        int actual4 = solution.swimInWater(grid4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Already connected
        int[][] grid5 = { { 0, 0 }, { 0, 0 } };
        int expected5 = 0;
        int actual5 = solution.swimInWater(grid5);
        System.out.println(actual5 + " | " + expected5);
    }
}
