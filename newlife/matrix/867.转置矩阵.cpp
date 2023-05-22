/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 *
 * https://leetcode.cn/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (66.75%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    97.6K
 * Total Submissions: 146.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。
 * 
 * 矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6]]
 * 输出：[[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * 1 
 * -10^9 
 * 
 * 
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.back().size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
// @lc code=end

