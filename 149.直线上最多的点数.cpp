/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (21.49%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 52.3K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 * 
 * 示例 1:
 * 
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 */
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:

    int get_gcd(int a, int b){
        while(b){
            int t = a%b;
            a = b;
            b = t;
        }
        return a;
    }

    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)
            return points.size();
        int ans = 0;
        for(int i=0; i<points.size();i++){
            unordered_map<string,int> map;
            int max_number = 0;
            int duplicate = 0;
            for(int j=i+1;j<points.size();j++){
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if(!x&&!y){
                    duplicate++;
                    continue;
                }
                int gcd = get_gcd(x,y);
                string key = to_string(x/gcd)+":"+to_string(y/gcd);
                if(map.find(key)==map.end())
                    map[key] = 1;
                else
                    map[key]++;
                max_number = max(map[key], max_number);
            }
            ans = max(ans, max_number + 1 + duplicate);
        }
        return ans;
    }
};
// @lc code=end

