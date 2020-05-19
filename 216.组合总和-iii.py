#
# @lc app=leetcode.cn id=216 lang=python3
#
# [216] 组合总和 III
#
# https://leetcode-cn.com/problems/combination-sum-iii/description/
#
# algorithms
# Medium (70.55%)
# Likes:    112
# Dislikes: 0
# Total Accepted:    20.5K
# Total Submissions: 28.9K
# Testcase Example:  '3\n7'
#
# 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
# 
# 说明：
# 
# 
# 所有数字都是正整数。
# 解集不能包含重复的组合。 
# 
# 
# 示例 1:
# 
# 输入: k = 3, n = 7
# 输出: [[1,2,4]]
# 
# 
# 示例 2:
# 
# 输入: k = 3, n = 9
# 输出: [[1,2,6], [1,3,5], [2,3,4]]
# 
# 
#

# @lc code=start
class Solution:
    def backtrack(self, start, path:list, k, n, ans:list):
        if k<=0 or n<=0:
            if k==0 and n==0:
                ans.append(path.copy())
            return
        for i in range(start,10):
            if n-i>=0:
                path.append(i)
                self.backtrack(i+1, path, k-1, n-i, ans)
                path.pop()
        

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        self.backtrack(1, [], k, n, ans)
        return ans
# @lc code=end

