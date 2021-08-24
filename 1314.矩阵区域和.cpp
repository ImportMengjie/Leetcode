/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 *
 * https://leetcode-cn.com/problems/matrix-block-sum/description/
 *
 * algorithms
 * Medium (73.31%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 13.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * 给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素
 * mat[r][c] 的和： 
 * 
 * 
 * i - k 
 * j - k  且
 * (r, c) 在矩阵内。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
 * 输出：[[12,21,16],[27,45,33],[24,39,28]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
 * 输出：[[45,45,45],[45,45,45],[45,45,45]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 
 * 1 
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int get(vector<vector<int>>& dp, int x, int y, int m, int n){
        x = max(min(x,m), 0);
        y = max(min(y,n), 0);
        return dp[x][y];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat.back().size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
                dp[i][j] = dp[i-1][j]+dp[i][j-1]+mat[i-1][j-1]-dp[i-1][j-1];
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = get(dp, i+k+1, j+k+1, m, n) - get(dp, i-k, j+k+1, m, n) - get(dp, i+k+1, j-k, m, n)+get(dp, i-k, j-k, m, n);
            }
        }
        return ans;
    }
};
// @lc code=end

