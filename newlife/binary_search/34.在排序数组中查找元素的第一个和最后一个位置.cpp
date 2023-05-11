/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.36%)
 * Likes:    2290
 * Dislikes: 0
 * Total Accepted:    785.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        if(left == nums.end() || *left!=target) return {-1, -1};
        auto right = lower_bound(left, nums.end(), target+1);
        return {static_cast<int>(left-nums.begin()), static_cast<int>(right-nums.begin())-1};
    }

    vector<int> searchRange1(vector<int>& nums, int target) {

        auto lowerbound = [](vector<int>& nums, int target)->int{
            int left = 0, right = nums.size() - 1, ans = nums.size();
            while(left<=right) {
                int mid = left + (right - left)/2;
                if(nums[mid]>=target) {
                    right = mid - 1;
                    ans = mid;
                } else left = mid + 1;
            }
            return ans;
        };
        int lower_idx = lowerbound(nums, target);
        if(lower_idx>=nums.size()||nums[lower_idx]!=target) return {-1, -1};
        int upper_idx = lowerbound(nums, target+1) - 1;
        return {lower_idx, upper_idx};
    }
};
// @lc code=end

