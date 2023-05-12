/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <deque>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<k;i++) {
            while(!dq.empty()&&nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        vector<int> ret{nums[dq.front()]};
        for(int i=k;i<nums.size();i++) {
            while(!dq.empty()&&nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i-dq.front()>=k) dq.pop_front();
            ret.push_back(nums[dq.front()]);
        }
        
        return ret;
    }

    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<k;i++) {
            dq.push_back(nums[i]);
            int j = dq.size()-1;
            while(--j>=0) {
                if(dq[j]<nums[i])
                    dq[j] = nums[i];
            }
        }
        vector<int> ret{dq.front()};
        for(int i=k;i<nums.size();i++) {
            dq.pop_front();
            dq.push_back(nums[i]);
            int j = dq.size()-1;
            while(--j>=0)
                if(dq[j]<nums[i])
                    dq[j] = nums[i];
            ret.push_back(dq.front());
        }
        return ret;
    }
};
// @lc code=end

