/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> m;
        for(int i=nums2.size()-1;i>=0;i--) {
            while(st.size()&&st.top()<=nums2[i]) st.pop();
            m[nums2[i]] = st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        vector<int> ret;
        for(auto& num:nums1) 
            ret.push_back(m[num]);
        return ret;
    }
};
// @lc code=end

