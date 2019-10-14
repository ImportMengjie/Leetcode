/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n <= 1)
            return;
        for (int len = n, depth = 0; len > 1; len -= 2, depth++)
        {
            for (int i = depth, count = len; i < depth + len - 1; i++, count--)
            {
                int &number1 = matrix[depth][i];
                int &number2 = matrix[i][depth + len - 1];
                int &number3 = matrix[depth + len - 1][depth + count - 1];
                int &number4 = matrix[depth + count - 1][depth];
                int t = number1;
                number1 = number4;
                number4 = number3;
                number3 = number2;
                number2 = t;
            }
        }
    }
};
// @lc code=end
