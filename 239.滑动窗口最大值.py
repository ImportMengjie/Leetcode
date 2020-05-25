#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#
# https://leetcode-cn.com/problems/sliding-window-maximum/description/
#
# algorithms
# Hard (45.52%)
# Likes:    370
# Dislikes: 0
# Total Accepted:    49.7K
# Total Submissions: 104.4K
# Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
#
# 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
# 个数字。滑动窗口每次只向右移动一位。
# 
# 返回滑动窗口中的最大值。
# 
# 
# 
# 进阶：
# 
# 你能在线性时间复杂度内解决此题吗？
# 
# 
# 
# 示例:
# 
# 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
# 输出: [3,3,5,5,6,7] 
# 解释: 
# 
# ⁠ 滑动窗口的位置                最大值
# ---------------               -----
# [1  3  -1] -3  5  3  6  7       3
# ⁠1 [3  -1  -3] 5  3  6  7       3
# ⁠1  3 [-1  -3  5] 3  6  7       5
# ⁠1  3  -1 [-3  5  3] 6  7       5
# ⁠1  3  -1  -3 [5  3  6] 7       6
# ⁠1  3  -1  -3  5 [3  6  7]      7
# 
# 
# 
# 提示：
# 
# 
# 1 <= nums.length <= 10^5
# -10^4 <= nums[i] <= 10^4
# 1 <= k <= nums.length
# 
# 
#
from collections import deque

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums, k: int):
        deq = deque()
        ans = []

        def clean_deq(i):
            if deq and deq[0] == i-k:
                deq.popleft()
            while deq and nums[i]>nums[deq[-1]]:
                deq.pop()

        for i in range(k):
            clean_deq(i)
            deq.append(i)
        ans.append(nums[deq[0]])
        for i in range(k, len(nums)):
            clean_deq(i)
            deq.append(i)
            ans.append(nums[deq[0]])
        return ans

# if __name__=='__main__':
#     print(Solution().maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))
# @lc code=end

