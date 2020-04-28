/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (48.41%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    36.4K
 * Total Submissions: 74.9K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> s;
        int max_streak = 1;
        for(int& n:nums)
            s.insert(n);
        for(int& n:nums){
            if(s.find(n-1)==s.end()){
                int current_num = n;
                int current_streak = 1;
                while(s.find(++current_num)!=s.end())
                    current_streak++;
                max_streak = max(max_streak, current_streak);
            }
        }
        return max_streak;
    }
};
// @lc code=end

