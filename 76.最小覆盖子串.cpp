/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.54%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 87.2K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */
#include <string>
#include <map>

using namespace std;

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> dict;
        for (char &c : t)
        {
            if (dict.find(c) == dict.end())
                dict[c] = 1;
            else
                dict[c]++;
        }

        int ans[] = {-1, 0};
        int right = 0, left = 0;

        map<char, int> word_count;
        int count = 0;

        while (right < s.size())
        {
            if (dict.find(s[right]) != dict.end())
            {
                if (word_count.find(s[right]) == word_count.end())
                    word_count[s[right]] = 1;
                else
                    word_count[s[right]]++;
                if (word_count[s[right]] == dict[s[right]])
                    count++;
                while (count == dict.size() && left <= right)
                {
                    if (ans[0] == -1 || right - left + 1 < ans[0])
                    {
                        ans[0] = right - left + 1;
                        ans[1] = left;
                    }
                    if (dict.find(s[left]) != dict.end())
                    {
                        word_count[s[left]]--;
                        if (word_count[s[left]] < dict[s[left]])
                            count--;
                    }
                    left++;
                }
            }
            right++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};
// @lc code=end
