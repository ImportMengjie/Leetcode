/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.10%)
 * Likes:    3639
 * Dislikes: 0
 * Total Accepted:    606K
 * Total Submissions: 1.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i-1]==nums[i])
                continue;
            int j = i+1, k=nums.size()-1;
            while(j<k){
                int t = nums[i] + nums[j] + nums[k];
                if(t==0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j<k&&nums[j]==nums[j-1])
                        j++;
                    while(j<k&&nums[k]==nums[k+1])
                        k--;
                }else if (t<0)
                    j++;
                else k--;
            }
        }
        return ans;
    }
};
// @lc code=end

