/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int find_range(vector<int> &nums, int target, bool left)
    {
        int low = 0, high = nums.size();
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target || (left && nums[mid] == target))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = find_range(nums, target, true);
        if (left >= nums.size() || nums[left] != target)
            return {-1, -1};
        int right = find_range(nums, target, false) - 1;
        return {left, right};
    }
};
// @lc code=end
