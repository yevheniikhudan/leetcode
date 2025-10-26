#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        set<vector<int>> triplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            set<int> seen = {};
            for (int j = i + 1; j < nums.size(); j++)
            {
                int target = -(nums[j] + nums[i]);
                if (seen.count(target))
                {
                    triplets.insert({ nums[i], target, nums[j] });
                }

                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(triplets.begin(), triplets.end());
    }
};

void printResult(vector<vector<int>>& result)
{
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;

    vector<int> nums1 = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> result1 = s.threeSum(nums1);
    printResult(result1);
    cout << "Expected: [[-1,-1,2],[-1,0,1]]" << endl;

    vector<int> nums2 = { 0, 1, 1 };
    vector<vector<int>> result2 = s.threeSum(nums2);
    printResult(result2);
    cout << "Expected: []" << endl;

    vector<int> nums3 = { 0, 0, 0 };
    vector<vector<int>> result3 = s.threeSum(nums3);
    printResult(result3);
    cout << "Expected: [[0,0,0]]" << endl;

    return 0;
}
