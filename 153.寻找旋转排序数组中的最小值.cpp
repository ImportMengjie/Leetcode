/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (50.26%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 91.5K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 你可以假设数组中不存在重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1||nums[0]<nums[nums.size()-1]) return nums[0];

        int left = 0, right = nums.size()-1;

        while(left<right){
            int mid = left + ((right-left)>>1);
            if(nums[mid]>nums[right])
                left = mid+1;
            else
                right = mid;
        }
        return nums[left];
    }
};
// @lc code=end

