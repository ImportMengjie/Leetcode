/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (39.88%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    31.8K
 * Total Submissions: 79.6K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int n=board.size() ,m=board[0].size();
        for(int i=0;i<n;i++){
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for(int j=1;j<m-1;j++){
            dfs(board, 0, j);
            dfs(board, n-1, j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]=='O'){
            board[i][j] = '#';
            dfs(board,i-1,j);
            dfs(board,i+1,j);
            dfs(board,i,j-1);
            dfs(board,i,j+1);
        }
    }
};
// @lc code=end

