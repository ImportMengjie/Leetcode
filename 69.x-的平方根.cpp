/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.63%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    110.3K
 * Total Submissions: 293.1K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */

#include <math.h>

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x<=2) return 1;
        double x0 = x;
        double x1 = 0.5*(x0+x/x0);
        while(abs(x1-x0)>=1){
            x0 = x1;
            x1 = (x0+x/x0)/2;
        }
        return (int)x1;
        
    }
};
// @lc code=end

