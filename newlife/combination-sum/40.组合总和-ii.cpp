/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.68%)
 * Likes:    1335
 * Dislikes: 0
 * Total Accepted:    424.7K
 * Total Submissions: 709.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>&& path, int start, int target){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if(target<0) return;
        for(int i=start;i<nums.size();i++) {
            if(i>start && nums[i-1] == nums[i]) continue;
            path.push_back(nums[i]);
            backtrack(ans, nums, std::move(path), i+1, target-nums[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, candidates, {}, 0, target);
        return ans;
    }
};
// @lc code=end

