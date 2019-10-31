/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
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
