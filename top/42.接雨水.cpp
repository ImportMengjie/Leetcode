/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (57.16%)
 * Likes:    2589
 * Dislikes: 0
 * Total Accepted:    297.9K
 * Total Submissions: 520.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        vector<int> leftMax(height.size(), height.front());
        vector<int> rightMax(height.size(), height.back());
        for(int i=1;i<height.size();i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        for(int i=height.size()-2;i>=0;i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        int totalTrap = 0;
        for(int i=0;i<height.size();i++)
            totalTrap += min(leftMax[i],rightMax[i]) - height[i];
        return totalTrap;
    }
};
// @lc code=end

