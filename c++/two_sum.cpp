#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int x = target - num;

            if (seen.count(x))
            {
                return {seen[x], i};
            }

            seen[num] = i;
        }

        return {-1, -1};
    }
};

int main()
{
    Solution s;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = s.twoSum(nums1, target1);
    cout << "[" << result1[0] << "," << result1[1] << "] [0,1]" << endl;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = s.twoSum(nums2, target2);
    cout << "[" << result2[0] << "," << result2[1] << "] [1,2]" << endl;

    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = s.twoSum(nums3, target3);
    cout << "[" << result3[0] << "," << result3[1] << "] [0,1]" << endl;

    return 0;
}