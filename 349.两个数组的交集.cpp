/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set{nums1.begin(),nums1.end()};
        unordered_set<int> tmp;
        for(auto& num:nums2)
            if(set.count(num)) tmp.insert(num);
        return vector<int>(tmp.begin(),tmp.end());
    }
};
// @lc code=end

