#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#
# https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
#
# algorithms
# Medium (61.81%)
# Likes:    471
# Dislikes: 0
# Total Accepted:    117.1K
# Total Submissions: 187.8K
# Testcase Example:  '[3,2,1,5,6,4]\n2'
#
# 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
# 
# 示例 1:
# 
# 输入: [3,2,1,5,6,4] 和 k = 2
# 输出: 5
# 
# 
# 示例 2:
# 
# 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
# 输出: 4
# 
# 说明: 
# 
# 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
# 
#
import random

# @lc code=start
class Solution:
    def findKthLargest(self, nums, k: int) -> int:

        def partition(left, right, pivot_ids):
            pivot = nums[pivot_ids]
            nums[pivot_ids], nums[left] = nums[left], nums[pivot_ids]
            while left<right:
                while left<right and nums[right]>=pivot:
                    right-=1
                nums[left] = nums[right]
                while left<right and nums[left]<=pivot:
                    left+=1
                nums[right]=nums[left]
            nums[left] = pivot
            return left

        def select(left, right):
            if left==right:
                return nums[left]
            # print(nums)
            pivot_ids = random.randint(left,right)
            mid = partition(left, right, pivot_ids)
            # print(pivot_ids, nums)
            # print("============")
            if mid==len(nums)-k:
                return nums[mid]
            elif mid<len(nums)-k:
                return select(mid+1, right)
            else:
                return select(left, mid-1)
        return select(0, len(nums)-1)

if __name__=='__main__':
    pass
    # print(Solution().findKthLargest([99,99], 1))
    # print(Solution().findKthLargest([99,99], 1))

# @lc code=end

