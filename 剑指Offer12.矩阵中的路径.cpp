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
    bool dfs(vector<vector<char>>& borad, string& word, int wordIdx,int row, int col, vector<vector<bool>>& visit){    
        if(row<0||row>=borad.size()||col<0||col>=borad[row].size()||visit[row][col]||borad[row][col]!=word[wordIdx])
            return false;
        if(wordIdx>=word.size()-1) return true;
        visit[row][col] = true;
        for(int i=0;i<4;i++)
            if(dfs(borad,word,wordIdx+1,row+directs[i][0],col+directs[i][1],visit))
                return true;
        visit[row][col]=false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        if(word.empty()) return true;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));            
        for(int row=0;row<board.size();row++)
            for(int col=0;col<board[row].size();col++)
                if(dfs(board, word, 0, row, col, visit))
                    return true;
        return false;
    }
};
// @lc code=end
