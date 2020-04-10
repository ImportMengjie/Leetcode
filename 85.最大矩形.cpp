// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

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
#include <string.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int cols = matrix[0].size();
        long max_area = 0;

        int left_less_min[cols];
        memset(left_less_min, -1, cols*sizeof(int));
        int right_less_min[cols];
        memset(right_less_min, cols, sizeof(right_less_min));
        int heights[cols];
        memset(heights, 0, sizeof(heights));

        for(int row=0;row<matrix.size();row++){
            for(int col = 0; col<cols;col++){
                if(matrix[row][col]=='1')
                    heights[col]++;
                else
                    heights[col] = 0;
            }
            int boundary = -1;
            for(int col=0;col<cols;col++){
                if(matrix[row][col]=='1')
                    left_less_min[col] = max(left_less_min[col], boundary);
                else{
                    boundary = col;
                    left_less_min[col] = -1;
                }
            }
            boundary = cols;
            for(int col=cols-1;col>=0;col--){
                if(matrix[row][col]=='1')
                    right_less_min[col] = min(boundary, right_less_min[col]);
                else{
                    boundary = col;
                    right_less_min[col] = cols;
                }
            }

            for(int col=0;col<cols;col++){
                max_area = max(max_area, (long)heights[col]*(right_less_min[col]-left_less_min[col]-1));
            }
        }
        return max_area;
    }
};
// @lc code=end

