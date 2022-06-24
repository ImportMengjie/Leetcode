/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 *
 * https://leetcode.cn/problems/nth-digit/description/
 *
 * algorithms
 * Medium (45.57%)
 * Likes:    323
 * Dislikes: 0
 * Total Accepted:    49.6K
 * Total Submissions: 108.9K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n
 * 位上的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 11
 * 输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */
#include <math.h>

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {   
        int d=1, count = 9;
        while(n>(long)d*count){
            n -= d*count;
            d++;
            count*=10;
        }
        n--;
        int num = (int)pow(10, d-1)+(n/d);
        int ret = (num/((int)pow(10, d-(n%d)-1)))%10;
        return ret;
    }
};
// @lc code=end

