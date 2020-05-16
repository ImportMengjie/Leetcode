/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (33.00%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    56.5K
 * Total Submissions: 168K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */
#include <vector>

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> primes(n, true);
        int res = 0;
        if(n>2) res++;
        for(int i=3;i<n;i+=2){
            if(primes[i]){
                res++;
                for(int j=3*i;j<n;j+=2*i)
                    primes[j] = false;
            }
        }
        return res;
    }
};
// @lc code=end

