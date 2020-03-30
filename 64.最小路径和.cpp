/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (65.16%)
 * Likes:    418
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 110.1K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size() - 1;
        int n = grid[m].size() - 1;
        for (int i = m - 1; i >= 0; i--)
            grid[i][n] += grid[i + 1][n];
        for (int j = n - 1; j >= 0; j--)
            grid[m][j] += grid[m][j + 1];

        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                grid[i][j] += min(grid[i][j + 1], grid[i + 1][j]);
        return grid[0][0];
    }
};
// @lc code=end
