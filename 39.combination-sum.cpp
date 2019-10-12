/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int> &candidates, int start, int target)
    {
        if (target == 0)
            res.push_back(path);
        else
        {
            for (int i = start; i < candidates.size(); i++)
            {
                if (target - candidates[i] < 0)
                    continue;
                path.push_back(candidates[i]);
                dfs(candidates, i, target - candidates[i]);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, 0, target);
        return res;
    }
};
// @lc code=end
