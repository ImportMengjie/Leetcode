#
# @lc app=leetcode.cn id=273 lang=python3
#
# [273] 整数转换英文表示
#
# https://leetcode-cn.com/problems/integer-to-english-words/description/
#
# algorithms
# Hard (26.56%)
# Likes:    71
# Dislikes: 0
# Total Accepted:    5.2K
# Total Submissions: 19.2K
# Testcase Example:  '123'
#
# 将非负整数转换为其对应的英文表示。可以保证给定输入小于 2^31 - 1 。
# 
# 示例 1:
# 
# 输入: 123
# 输出: "One Hundred Twenty Three"
# 
# 
# 示例 2:
# 
# 输入: 12345
# 输出: "Twelve Thousand Three Hundred Forty Five"
# 
# 示例 3:
# 
# 输入: 1234567
# 输出: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
# 
# 示例 4:
# 
# 输入: 1234567891
# 输出: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven
# Thousand Eight Hundred Ninety One"
# 
#

# @lc code=start
class Solution:
    def numberToWords(self, num: int) -> str:
# @lc code=end

