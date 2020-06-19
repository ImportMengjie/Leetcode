/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2;
        vector<int> ret;
        for(auto& num:nums1)
            m1[num]++;
        for(auto& num:nums2)
            m2[num]++;
        for(auto& [num,count]:m2)
            if(m1.count(num))
                for(int i=0;i<min(m1[num],m2[num]);i++)
                    ret.push_back(num);
        return ret;
    }
};
// @lc code=end

