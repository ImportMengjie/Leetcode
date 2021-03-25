/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 
提示：

0 < grid.length <= 200
0 < grid[0].length <= 200


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                int left=0, up=0;
                if(col>0) left = dp[row][col-1];
                if(row>0) up = dp[row-1][col];
                dp[row][col] = grid[row][col] + max(left, up);
            }
        }
        return dp.back().back();
    }
};