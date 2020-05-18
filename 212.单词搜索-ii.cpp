/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (39.84%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 34.3K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
 * 
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 * 
 * 示例:
 * 
 * 输入: 
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * 输出: ["eat","oath"]
 * 
 * 说明:
 * 你可以假设所有输入都由小写字母 a-z 组成。
 * 
 * 提示:
 * 
 * 
 * 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
 * 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
 * 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
 * 
 * 
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
private:
    class TrieNode{
        public:
            vector<TrieNode*> links;
            string word="";
            TrieNode():links(26,nullptr){
            }
            TrieNode* getKey(char &c){
                return links[c-'a'];
            }
            void putKey(char& c){
                links[c-'a'] = new TrieNode();
            }
    };

public:
    vector<string> ans;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& w:words){
            TrieNode* node = root;
            for(char &c:w){
                if(!node->getKey(c)) node->putKey(c);
                node = node->getKey(c);
            }
            node->word = w;
        }

        for(int i=0;i<board.size();i++){
            for(int j=0; j<board[i].size();j++){
                if(root->getKey(board[i][j]))
                    dfs(board, i, j, root);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node){
        char c = board[i][j];
        if(board[i][j]=='.'||!node->getKey(c)) return;
        board[i][j] = '.';
        if(node->getKey(c)->word!=""){
            ans.push_back(node->getKey(c)->word);
            node->getKey(c)->word = "";
        }
        if(i>0) dfs(board, i-1, j, node->getKey(c));
        if(j>0) dfs(board, i, j-1, node->getKey(c));
        if(i+1<board.size()) dfs(board, i+1, j, node->getKey(c));
        if(j+1<board[0].size()) dfs(board, i, j+1, node->getKey(c));

        board[i][j] = c;

    }
};
// @lc code=end

