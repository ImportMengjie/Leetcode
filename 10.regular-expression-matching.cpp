/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <string>

using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        bool dp[s.size() + 1][p.size() + 1] = {};
        dp[s.size()][p.size()] = true;
        for (int i = s.size(); i >= 0; i--)
        {
            for (int j = p.size() - 1; j >= 0; j--)
            {
                bool first_match = i < s.size() && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < p.size() && p[j + 1] == '*')
                {
                    dp[i][j] = (first_match && dp[i + 1][j]) || (dp[i][j + 2]);
                }
                else
                {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
