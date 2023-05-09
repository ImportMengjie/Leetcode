/*
设想有个机器人坐在一个网格的左上角，网格 r 行 c 列。机器人只能向下或向右移动，但不能走到一些被禁止的网格（有障碍物）。设计一种算法，寻找机器人从左上角移动到右下角的路径。

网格中的障碍物和空位置分别用 1 和 0 来表示。

返回一条可行的路径，路径由经过的网格的行号和列号组成。左上角为 0 行 0 列。如果没有可行的路径，返回空数组。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: [[0,0],[0,1],[0,2],[1,2],[2,2]]
解释: 
输入中标粗的位置即为输出表示的路径，即
0行0列（左上角） -> 0行1列 -> 0行2列 -> 1行2列 -> 2行2列（右下角）
说明：r 和 c 的值均不超过 100。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/robot-in-a-grid-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> res;
        if(obstacleGrid.empty()) return res;
        vector<vector<bool>> dp(obstacleGrid.size(), vector<bool>(obstacleGrid.back().size(), false));
        dp[0][0] = !obstacleGrid[0][0];
        for(int i=1;i<dp.size();i++)
            dp[i][0] = !obstacleGrid[i][0] && dp[i-1][0];
        for(int i=1;i<dp.back().size();i++)
            dp[0][i] = !obstacleGrid[0][i] && dp[0][i-1];
        for(int i=1;i<dp.size();i++)
            for(int j=1;j<dp.back().size();j++)
                dp[i][j] = !obstacleGrid[i][j] && (dp[i-1][j]||dp[i][j-1]);
        if(!dp.back().back()) return res;
        for(int i=dp.size()-1, j = dp.back().size()-1;j>=0&&i>=0;){
            res.push_back({i, j});
            if(i-1>=0&&dp[i-1][j]) i--;
            else j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
