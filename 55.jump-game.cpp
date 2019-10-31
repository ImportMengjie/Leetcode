/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int end = 0, max_positon = 0;
        for (int i = 0; i < nums.size() && end >= i; i++)
        {
            max_positon = max(max_positon, nums[i] + i);
            if (end == i)
                end = max_positon;
        }
        return end >= nums.size() - 1;
    }
};
// @lc code=end
