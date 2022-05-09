/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * https://leetcode-cn.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (70.40%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    97K
 * Total Submissions: 138K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
 * 
 * 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * 
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100
 * 。计算这个岛屿的周长。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * 输出：16
 * 解释：它的周长是上面图片中的 16 个黄色的边
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1]]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：grid = [[1,0]]
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * row == grid.length
 * col == grid[i].length
 * 1 
 * grid[i][j] 为 0 或 1
 * 
 * 
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> direction{{-1,0},{1,0},{0,-1},{0,1}};

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid.front().size(),false));
        queue<pair<int,int>> q;
        int perimeter = 0;
        int i,j = 0;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[i].size();j++){
                if(grid[i][j])
                    break;
            }
            if(j<grid[i].size()&&grid[i][j])
                break;
        }
        if(i<grid.size()&&grid[i][j]){
            q.push({i,j});
            visited[i][j] = true;
        }
        while(q.size()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            int p = 4;
            for(auto& d:direction){
                int x = i+d.first;
                int y = j+d.second;
                if(x>=0&&x<grid.size()&&y>=0&&y<grid[x].size()){
                    if(grid[x][y]){
                        p--;
                        if(!visited[x][y]){
                            visited[x][y] = true;
                            q.push({x,y});
                        }
                    }
                }
            }
            perimeter+=p;
        }
        return perimeter;
    }
};
// @lc code=end

