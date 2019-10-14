/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int end = 0, step = 0, max_positon = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            max_positon = max(max_positon, nums[i] + i);
            if (i == end)
            {
                end = max_positon;
                step++;
            }
        }
        return step;
    }
};
// @lc code=end
