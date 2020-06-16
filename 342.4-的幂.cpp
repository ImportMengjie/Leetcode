/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (48.72%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 53K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */
#include <math.h>

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0&&!(num&(num-1))&&(num&0x55555555)==num;
    }
};
// @lc code=end

