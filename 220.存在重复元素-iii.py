#
# @lc app=leetcode.cn id=220 lang=python3
#
# [220] 存在重复元素 III
#
# https://leetcode-cn.com/problems/contains-duplicate-iii/description/
#
# algorithms
# Medium (25.89%)
# Likes:    169
# Dislikes: 0
# Total Accepted:    17.5K
# Total Submissions: 67.2K
# Testcase Example:  '[1,2,3,1]\n3\n0'
#
# 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j
# 之间的差的绝对值最大为 ķ。
# 
# 示例 1:
# 
# 输入: nums = [1,2,3,1], k = 3, t = 0
# 输出: true
# 
# 示例 2:
# 
# 输入: nums = [1,0,1,1], k = 1, t = 2
# 输出: true
# 
# 示例 3:
# 
# 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
# 输出: false
# 
#

# @lc code=start
class Solution:
    def getId(self, x, w):
        return x//w if x>=0 else (x+1)//w-1

    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t<0 or k<0: return False
        table = {}
        for i in range(len(nums)):
            key = self.getId(nums[i], t+1)
            if key in table:
                return True
            if key-1 in table and abs(table[key-1]-nums[i])<=t:
                return True
            if key+1 in table and abs(table[key+1]-nums[i])<=t:
                return True
            table[key] = nums[i]
            if i>=k:
                table.pop(self.getId(nums[i-k], t+1))
        return False


# @lc code=end

