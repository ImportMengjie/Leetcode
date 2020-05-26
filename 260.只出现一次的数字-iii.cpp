/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 *
 * https://leetcode-cn.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (70.88%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    21.6K
 * Total Submissions: 29.9K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
 * 
 * 示例 :
 * 
 * 输入: [1,2,1,3,2,5]
 * 输出: [3,5]
 * 
 * 注意：
 * 
 * 
 * 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
 * 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int xorRes = 0;
        for(auto& num: nums)
            xorRes ^= num;
        unsigned int ids_of_diff_bit = 1;
        while ((ids_of_diff_bit&xorRes)==0) 
            ids_of_diff_bit<<=1;
        for(auto& num:nums)
            if((num&ids_of_diff_bit)==0)
                ans[0]^=num;
            else
                ans[1]^=num;
        return ans;
    }
};
// @lc code=end

