/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 *
 * https://leetcode.cn/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (50.86%)
 * Likes:    722
 * Dislikes: 0
 * Total Accepted:    152.9K
 * Total Submissions: 300.6K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回
 * 需要移除区间的最小数量，使剩余区间互不重叠 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * 输出: 1
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: intervals = [ [1,2], [1,2], [1,2] ]
 * 输出: 2
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: intervals = [ [1,2], [2,3] ]
 * 输出: 0
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int maxRight = intervals[0][1];
        int result = 1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=maxRight){
                result++;
                maxRight = intervals[i][1];
            }
        }
        return intervals.size()-result;

    }
};
// @lc code=end

