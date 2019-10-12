/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

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
            for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
            {
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;
                path.push_back(candidates[i]);
                dfs(candidates, i + 1, target - candidates[i]);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};
// @lc code=end
