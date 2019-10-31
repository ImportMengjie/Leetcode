/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

#include <vector>
using namespace std;
// @lc code=start

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(vector<int>(n, 0));
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        int num = 1;
        while (r1 <= r2 && c1 <= c2)
        {
            for (int c = c1; c <= c2; c++)
                ans[r1][c] = num++;
            for (int r = r1 + 1; r <= r2; r++)
                ans[r][c2] = num++;
            for (int c = c2 - 1; c >= c1; c--)
                ans[r2][c] = num++;
            for (int r = r2 - 1; r > r1; r--)
                ans[r][c1] = num++;
            r1++;
            c1++;
            r2--;
            c2--;
        }
        return ans;
    }
};
// @lc code=end
