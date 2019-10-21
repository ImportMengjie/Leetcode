/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (m.find(s) == m.end())
                m[s] = {};
            m[s].push_back(strs[i]);
        }
        for (auto it = m.begin(); it != m.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
};
// @lc code=end
