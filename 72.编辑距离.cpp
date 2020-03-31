/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (56.66%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    37.2K
 * Total Submissions: 65.7K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 示例 1:
 * 
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2:
 * 
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {

        int dp[word1.size()+1][word2.size()+1];
        for(int i=0;i<=word1.size();i++)
            dp[i][0] = i;
        for(int i=0;i<=word2.size();i++)
            dp[0][i]=i;

        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end

