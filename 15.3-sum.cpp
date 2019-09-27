/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int t = nums[i] + nums[j] + nums[k];
                if (t == 0)
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (t < 0)
                    j++;
                else
                    k--;
            }
        }
        return ret;
    }
};
