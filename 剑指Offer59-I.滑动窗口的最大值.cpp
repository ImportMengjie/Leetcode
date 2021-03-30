/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        deque<int> dq;
        vector<int> ret(nums.size()-k+1, 0);
        for(int i=0;i<k;i++){
            while(dq.size()&&dq.back()<nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        ret[0] = dq.front();
        for(int i=k;i<nums.size();i++){
            if(dq.size()&&dq.front()==nums[i-k])
                dq.pop_front();
            while(dq.size()&&dq.back()<nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            ret[i-k+1] = dq.front();
        }
        return ret;
    }
};
