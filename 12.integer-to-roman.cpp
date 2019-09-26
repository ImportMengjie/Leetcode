/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> M = {"", "M", "MM", "MMM"};
    vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    string intToRoman(int num)
    {
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[(num % 10)];
    }
};
