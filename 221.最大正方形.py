#
# @lc app=leetcode.cn id=221 lang=python3
#
# [221] 最大正方形
#
# https://leetcode-cn.com/problems/maximal-square/description/
#
# algorithms
# Medium (39.36%)
# Likes:    419
# Dislikes: 0
# Total Accepted:    52.5K
# Total Submissions: 124K
# Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
#
# 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
# 
# 示例:
# 
# 输入: 
# 
# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0
# 
# 输出: 4
# 
#

# @lc code=start
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        dp = []
        ans = 0
        for i in range(len(matrix)):
            dp.append([0]*len(matrix[i]))
            for j in range(len(matrix[i])):
                if (i==0 or j==0) and matrix[i][j]=='1':
                    dp[i][j] = 1
                elif matrix[i][j]=='1':
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1
                ans = max(ans, dp[i][j])
        return ans*ans

# @lc code=end