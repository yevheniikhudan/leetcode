/*
853. Car Fleet

There are n cars going to the same destination along a one-lane road. The destination
is target miles away.

You are given two integer arrays position and speed, both of length n, where
position[i] is the position of the ith car and speed[i] is the speed of the ith car
(in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive
bumper to bumper at the same speed. The faster car will slow down to match the
slower car's speed. The distance between these two cars is ignored.

A car fleet is some non-empty set of cars driving at the same position and same speed.
Note that a single car is also a car fleet.

Return the number of car fleets that will arrive at the destination.
*/

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class Solution {
    /**
     * Calculate the number of car fleets that arrive at the destination.
     *
     * @param target   Distance to the destination in miles
     * @param position Array of starting positions for each car
     * @param speed    Array of speeds for each car (miles per hour)
     * @return Number of car fleets that arrive at the destination
     *
     *         Time Complexity: O(n log n) where n = position.length
     *         Space Complexity: O(n) for sorting and storing pairs
     */
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        Car[] cars = new Car[n];
        Deque<Double> stack = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            cars[i] = new Car(position[i], (double) (target - position[i]) / speed[i]);
        }

        Arrays.sort(cars, (a, b) -> Integer.compare(b.position, a.position));

        for (Car car : cars) {
            if (stack.isEmpty() || car.time > stack.peekLast()) {
                stack.addLast(car.time);
            }
        }

        return stack.size();
    }

    class Car {
        int position;
        double time;

        Car(int position, double time) {
            this.position = position;
            this.time = time;
        }
    }
}

public class CarFleet {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Example 1
        int result1 = solution.carFleet(12, new int[] { 10, 8, 0, 5, 3 }, new int[] { 2, 4, 1, 1, 3 });
        System.out.println("Test 1: " + result1 + " (expected: 3)");

        // Test case 2: Example 2 - Single car
        int result2 = solution.carFleet(10, new int[] { 3 }, new int[] { 3 });
        System.out.println("Test 2: " + result2 + " (expected: 1)");

        // Test case 3: Example 3 - All cars merge into one fleet
        int result3 = solution.carFleet(100, new int[] { 0, 2, 4 }, new int[] { 4, 2, 1 });
        System.out.println("Test 3: " + result3 + " (expected: 1)");

        // Test case 4: All separate fleets (times increase from closest to farthest)
        int result4 = solution.carFleet(10, new int[] { 8, 5, 0 }, new int[] { 1, 2, 3 });
        System.out.println("Test 4: " + result4 + " (expected: 3)");

        // Test case 5: All same speed
        int result5 = solution.carFleet(10, new int[] { 6, 8 }, new int[] { 3, 3 });
        System.out.println("Test 5: " + result5 + " (expected: 2)");

        // Test case 6: Two cars, faster behind
        int result6 = solution.carFleet(10, new int[] { 0, 5 }, new int[] { 3, 2 });
        System.out.println("Test 6: " + result6 + " (expected: 2)");

        // Test case 7: Two cars, same arrival time
        int result7 = solution.carFleet(10, new int[] { 0, 4 }, new int[] { 2, 1 });
        System.out.println("Test 7: " + result7 + " (expected: 1)");

        // Test case 8: Multiple fleets
        int result8 = solution.carFleet(20, new int[] { 6, 2, 17 }, new int[] { 3, 9, 2 });
        System.out.println("Test 8: " + result8 + " (expected: 2)");
    }
}
