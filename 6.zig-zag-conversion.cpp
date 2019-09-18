/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> rows(min(int(s.length()), numRows));
        bool down = false;
        int rowNum = 0;
        for (char &c : s)
        {
            rows[rowNum] += c;
            if (rowNum == 0 || rowNum == numRows - 1)
                down = !down;
            rowNum += down ? 1 : -1;
        }
        string ret;
        for (string &str : rows)
        {
            ret += str;
        }
        return ret;
    }
};
