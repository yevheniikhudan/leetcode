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

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Calculate the number of car fleets that arrive at the destination.
     *
     * @param target Distance to the destination in miles
     * @param position Vector of starting positions for each car
     * @param speed Vector of speeds for each car (miles per hour)
     * @return Number of car fleets that arrive at the destination
     *
     * Time Complexity: O(n log n) where n = position.size()
     * Space Complexity: O(n) for sorting and storing pairs
     */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Create pairs of (position, time) and store in vector
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort by position in descending order (closest to target first)
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        // Stack to track arrival times of fleet leaders
        stack<double> stk;

        for (const auto& car : cars) {
            double time = car.second;

            // If this car takes longer than the previous fleet leader,
            // it forms a new fleet (can't catch up)
            if (stk.empty() || time > stk.top()) {
                stk.push(time);
            }
            // Otherwise, it catches up to the previous fleet (don't add to stack)
        }

        return stk.size();
    }
};

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> pos1 = {10, 8, 0, 5, 3};
    vector<int> speed1 = {2, 4, 1, 1, 3};
    int result1 = solution.carFleet(12, pos1, speed1);
    cout << "Test 1: " << result1 << " (expected: 3)\n";

    // Test case 2: Example 2 - Single car
    vector<int> pos2 = {3};
    vector<int> speed2 = {3};
    int result2 = solution.carFleet(10, pos2, speed2);
    cout << "Test 2: " << result2 << " (expected: 1)\n";

    // Test case 3: Example 3 - All cars merge into one fleet
    vector<int> pos3 = {0, 2, 4};
    vector<int> speed3 = {4, 2, 1};
    int result3 = solution.carFleet(100, pos3, speed3);
    cout << "Test 3: " << result3 << " (expected: 1)\n";

    // Test case 4: All separate fleets (times increase from closest to farthest)
    vector<int> pos4 = {8, 5, 0};
    vector<int> speed4 = {1, 2, 3};
    int result4 = solution.carFleet(10, pos4, speed4);
    cout << "Test 4: " << result4 << " (expected: 3)\n";

    // Test case 5: All same speed
    vector<int> pos5 = {6, 8};
    vector<int> speed5 = {3, 3};
    int result5 = solution.carFleet(10, pos5, speed5);
    cout << "Test 5: " << result5 << " (expected: 2)\n";

    // Test case 6: Two cars, faster behind
    vector<int> pos6 = {0, 5};
    vector<int> speed6 = {3, 2};
    int result6 = solution.carFleet(10, pos6, speed6);
    cout << "Test 6: " << result6 << " (expected: 2)\n";

    // Test case 7: Two cars, same arrival time
    vector<int> pos7 = {0, 4};
    vector<int> speed7 = {2, 1};
    int result7 = solution.carFleet(10, pos7, speed7);
    cout << "Test 7: " << result7 << " (expected: 1)\n";

    // Test case 8: Multiple fleets
    vector<int> pos8 = {6, 2, 17};
    vector<int> speed8 = {3, 9, 2};
    int result8 = solution.carFleet(20, pos8, speed8);
    cout << "Test 8: " << result8 << " (expected: 2)\n";
}

int main() {
    runTests();
    return 0;
}
