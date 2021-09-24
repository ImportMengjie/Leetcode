/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (47.48%)
 * Likes:    288
 * Dislikes: 0
 * Total Accepted:    27.1K
 * Total Submissions: 56.5K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
 * 
 * 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
 * 
 * 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输出坐标的顺序不重要
 * m 和 n 都小于150
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 
 * 给定下面的 5x5 矩阵:
 * 
 * ⁠ 太平洋 ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * 大西洋
 * 
 * 返回:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
 * 
 * 
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& state,vector<vector<bool>>& vis,int r, int c, int s){
        state[r][c] |= s;
        vis[r][c] = true;
        if(r-1>=0&&!vis[r-1][c]&&heights[r-1][c]>=heights[r][c])
            dfs(heights, state, vis, r-1, c, s);
        if(r+1<heights.size()&&!vis[r+1][c]&&heights[r+1][c]>=heights[r][c])
            dfs(heights, state, vis, r+1, c, s);
        if(c-1>=0&&!vis[r][c-1]&&heights[r][c-1]>=heights[r][c])
            dfs(heights, state, vis, r, c-1, s);
        if(c+1<heights.back().size()&&!vis[r][c+1]&&heights[r][c+1]>=heights[r][c])
            dfs(heights, state, vis, r, c+1, s);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> state(heights.size(), vector<int>(heights.back().size(), 0));
        vector<vector<bool>> vis1(heights.size(), vector<bool>(heights.back().size(), 0));
        vector<vector<bool>> vis2(heights.size(), vector<bool>(heights.back().size(), 0));
        for(int i=0;i<heights.size();i++){
            dfs(heights, state, vis1, i, 0, 1);
            dfs(heights, state, vis2, i, heights.back().size()-1, 2);
        }
        for(int i=0;i<heights.back().size();i++){
            dfs(heights, state, vis1, 0, i, 1);
            dfs(heights, state, vis2, heights.size()-1, i, 2);
        }
        vector<vector<int>> ans;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights.back().size();j++){
                if(state[i][j]==3)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
// @lc code=end

