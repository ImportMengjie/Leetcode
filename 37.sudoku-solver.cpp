/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    short columns[9][9] = {{0}};
    short rows[9][9] = {{0}};
    short boxs[9][9] = {{0}};

    bool isDone = false;

    bool cloudPlace(vector<vector<char>> &borad, int row, int column, int num)
    {
        return columns[column][num] + rows[row][num] + boxs[(row / 3) * 3 + column / 3][num] == 0;
    }

    void placeNumber(vector<vector<char>> &borad, int row, int col, int num)
    {
        columns[col][num]++;
        rows[row][num]++;
        boxs[(row / 3) * 3 + col / 3][num]++;
        borad[row][col] = (char)('1' + num);
    }

    void deleteNumber(vector<vector<char>> &borad, int row, int col, int num)
    {
        columns[col][num]--;
        rows[row][num]--;
        boxs[(row / 3) * 3 + col / 3][num]--;
        borad[row][col] = '.';
    }

    void placeNextNumber(vector<vector<char>> &borad, int row, int col)
    {
        if (row == 8 && col == 8)
            isDone = true;
        else
        {
            if (col == 8)
                backtrack(borad, row + 1, 0);
            else
                backtrack(borad, row, col + 1);
        }
    }
    void backtrack(vector<vector<char>> &borad, int row, int col)
    {
        if (borad[row][col] == '.')
        {
            for (int i = 0; i < 9; i++)
            {
                if (cloudPlace(borad, row, col, i))
                {
                    placeNumber(borad, row, col, i);
                    placeNextNumber(borad, row, col);
                    if (!isDone)
                        deleteNumber(borad, row, col, i);
                }
            }
        }
        else
            placeNextNumber(borad, row, col);
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                    placeNumber(board, i, j, board[i][j] - '1');
            }
        }
        backtrack(board, 0, 0);
    }
};
// @lc code=end
