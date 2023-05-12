/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) {
            return p1.second > p2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ret;
        for(auto& num:nums) m[num]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> freqs;
        for(auto& p:m) {
            freqs.push(p);
            if(freqs.size()>k) freqs.pop();
        }
        while(freqs.size()){
            ret.insert(ret.begin(), freqs.top().first);
            freqs.pop();
        }
        return ret;

    }
};
// @lc code=end

