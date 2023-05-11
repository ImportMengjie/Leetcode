/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (42.44%)
 * Likes:    1518
 * Dislikes: 0
 * Total Accepted:    336.2K
 * Total Submissions: 791.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 ）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ...,
 * nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如，
 * [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[left]<=nums[mid]) { // left 到mid是升序的, 不含分割点k
                if(nums[left]<=target && nums[mid]>target) right = mid - 1;
                else left = mid + 1;
            } else { // mid=>right是升序的, 不含分割点k
                if(nums[mid]<target && nums[right]>=target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

