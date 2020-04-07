/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (45.02%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    23.5K
 * Total Submissions: 51.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int cols = matrix[0].size();

        int left_less_min[cols];
        int right_less_min[cols];
        int heights[cols] = {0};

        for(int row=0;row<matrix.size();row++){
            for(int col = 0; col<cols;col++){
                if(matrix[row][col]=='1')
                    heights[col]++;
                else
                    heights[col] = 0;
            }
            int boundary = -1;
            for(int col=0;col<cols;col++){

            }

        }


        
    }
};
// @lc code=end

