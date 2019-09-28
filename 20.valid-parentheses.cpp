/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack_char;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                stack_char.push(c);
            else
            {
                if (stack_char.empty() || abs(c - stack_char.top()) > 2)
                    return false;
                stack_char.pop();
            }
        }
        if (stack_char.empty())
            return true;
        else
            return false;
    }
};
