#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#
# https://leetcode-cn.com/problems/ugly-number-ii/description/
#
# algorithms
# Medium (50.91%)
# Likes:    281
# Dislikes: 0
# Total Accepted:    25.4K
# Total Submissions: 49.1K
# Testcase Example:  '10'
#
# 编写一个程序，找出第 n 个丑数。
# 
# 丑数就是质因数只包含 2, 3, 5 的正整数。
# 
# 示例:
# 
# 输入: n = 10
# 输出: 12
# 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
# 
# 说明:  
# 
# 
# 1 是丑数。
# n 不超过1690。
# 
# 
#

# @lc code=start

class Ugly:

    def __init__(self):
        self.nums = [1,]
        i2,i3,i5=0,0,0
        for i in range(1, 1690):
            ugly = min(self.nums[i2]*2,self.nums[i3]*3,self.nums[i5]*5)
            self.nums.append(ugly)
            if ugly == self.nums[i2]*2:
                i2+=1
            if ugly == self.nums[i3]*3:
                i3+=1
            if ugly == self.nums[i5]*5:
                i5+=1


class Solution:
    ugly = Ugly()

    def nthUglyNumber(self, n: int) -> int:
        return self.ugly.nums[n-1]
# @lc code=end

