/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 *
 * https://leetcode-cn.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (42.84%)
 * Likes:    189
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 36.1K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 
 * 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: [3]
 * 
 * 示例 2:
 * 
 * 输入: [1,1,1,3,3,2,2,2]
 * 输出: [1,2]
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cnt1 = 0;
        int cand2 = 0, cnt2 = 0;
        vector<int> ans;
        for(auto& num: nums){
            if(num == cand1){
                cnt1++;
                continue;
            }else if(num == cand2){
                cnt2++;
                continue;
            }else if(cnt1==0){
                cand1 = num;
                cnt1++;
                continue;
            }
            else if(cnt2==0){
                cand2 = num;
                cnt2++;
                continue;
            }
            cnt1--;
            cnt2--;
        }
        cnt1=cnt2=0;
        for(auto& num:nums){
            if(num==cand1)
                cnt1++;
            else if(num==cand2)
                cnt2++;
        }
        if(cnt1>nums.size()/3)
            ans.push_back(cand1);
        if(cnt2>nums.size()/3)
            ans.push_back(cand2);
        return ans;
    }
};
// @lc code=end

