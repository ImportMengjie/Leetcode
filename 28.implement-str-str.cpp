/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
            return -1;
        else if (needle == "")
            return 0;
        else
        {
            for (int i = 0; i < haystack.size(); i++)
            {
                bool is_not_match = false;
                for (int j = 0; j < needle.size(); j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        is_not_match = true;
                        break;
                    }
                }
                if (!is_not_match)
                    return i;
            }
            return -1;
        }
    }
};
// @lc code=end
