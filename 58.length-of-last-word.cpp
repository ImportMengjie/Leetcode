/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = 0;
        int e = s.size() - 1;
        while (e >= 0 && s[e] == ' ')
            e--;
        for (int i = e; i >= 0 && s[i] != ' '; i--, len++)
            ;
        return len;
    }
};
// @lc code=end
