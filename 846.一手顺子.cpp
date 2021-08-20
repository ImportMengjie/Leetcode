/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 *
 * https://leetcode-cn.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (50.65%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 14.8K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * 爱丽丝有一手（hand）由整数数组给定的牌。 
 * 
 * 现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。
 * 
 * 如果她可以完成分组就返回 true，否则返回 false。
 * 
 * 
 * 
 * 注意：此题目与 1296
 * 重复：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
 * 输出：true
 * 解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：hand = [1,2,3,4,5], W = 4
 * 输出：false
 * 解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 1 
 * 
 * 
 */
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W) return false;
        map<int,int> mp;
        for(int& num:hand)
            mp[num]++;
        for(auto iter = mp.begin();iter!=mp.end();iter++){
            if(iter->second>0){
                for(int i=1;i<W;i++){
                    int next = i+iter->first;
                    if(mp.count(next)&&mp[next]>=iter->second)
                        mp[next] -= iter->second;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

