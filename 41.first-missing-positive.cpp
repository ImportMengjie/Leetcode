/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        bool is_include_one = false;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 1)
                is_include_one = true;
        if (!is_include_one)
            return 1;
        if (nums.size() == 1)
            return 2;

        for (int &i : nums)
            if (i <= 0 || i > nums.size())
                i = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = abs(nums[i]);
            a = a == nums.size() ? 0 : a;
            if (nums[a] > 0)
                nums[a] = -nums[a];
        }

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > 0)
                return i;
        if (nums[0] > 0)
            return nums.size();
        return nums.size() + 1;
    }
};
// @lc code=end
