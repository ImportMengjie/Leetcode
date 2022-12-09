/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, len = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) len++;
            else{
                ret = max(ret, len);
                len = 0;
            }
        }
        ret = max(ret, len);
        return ret;
    }
};
// @lc code=end

