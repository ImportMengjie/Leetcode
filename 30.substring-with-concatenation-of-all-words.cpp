/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        if (s.empty() || words.empty())
            return ans;
        unordered_map<string, int> counts;
        for (string &word : words)
            counts[word]++;

        int word_size = words[0].size();
        for (int i = 0; i <= (int)s.size() - word_size * (int)words.size(); i++)
        {
            auto records(counts);
            int nums = 0;
            for (int j = i; j <= s.size() - word_size; j += word_size)
            {
                string word = s.substr(j, word_size);
                if (records[word])
                {
                    records[word]--;
                    nums++;
                }
                else
                    break;
            }
            if (nums == words.size())
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
