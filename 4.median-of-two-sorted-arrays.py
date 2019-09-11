#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a = (len(nums1)+len(nums2))//2
        b = a if ((len(nums1)+len(nums2)) % 2 == 1) else a-1
        i, j, total = 0, 0, 0
        a_num = 0
        b_num = 0
        while True:
            if j >= len(nums2) or (i < len(nums1) and nums1[i] < nums2[j]):
                temp = nums1[i]
                i += 1
            else:
                temp = nums2[j]
                j += 1
            if total == b:
                b_num = temp
            if total == a:
                a_num = temp
                break
            total += 1
        return (a_num+b_num)/2
