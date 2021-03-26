/*
统计一个数字在排序数组中出现的次数。
示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
限制：

0 <= 数组长度 <= 50000

注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

class Solution {
public:
    int findLeft(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while(left<right){
            int mid = left + ((right-left)>>1);
            if(nums[mid]<target)
                left = mid+1;
            else if (nums[mid]>target)
                right = mid-1;
            else{
                if(mid==0||nums[mid-1]!=target)
                    return mid;
                else
                    right = mid-1;
            }
        }
        return nums[left]==target?left:-1;
    }

    int findRight(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while(left<right){
            int mid = left + ((right-left)>>1);
            if(nums[mid]==target){
                if(mid==nums.size()-1||nums[mid+1]!=target)
                    return mid;
                else
                    left = mid+1;
            }else if(nums[mid]<target)
                left = mid+1;
            else
                right = mid-1;
        }
        return nums[left]==target?left:-1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int left = findLeft(nums, target);
        if(left<0) return 0;
        int right = findRight(nums, target);
        return right-left+1;
    }
};
