/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n <= 0)
            return {};
        stack<pair<string, vector<int>>> s;
        vector<string> ret;
        s.push({"(", {1, 0}});
        while (!s.empty())
        {
            auto t = s.top();
            s.pop();
            if (t.second[0] == n && t.second[1] == n)
            {
                ret.push_back(t.first);
            }
            if (t.second[0] < n)
                s.push({t.first + "(", {t.second[0] + 1, t.second[1]}});
            if (t.second[1] < t.second[0])
                s.push({t.first + ")", {t.second[0], t.second[1] + 1}});
        }
        return ret;
    }
};
