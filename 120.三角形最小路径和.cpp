/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (64.15%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    53.8K
 * Total Submissions: 83.5K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        long max_value = 2147483647;
        for(int i=1;i< triangle.size();i++)
            for(int j=0; j<triangle[i].size();j++){
                int a = j<triangle[i-1].size()?triangle[i-1][j]:max_value;
                int b = j-1<triangle[i-1].size()?triangle[i-1][j-1]:max_value;
                triangle[i][j] += min(a,b);
            }
            return *min_element(triangle[triangle.size()-1].begin(), end(triangle[triangle.size()-1]));
    }
};
// @lc code=end

