#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Two Sum II - Input Array Is Sorted
     *
     * @param numbers Sorted list of integers (1-indexed)
     * @param target Target sum
     * @return 1-indexed positions [index1, index2]
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int cur = numbers[left] + numbers[right];

            if (cur == target) {
                return {left + 1, right + 1};
            } else if (cur < target) {
                left++;
            } else {
                right--;
            }
        }

        return {-1, -1};
    }
};

void test_two_sum_ii() {
    Solution solution;

    // Test case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    cout << "Test 1: [2,7,11,15], target=9 -> [" << result1[0] << "," << result1[1] << "]" << endl;
    assert(result1 == vector<int>({1, 2}));

    // Test case 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    cout << "Test 2: [2,3,4], target=6 -> [" << result2[0] << "," << result2[1] << "]" << endl;
    assert(result2 == vector<int>({1, 3}));

    // Test case 3
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    cout << "Test 3: [-1,0], target=-1 -> [" << result3[0] << "," << result3[1] << "]" << endl;
    assert(result3 == vector<int>({1, 2}));

    // Test case 4: Larger array
    vector<int> numbers4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target4 = 17;
    vector<int> result4 = solution.twoSum(numbers4, target4);
    cout << "Test 4: [1,2,3,4,5,6,7,8,9], target=17 -> [" << result4[0] << "," << result4[1] << "]"
         << endl;
    assert(result4 == vector<int>({8, 9}));

    // Test case 5: Negative numbers
    vector<int> numbers5 = {-5, -3, -1, 0, 2, 4};
    int target5 = -4;
    vector<int> result5 = solution.twoSum(numbers5, target5);
    cout << "Test 5: [-5,-3,-1,0,2,4], target=-4 -> [" << result5[0] << "," << result5[1] << "]"
         << endl;
    assert(result5 == vector<int>({2, 3}));

    cout << "All test cases passed!" << endl;
}

int main() {
    test_two_sum_ii();
    return 0;
}
