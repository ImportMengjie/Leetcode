/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (59.67%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    144.9K
 * Total Submissions: 245.4K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
private:

    int partition(vector<int>& nums, int left, int right){
        int pivot_idx = rand()%(right-left+1) + left;
        swap(nums[pivot_idx], nums[left]);
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

    void quickSort(vector<int>& nums, int left, int right){
        int mid = partition(nums, left, right);
        if(mid-1>left)
            quickSort(nums, left, mid-1);
        if(mid+1<right)
            quickSort(nums, mid+1, right);
    }

    void quickSortStack(vector<int>& nums){
        stack<pair<int,int>> stk;
        stk.push({0, nums.size()-1});
        while(stk.size()){
            int left = stk.top().first;
            int right = stk.top().second;
            stk.pop();
            if(left<right){
                int mid = partition(nums, left, right);
                if(mid+1<right)
                    stk.push({mid+1, right});
                if(mid-1>left)
                    stk.push({left, mid-1});
            }
        }
    }


public:
    vector<int> sortArray(vector<int>& nums) {
        quickSortStack(nums);
        // quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

