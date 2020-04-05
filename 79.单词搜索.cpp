/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (41.06%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    48.4K
 * Total Submissions: 117.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
#include <vector>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution
{
public:
    int directs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool backtrack(vector<vector<char>> &board, string word, vector<vector<bool>>& mark, int i, int j)
    {
        if (!word.empty())
        {
            for (int d = 0; d < 4; d++)
            {
                int t_i = directs[d][0] + i;
                int t_j = directs[d][1] + j;
                if (0 <= t_i && t_i < board.size() && 0 <= t_j && t_j < board[0].size() && mark[t_i][t_j] != 1)
                {
                    if (word[0] == board[t_i][t_j])
                    {
                        mark[t_i][t_j] = 1;
                        bool ret = backtrack(board, word.substr(1), mark, t_i, t_j);
                        if (!ret)
                            mark[t_i][t_j] = 0;
                        else
                            return true;
                    }
                }
            }
            return false;
        }
        else
            return true;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        if (word.empty())
            return true;
        vector<vector<bool>> mark;
        for (int i = 0; i < board.size(); i++){
            mark.emplace_back();
            for (int j = 0; j < board[i].size(); j++)
                mark[i].push_back(0);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    mark[i][j] = 1;
                    if (backtrack(board, word.substr(1), mark, i, j))
                        return true;
                    mark[i][j] = 0;
                }
            }
        }
        return false;
    }

};
// @lc code=end
