/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (prefix != "" && strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.size() - 1);
            }
            if (prefix == "")
                break;
        }
        return prefix;
    }
};
