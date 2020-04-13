/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.49%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 47.8K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:

    vector<vector<int>> result;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};
// @lc code=end

