/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& n:nums) {
            if(pq.size()<k) pq.push(n);
            else if(pq.top()<n) {
                pq.pop();
                pq.push(n);
            }
        }
        return pq.top();
    }
};
// @lc code=end

