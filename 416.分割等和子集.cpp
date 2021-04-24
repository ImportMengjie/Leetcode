/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    756
 * Dislikes: 0
 * Total Accepted:    120.5K
 * Total Submissions: 242.3K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int max_num = 0; int sum = 0;
        for(int& num:nums){
            sum += num;
            max_num = max(num, max_num);
        }
        if(sum%2||max_num>sum/2) return false;
        int target = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));
        dp[0][nums[0]] = true;
        for(int i=1; i<nums.size();i++){
            dp[i][0] = true;
            for(int j=1; j<target+1;j++){
                if(nums[i]<=j){
                    dp[i][j] = dp[i-1][j - nums[i]] || dp[i-1][j];
                }else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()-1][target];
    }
};
// @lc code=end

