/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (40.75%)
 * Likes:    189
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 35.1K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 * 
 * 示例 1:
 * 
 * 输入: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2:
 * 
 * 输入: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int ans = 0;
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                ans = max(dfs(matrix, cache, i, j), ans);
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j){
        if(cache[i][j]) return cache[i][j];
        for(auto& d:dirs){
            int x = i+d[0], y = j + d[1];
            if(x>=0&&y>=0&&x<matrix.size()&&y<matrix[x].size()&&matrix[x][y]>matrix[i][j])
                cache[i][j] = max(dfs(matrix,cache, x, y), cache[i][j]);
        }
        return ++cache[i][j];
    }
};
// @lc code=end

