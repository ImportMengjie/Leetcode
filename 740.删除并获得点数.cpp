/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * https://leetcode-cn.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (63.10%)
 * Likes:    408
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 70.3K
 * Testcase Example:  '[3,4,2]'
 *
 * 给你一个整数数组 nums ，你可以对它进行一些操作。
 * 
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和
 * nums[i] + 1 的元素。
 * 
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,4,2]
 * 输出：6
 * 解释：
 * 删除 4 获得 4 个点数，因此 3 也被删除。
 * 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,3,3,3,4]
 * 输出：9
 * 解释：
 * 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
 * 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 * 总共获得 9 个点数。
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
    int deleteAndEarn(vector<int>& nums) {
        int maxValue = 0;
        for(int& num:nums)
            maxValue = max(maxValue, num);
        vector<int> sum(maxValue+1, 0);
        for(int& num:nums)
            sum[num] += num;
        if(sum.size()==1) return sum[0];
        int curMax = max(sum[1],sum[0]), preMax = sum[0];
        for(int i=2;i<sum.size();i++){
            int t = max(curMax, preMax+sum[i]);
            preMax = curMax;
            curMax = t;
        }
        return curMax;
    }
};
// @lc code=end

