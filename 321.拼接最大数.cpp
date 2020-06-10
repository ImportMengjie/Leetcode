/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 *
 * https://leetcode-cn.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (29.70%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 11K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n)
 * 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
 * 
 * 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
 * 
 * 说明: 请尽可能地优化你算法的时间和空间复杂度。
 * 
 * 示例 1:
 * 
 * 输入:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * 输出:
 * [9, 8, 6, 5, 3]
 * 
 * 示例 2:
 * 
 * 输入:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * 输出:
 * [6, 7, 6, 0, 4]
 * 
 * 示例 3:
 * 
 * 输入:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * 输出:
 * [9, 8, 9]
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxKsequence(vector<int> &v, int k){
        if(v.size()<=k) return v;
        int pop = v.size()-k;
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            while (ans.size()&&ans.back()<v[i]&&pop-->0)
                ans.pop_back();
            ans.push_back(v[i]);
        }
        ans.resize(k);
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, 0);
        for(int s = max(0, k-(int)nums2.size());s <= min((int)nums1.size(),k);s++){
            vector<int> temp;
            vector<int> temp1 = maxKsequence(nums1, s);
            vector<int> temp2 = maxKsequence(nums2, k-s);
            auto iter1 = temp1.begin();
            auto iter2 = temp2.begin();
            while (iter1!=temp1.end()||iter2!=temp2.end()) 
                temp.push_back(lexicographical_compare(iter1,temp1.end(),iter2,temp2.end())?*iter2++:*iter1++);
            ans = lexicographical_compare(ans.begin(),ans.end(),temp.begin(),temp.end())?temp:ans;
        }
        return ans;
    }

};
// @lc code=end

