/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.00%)
 * Likes:    512
 * Dislikes: 0
 * Total Accepted:    74.9K
 * Total Submissions: 97.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        stack<pair<int, vector<int>>> s;
        s.push(pair<int, vector<int>>(0, vector<int>()));
        while (!s.empty())
        {
            pair<int, vector<int>> p = s.top();
            s.pop();
            ans.push_back(p.second);
            if(p.second.size()<nums.size())
            {
                for (int i = p.first; i<nums.size(); i++)
                {
                    vector<int> new_list(p.second);
                    new_list.push_back(nums[i]);
                    s.push(pair<int, vector<int>>(i+1, new_list));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

