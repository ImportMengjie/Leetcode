/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

class Solution
{
public:
    map<char, string> phone = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

    vector<string> letterCombinations(string digits)
    {
        queue<pair<int, string>> q;
        vector<string> ret;
        q.push({0, ""});
        for (int i = 0; i < digits.size(); i++)
        {
            while (!q.empty() && q.front().first == i)
            {
                auto top = q.front();
                q.pop();
                if (digits[i] == '1')
                    q.push({i + 1, top.second});

                for (int j = 0; j < phone[digits[i]].size(); j++)
                    q.push({i + 1, top.second + phone[digits[i]][j]});
            }
        }
        while (!q.empty())
        {
            if (q.front().second != "")
                ret.push_back(q.front().second);
            q.pop();
        }
        return ret;
    }
};
