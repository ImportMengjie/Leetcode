/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left, left_max, right = height.size() - 1, right_max, ans;
        left = left_max = right_max = ans = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    ans += left_max - height[left];
                left++;
            }
            else
            {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end
