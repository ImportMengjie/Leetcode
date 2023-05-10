/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (63.57%)
 * Likes:    774
 * Dislikes: 0
 * Total Accepted:    197.8K
 * Total Submissions: 311.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>&& path, vector<bool>& used){
        if(path.size()==nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!used[i]){
                if(i>0&&(!used[i-1]&&nums[i-1]==nums[i])) continue;
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(ans, nums, std::move(path), used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(ans, nums, {}, used);
        return ans;
    }
};
// @lc code=end

