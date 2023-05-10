/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (78.20%)
 * Likes:    1497
 * Dislikes: 0
 * Total Accepted:    386.9K
 * Total Submissions: 494.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有整数 互不相同
 * 
 * 
 */
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>&& path, set<int>&& pick){
        if(path.size()==nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!pick.count(nums[i])){
                path.push_back(nums[i]);
                pick.insert(nums[i]);
                backtrack(ans, nums, std::move(path), std::move(pick));
                path.pop_back();
                pick.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, {}, {});
        return ans;
    }
};
// @lc code=end

