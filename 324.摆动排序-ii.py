#
# @lc app=leetcode.cn id=324 lang=python3
#
# [324] 摆动排序 II
#
# https://leetcode-cn.com/problems/wiggle-sort-ii/description/
#
# algorithms
# Medium (35.35%)
# Likes:    145
# Dislikes: 0
# Total Accepted:    11.7K
# Total Submissions: 32.8K
# Testcase Example:  '[1,5,1,1,6,4]'
#
# 给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
# 
# 示例 1:
# 
# 输入: nums = [1, 5, 1, 1, 6, 4]
# 输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
# 
# 示例 2:
# 
# 输入: nums = [1, 3, 2, 2, 3, 1]
# 输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
# 
# 说明:
# 你可以假设所有输入都会得到有效的结果。
# 
# 进阶:
# 你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
# 
#

# @lc code=start
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort(reverse=True)
        mid = len(nums)//2
        nums[1::2],nums[0::2]=nums[:mid],nums[mid:]
# @lc code=end

