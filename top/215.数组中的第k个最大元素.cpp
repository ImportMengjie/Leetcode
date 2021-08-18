/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.71%)
 * Likes:    1228
 * Dislikes: 0
 * Total Accepted:    403.3K
 * Total Submissions: 623.3K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(auto& num:nums){
            heap.push(num);
            if(heap.size()>k)
                heap.pop();
        }
        return heap.top();
    }

    int randomPartition(vector<int>& nums, int left, int right){
        swap(nums[left], nums[rand()%(right-left+1)+left]);
        int pivot = nums[left];
        while(left<right){
            while(left<right&&nums[right]>pivot)
                right--;
            if(left<right) nums[left] = nums[right];
            while(left<right&&nums[left]<=pivot)
                left++;
            if(left<right) nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    int findKthLargest2(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        k = nums.size()-k;
        int left = 0, right = nums.size()-1;
        while(left<right){
            int mid = randomPartition(nums, left, right);
            if(mid==k) return nums[mid];
            else if(mid>k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return nums[k];
    }

};
// @lc code=end

