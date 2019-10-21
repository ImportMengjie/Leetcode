/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int maxValue(int left, int right, vector<int> &nums)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;
            int max_left = maxValue(left, mid - 1, nums);
            int max_right = maxValue(mid + 1, right, nums);
            int max_other = max(max_left, max_right);
            int max_mid_left = nums[mid];
            int max_mid_right = 0;
            int m = mid;
            int t = 0;
            while (m >= left)
            {
                t += nums[m];
                max_mid_left = max(max_mid_left, t);
                m--;
            }
            m = mid + 1;
            t = 0;
            while (m <= right)
            {
                t += nums[m];
                max_mid_right = max(max_mid_right, t);
                m++;
            }
            return max(max_mid_left + max_mid_right, max_other);
        }
        else
            return nums[left];
    }

    int maxSubArray(vector<int> &nums)
    {
        return maxValue(0, nums.size() - 1, nums);
    }
};
// @lc code=end
