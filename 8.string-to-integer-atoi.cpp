/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int ans = 0;
        int idx = 0;
        int max_int = (1 << 31) - 1;
        int min_int = 1 << 31;
        bool is_start = false;
        bool is_neg = false;
        while (idx < str.length())
        {
            if (is_start)
            {
                if (!(str[idx] >= '0' && str[idx] <= '9'))
                    break;
                int t = str[idx] - '0';
                t = is_neg ? -t : t;
                if (is_neg && (ans < min_int / 10 || (ans == min_int / 10 && t < (min_int % 10))))
                    return min_int;
                if (!is_neg && (ans > max_int / 10 || (ans == max_int / 10 && t > (max_int % 10))))
                    return max_int;
                ans *= 10;
                ans += t;
            }
            else
            {
                if (str[idx] >= '0' && str[idx] <= '9')
                {
                    is_start = true;
                    continue;
                }
                else if (str[idx] == '-')
                {
                    is_neg = true;
                    is_start = true;
                }
                else if (str[idx] == '+')
                    is_start = true;
                else if (str[idx] != ' ')
                    break;
            }
            idx++;
        }
        return ans;
    }
};
