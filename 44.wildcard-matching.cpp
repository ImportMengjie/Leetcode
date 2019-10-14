/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        bool dp[s.size() + 1][p.size() + 1] = {{false}};
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++)
            dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
