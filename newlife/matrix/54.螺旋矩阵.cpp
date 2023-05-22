/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    1382
 * Dislikes: 0
 * Total Accepted:    369.1K
 * Total Submissions: 748.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序
 * ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
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
 * -100
 *
 *
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int min_row = 0, min_col = 0, max_row = matrix.size() - 1,
            max_col = matrix.front().size() - 1;
        vector<int> ans;
        while(ans.size()<matrix.size()*matrix.front().size()) {
            if(min_row<=max_row) {
                for(int col=min_col;col<=max_col;col++) {
                    ans.push_back(matrix[min_row][col]);
                }
                min_row++;
            }
            if(min_col<=max_col) {
                for(int row = min_row;row<=max_row;row++) {
                    ans.push_back(matrix[row][max_col]);
                }
                max_col--;
            }
            if(min_row<=max_row) {
                for(int col=max_col;col>=min_col;col--) {
                    ans.push_back(matrix[max_row][col]);
                }
                max_row--;
            }
            if(min_col<=max_col) {
                for(int row=max_row;row>=min_row;row--) {
                    ans.push_back(matrix[row][min_col]);
                }
                min_col++;
            }
        }
        return ans;
    }
};
// @lc code=end
