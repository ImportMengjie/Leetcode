/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 *
 * https://leetcode-cn.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (62.59%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 15.9K
 * Testcase Example:  '["Solution","pick"]\n[[[1,2,3,3,3]],[3]]'
 *
 * 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。
 * 
 * 注意：
 * 数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。
 * 
 * 示例:
 * 
 * 
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 * 
 * // pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
 * solution.pick(3);
 * 
 * // pick(1) 应该返回 0。因为只有nums[0]等于1。
 * solution.pick(1);
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums):nums(nums) {}
    
    int pick(int target) {
        int ret = -1;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                count++;
                if(rand()%count==0)
                    ret = i;
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

