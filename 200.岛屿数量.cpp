/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (47.86%)
 * Likes:    562
 * Dislikes: 0
 * Total Accepted:    105.3K
 * Total Submissions: 213.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        if(i-1>=0&&grid[i-1][j]=='1') dfs(grid, i-1, j);
        if(i+1<grid.size()&&grid[i+1][j]=='1') dfs(grid, i+1, j);
        if(j-1>=0&&grid[i][j-1]=='1') dfs(grid, i, j-1);
        if(j+1<grid[i].size()&&grid[i][j+1]=='1') dfs(grid, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int num_island = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]=='1'){
                    ++num_island;
                    dfs(grid, i, j);
                }
        return num_island;
    }
};
// @lc code=end

