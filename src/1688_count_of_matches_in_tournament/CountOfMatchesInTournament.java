class Solution {
    public int numberOfMatches(int n) {
        return n - 1;
    }
}

public class CountOfMatchesInTournament {
    public static void main(String[] args) {
        testNumberOfMatches();
    }

    public static void testNumberOfMatches() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int n1 = 7;
        int expected1 = 6;
        int actual1 = solution.numberOfMatches(n1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        int n2 = 14;
        int expected2 = 13;
        int actual2 = solution.numberOfMatches(n2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: n=1
        int n3 = 1;
        int expected3 = 0;
        int actual3 = solution.numberOfMatches(n3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: n=2
        int n4 = 2;
        int expected4 = 1;
        int actual4 = solution.numberOfMatches(n4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: n=3
        int n5 = 3;
        int expected5 = 2;
        int actual5 = solution.numberOfMatches(n5);
        System.out.println(actual5 + " | " + expected5);

        // Test case 6: n=4
        int n6 = 4;
        int expected6 = 3;
        int actual6 = solution.numberOfMatches(n6);
        System.out.println(actual6 + " | " + expected6);
    }
}
