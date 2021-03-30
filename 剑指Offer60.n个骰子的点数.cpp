/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:

输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]

限制：

1 <= n <= 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp(2, vector<int>(n*6, 0));
        int flag = 0;
        for(int i=0;i<6;i++)
            dp[1-flag][i] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++)
                dp[flag][j] = 0;
            for(int sum=i;sum<(i+1)*6;sum++){
                dp[flag][sum] = 0;
                for(int j=1;j<=6&&sum-j>=0;j++)
                    dp[flag][sum] += dp[1-flag][sum-j];
            }
            flag = 1-flag;
        }
        vector<double> ret(n*6-n+1, 0);
        int total = pow(6, n);
        for(int i=n;i<=n*6;i++)
            ret[i-n] = double(dp[1-flag][i-1])/total;
        return ret;
    }
};
