/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 *
 * https://leetcode-cn.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (34.41%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 11K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * 给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
 * 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
 * 
 * 说明:
 * 最直观的算法复杂度是 O(n^2) ，请在此基础上优化你的算法。
 * 
 * 示例:
 * 
 * 输入: nums = [-2,5,-1], lower = -2, upper = 2,
 * 输出: 3 
 * 解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。
 * 
 * 
 */
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans = 0;
        multiset<long long> mset;
        mset.insert(0);
        long long sum = 0;
        for(int& num:nums){
            sum += num;
            ans += distance(mset.lower_bound(sum-upper), mset.upper_bound(sum-lower));
            mset.insert(sum);
        }
        return ans;
    }
};
// @lc code=end

