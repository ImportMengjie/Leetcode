/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int t = nums[i] + nums[j] + nums[k] - target;
                if (t == 0)
                    return target;
                else if (t < 0)
                {
                    if (abs(closest - target) > -t)
                        closest = t + target;
                    j++;
                }
                else
                {
                    if (abs(closest - target) > t)
                        closest = t + target;
                    k--;
                }
            }
        }
        return closest;
    }
};
