/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.42%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    42.3K
 * Total Submissions: 57.7K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        if(n==0||k==0)
            return ans;
        stack<pair<int, vector<int>>> s;
        s.push(pair<int, vector<int>>(0, vector<int>()));
        while (!s.empty())
        {
            pair<int, vector<int>> p = s.top();
            s.pop();
            if (p.second.size() == k)
            {
                ans.push_back(p.second);
            }
            else
            {
                for (int i = p.first + 1; n - i + 1 + p.second.size() >= k; i++)
                {
                    vector<int> new_list(p.second);
                    new_list.push_back(i);
                    s.push(pair<int, vector<int>>(i, new_list));
                }
            }
        }
        return ans;
    }
};
// @lc code=end
