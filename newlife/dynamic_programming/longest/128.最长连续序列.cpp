/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.89%)
 * Likes:    1645
 * Dislikes: 0
 * Total Accepted:    386.6K
 * Total Submissions: 704.7K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        如果找不到nums[i]-1在set中, 说明nums[i]可作为起点计数
        */
        set<int> st;
        int ans = 0;
        for(auto& n:nums) st.insert(n);
        for(int i=0;i<nums.size();i++) {
            if(!st.count(nums[i]-1)){
                int current_num = nums[i];
                int current_consecutive = 1;
                while(st.count(++current_num))
                    current_consecutive++;
                ans = max(current_consecutive, ans);
            }
        }
        return ans;
    }
};
// @lc code=end

