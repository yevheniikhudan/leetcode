/*
875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the i-th pile has 
piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses 
some pile of bananas and eats k bananas from that pile. If the pile has less 
than k bananas, she eats all of them instead and will not eat any more bananas 
during this hour.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

class Solution {
    /**
     * Find minimum eating speed to finish all bananas within h hours.
     * 
     * @param piles Array of banana pile sizes
     * @param h     Hours available
     * @return Minimum eating speed k
     * 
     *         Time Complexity: O(n log m) where n = piles.length, m = max(piles)
     *         Space Complexity: O(1) - only constant extra space
     */
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1, right = 0;
        for (int pile : piles) {
            right = Math.max(right, pile);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;

            long total = 0;
            for (int pile : piles) {
                total += (pile + mid - 1) / mid;
            }

            if (total <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

public class KokoEatingBananas {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int result1 = solution.minEatingSpeed(new int[] { 3, 6, 7, 11 }, 8);
        System.out.println("Test 1: " + result1 + " (expected: 4)");

        // Test case 2: Example 2 - must eat one pile per hour
        int result2 = solution.minEatingSpeed(new int[] { 30, 11, 23, 4, 20 }, 5);
        System.out.println("Test 2: " + result2 + " (expected: 30)");

        // Test case 3: Example 3
        int result3 = solution.minEatingSpeed(new int[] { 30, 11, 23, 4, 20 }, 6);
        System.out.println("Test 3: " + result3 + " (expected: 23)");

        // Test case 4: Single pile
        int result4 = solution.minEatingSpeed(new int[] { 1000000000 }, 2);
        System.out.println("Test 4: " + result4 + " (expected: 500000000)");

        // Test case 5: Many hours available
        int result5 = solution.minEatingSpeed(new int[] { 3, 6, 7, 11 }, 100);
        System.out.println("Test 5: " + result5 + " (expected: 1)");

        // Test case 6: Exact hours match piles
        int result6 = solution.minEatingSpeed(new int[] { 5, 10, 15, 20 }, 4);
        System.out.println("Test 6: " + result6 + " (expected: 20)");

        // Test case 7: All same size piles
        int result7 = solution.minEatingSpeed(new int[] { 10, 10, 10, 10 }, 10);
        System.out.println("Test 7: " + result7 + " (expected: 5)");

        // Test case 8: Small piles, exact hours match piles
        int result8 = solution.minEatingSpeed(new int[] { 1, 1, 1, 1 }, 4);
        System.out.println("Test 8: " + result8 + " (expected: 1)");
    }
}
