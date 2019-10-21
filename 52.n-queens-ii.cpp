/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool *row;
    bool *col;
    bool *hill;
    bool *dales;
    int n;
    int count;

    bool couldPlace(int row, int col)
    {
        bool ret = !(this->row[row] || this->col[col] || this->hill[row + col] || this->dales[row - col + n - 1]);
        return ret;
    }

    void placeQueen(int row, int col)
    {
        this->row[row] = true;
        this->col[col] = true;
        this->hill[row + col] = true;
        this->dales[row - col + n - 1] = true;
    }

    void removeQueen(int row, int col)
    {
        this->row[row] = false;
        this->col[col] = false;
        this->hill[row + col] = false;
        this->dales[row - col + n - 1] = false;
    }

    void backtrack(int row)
    {
        for (int col = 0; col < n; col++)
        {
            if (couldPlace(row, col))
            {
                placeQueen(row, col);
                if (row + 1 == n)
                    count++;
                else
                    backtrack(row + 1);
                removeQueen(row, col);
            }
        }
    }

    int totalNQueens(int n)
    {
        row = new bool[n];
        col = new bool[n];
        hill = new bool[2 * n - 1];
        dales = new bool[2 * n - 1];
        for (int i = 0; i < n; i++)
        {
            row[i] = false;
            col[i] = false;
            hill[i] = false;
            dales[i] = false;
        }
        for (int i = n; i < 2 * n - 1; i++)
        {
            hill[i] = false;
            dales[i] = false;
        }

        this->n = n;
        backtrack(0);
        delete[] row;
        delete[] col;
        delete[] hill;
        delete[] dales;
        return this->count;
    }
};
// @lc code=end
