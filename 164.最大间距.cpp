/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode-cn.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (54.82%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 25.4K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
 * 
 * 如果数组元素个数小于 2，则返回 0。
 * 
 * 示例 1:
 * 
 * 输入: [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 * 
 * 示例 2:
 * 
 * 输入: [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
 * 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
 * 
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.empty()||nums.size()<2)
            return 0;
        
        int exp = 1;
        int max_value = *max_element(nums.begin(),nums.end());

        vector<int> aux(nums.size());
        while (max_value/exp>0)
        {
            vector<int> count(10,0);
            for(int &n:nums)
                count[(n/exp)%10]++;
            
            for(int i=1;i<count.size();i++)
                count[i] += count[i-1];
            
            for(int i=nums.size()-1;i>=0;i--)
                aux[--count[(nums[i]/exp)%10]] = nums[i];
            
            for(int i=0;i<nums.size();i++)
                nums[i] = aux[i];
            
            exp*=10;
        }

        int ans = 0;
        for(int i=1;i<nums.size();i++)
            ans = max(ans, nums[i]-nums[i-1]);
        return ans;
    }
};
// @lc code=end

