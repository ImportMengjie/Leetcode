/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (ans.empty() || ans[ans.size() - 1][1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else
                ans[ans.size() - 1][1] = max(intervals[i][1], ans[ans.size() - 1][1]);
        }
        return ans;
    }
};
// @lc code=end
