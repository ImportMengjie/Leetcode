/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 *
 * https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (41.50%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    49.9K
 * Total Submissions: 120.3K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
 * 
 * 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
 * 
 * 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * 输出: [1,2],[1,4],[1,6]
 * 解释: 返回序列中的前 3 对数：
 * ⁠    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * 输出: [1,1],[1,1]
 * 解释: 返回序列中的前 2 对数：
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: nums1 = [1,2], nums2 = [3], k = 3 
 * 输出: [1,3],[2,3]
 * 解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 10^5
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1 和 nums2 均为升序排列
 * 1 <= k <= 1000
 * 
 * 
 */
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty()||nums2.empty()) return {};
        auto cmp = [&nums1, &nums2](const pair<int,int>& a, const pair<int,int>& b){
            return nums1[a.first]+nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(int i=0;i<min((int)nums1.size(), k); i++)
            pq.emplace(i, 0);

        while(k--&&pq.size()){
            auto [x,y] = pq.top();
            pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if(y+1<nums2.size())
                pq.push({x, y+1});
        }
        return ans;
    }
};
// @lc code=end

