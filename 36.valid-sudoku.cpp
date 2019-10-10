/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        short clo[9][9] = {{0}};
        short row[9][9] = {{0}};
        short box[9][9] = {{0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    short num = board[i][j] - '1';
                    row[i][num] += 1;
                    clo[j][num] += 1;
                    box[i / 3 * 3 + j / 3][num] += 1;
                    if (clo[j][num] > 1 || row[i][num] > 1 || box[i / 3 * 3 + j / 3][num] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
