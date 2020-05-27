/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (55.30%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    60.9K
 * Total Submissions: 108.2K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
#include <math.h>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares(int(sqrt(n)));
        for(int i=1; i<squares.size()+1;i++)
            squares[i-1] = i*i;
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n;i++){
            dp[i] = 2147483647;
            for(auto& s: squares)
                if(s<=i)
                    dp[i] = min(dp[i], dp[i-s]+1);
                else
                    break;
        }
        return dp[n];
    }
};
// @lc code=end

