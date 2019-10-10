/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[left])
            {
                if (nums[mid] > target && nums[left] <= target)
                    right = mid;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return (left == right && nums[left] == target) ? left : -1;
    }
};
// @lc code=end
