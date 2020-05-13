/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (29.50%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    18.5K
 * Total Submissions: 62.5K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [2,4,1], k = 2
 * 输出: 2
 * 解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,6,5,0,3], k = 2
 * 输出: 7
 * 解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4
 * 。
 * 随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 * 
 * 
 */

#include <vector>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        if(k>prices.size()/2){
            int max_profit = 0;
            for(int i=1;i<prices.size();i++)
                if(prices[i]>prices[i-1])
                    max_profit += prices[i]-prices[i-1];
            return max_profit;
        }
        int dp[prices.size()][k+1][2];

        for(int i=0;i<prices.size();i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = 1<<31;
            if(i)
                for(int kk=k;kk>=1;kk--){
                    dp[i][kk][1] = max(dp[i-1][kk][1],dp[i-1][kk-1][0]==1<<31?0:dp[i-1][kk-1][0]-prices[i]);
                    dp[i][kk][0] = max(dp[i-1][kk][1]+prices[i], dp[i-1][kk][0]);
                }
            else
                for(int kk=0;kk<=k;kk++){
                    dp[i][kk][1] = -prices[i];
                    dp[i][kk][0] = 0;
                }
        }
        return dp[prices.size()-1][k][0];
    }
};
// @lc code=end

