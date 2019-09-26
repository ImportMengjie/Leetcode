/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    map<char, int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (m[s[i]] < m[s[i + 1]])
                ans -= m[s[i]];
            else
                ans += m[s[i]];
        }
        return ans + m[s[s.size() - 1]];
    }
};
